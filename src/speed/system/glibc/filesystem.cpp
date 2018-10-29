/* speed - Generic C++ library.
 * Copyright (C) 2015-2018 Killian Poulaud.
 *
 * This file is part of speed.
 *
 * speed is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * speed is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with speed. If not, see <http://www.gnu.org/licenses/>.
 */

/**
 * @file        speed/system/glibc/filesystem.cpp
 * @brief       filesystem functions source.
 * @author      Killian
 * @date        2017/05/26 - 17:20
 */

#include "../system_macros.hpp"
#ifdef SPEED_GLIBC

#include <sys/stat.h>
#include <limits.h>
#include <stdlib.h>

#include "../../stringutils.hpp"
#include "filesystem.hpp"


namespace speed {
namespace system {
namespace glibc {


bool access(
        const char* fle_path,
        access_modes acss_modes,
        std::error_code* err_code
) noexcept
{
    decltype(F_OK) mode_buildr = 0;
    bool check = false;
    
    if ((acss_modes & access_modes::EXISTS) != access_modes::NIL)
    {
        check = true;
        mode_buildr |= F_OK;
    }
    if ((acss_modes & access_modes::READ) != access_modes::NIL)
    {
        check = true;
        mode_buildr |= R_OK;
    }
    if ((acss_modes & access_modes::WRITE) != access_modes::NIL)
    {
        check = true;
        mode_buildr |= W_OK;
    }
    if ((acss_modes & access_modes::EXECUTE) != access_modes::NIL)
    {
        check = true;
        mode_buildr |= X_OK;
    }
    
    if (check && ::access(fle_path, mode_buildr) == -1)
    {
        assign_system_error_code(errno, err_code);
        return false;
    }
    
    if ((acss_modes & access_modes::CREATE) != access_modes::NIL)
    {
        if (glibc::access(fle_path, access_modes::EXISTS))
        {
            return false;
        }
        
        char rel_pth[PATH_MAX] = {0};
        std::size_t rel_pth_len;
        
        if (::realpath(fle_path, rel_pth) == nullptr)
        {
            return false;
        }
        rel_pth_len = stringutils::strlen(rel_pth);
        
        if (rel_pth[rel_pth_len - 1] == '/')
        {
            rel_pth[rel_pth_len - 1] = 0;
            --rel_pth_len;
        }
        if (rel_pth_len == 0)
        {
            assign_system_error_code(EPERM, err_code);
            return false;
        }
        
        stringutils::strcut(rel_pth, '/');
        
        if (!glibc::access(rel_pth, access_modes::WRITE | access_modes::EXECUTE, err_code))
        {
            return false;
        }
    }
    
    return true;
}


bool access(
        const char* fle_path,
        access_modes acss_modes,
        file_type fle_type,
        std::error_code* err_code
) noexcept
{
    bool scs;
    
    switch (fle_type)
    {
        case file_type::NIL:
            scs = true;
            break;
        
        case file_type::BLOCK_DEVICE:
            scs = is_block_device(fle_path, err_code);
            break;
    
        case file_type::CHARACTER_DEVICE:
            scs = is_character_device(fle_path, err_code);
            break;
    
        case file_type::DIRECTORY:
            scs = is_directory(fle_path, err_code);
            break;
    
        case file_type::FIFO:
            scs = is_fifo(fle_path, err_code);
            break;
    
        case file_type::REGULAR_FILE:
            scs = is_regular_file(fle_path, err_code);
            break;
    
        case file_type::SOCKET:
            scs = is_socket(fle_path, err_code);
            break;
    
        case file_type::SYMLINK:
            scs = is_symlink(fle_path, err_code);
            break;
    
        default:
            scs = false;
    }
    
    if (!scs)
    {
        assign_system_error_code(EINVAL, err_code);
        return false;
    }
    
    return glibc::access(fle_path, acss_modes, err_code);
}


bool chdir(const char* dir_path, std::error_code* err_code) noexcept
{
    if (::chdir(dir_path) == -1)
    {
        assign_system_error_code(errno, err_code);
        return false;
    }
    
    return true;
}


uint64_t get_file_inode(const char* fle_path, std::error_code* err_code) noexcept
{
    struct ::stat stt;
    
    if (::lstat(fle_path, &stt) == -1)
    {
        assign_system_error_code(errno, err_code);
        return ~0ul;
    }
    
    return stt.st_ino;
}


int get_file_uid(const char* fle_path, std::error_code* err_code) noexcept
{
    struct ::stat stt;
    
    if (::stat(fle_path, &stt) == -1)
    {
        assign_system_error_code(errno, err_code);
        return -1;
    }
    
    return stt.st_uid;
}


int get_file_gid(const char* fle_path, std::error_code* err_code) noexcept
{
    struct ::stat stt;
    
    if (::stat(fle_path, &stt) == -1)
    {
        assign_system_error_code(errno, err_code);
        return -1;
    }
    
    return stt.st_gid;
}


const char* get_tmp_path() noexcept
{
    return "/tmp";
}


bool is_block_device(const char* fle_path, std::error_code* err_code) noexcept
{
    struct ::stat infos;
    
    if (::stat(fle_path, &infos) == -1)
    {
        assign_system_error_code(errno, err_code);
        return false;
    }
    
    return S_ISBLK(infos.st_mode);
}


bool is_character_device(const char* fle_path, std::error_code* err_code) noexcept
{
    struct ::stat infos;
    
    if (::stat(fle_path, &infos) == -1)
    {
        assign_system_error_code(errno, err_code);
        return false;
    }
    
    return S_ISCHR(infos.st_mode);
}


bool is_directory(const char* fle_path, std::error_code* err_code) noexcept
{
    struct ::stat infos;
    
    if (::stat(fle_path, &infos) == -1)
    {
        assign_system_error_code(errno, err_code);
        return false;
    }
    
    return S_ISDIR(infos.st_mode);
}


bool is_fifo(const char* fle_path, std::error_code* err_code) noexcept
{
    struct ::stat infos;
    
    if (::stat(fle_path, &infos) == -1)
    {
        assign_system_error_code(errno, err_code);
        return false;
    }
    
    return S_ISFIFO(infos.st_mode);
}


bool is_regular_file(const char* fle_path, std::error_code* err_code) noexcept
{
    struct ::stat infos;
    
    if (::stat(fle_path, &infos) == -1)
    {
        assign_system_error_code(errno, err_code);
        return false;
    }
    
    return S_ISREG(infos.st_mode);
}


bool is_socket(const char* fle_path, std::error_code* err_code) noexcept
{
    struct ::stat infos;
    
    if (::stat(fle_path, &infos) == -1)
    {
        assign_system_error_code(errno, err_code);
        return false;
    }
    
    return S_ISSOCK(infos.st_mode);
}


bool is_symlink(const char* fle_path, std::error_code* err_code) noexcept
{
    struct ::stat infos;
    
    if (::lstat(fle_path, &infos) == -1)
    {
        assign_system_error_code(errno, err_code);
        return false;
    }
    
    return S_ISLNK(infos.st_mode);
}


bool mkdir(const char* dir_path, std::uint32_t mods, std::error_code* err_code) noexcept
{
    if (::mkdir(dir_path, mods) == -1)
    {
        assign_system_error_code(errno, err_code);
        return false;
    }
    
    return true;
}


bool rmdir(const char* dir_path, std::error_code* err_code) noexcept
{
    if (::rmdir(dir_path) == -1)
    {
        assign_system_error_code(errno, err_code);
        return false;
    }
    
    return true;
}


bool symlink(const char* trg, const char* lnk_pth, std::error_code* err_code) noexcept
{
    if (::symlink(trg, lnk_pth) == -1)
    {
        assign_system_error_code(errno, err_code);
        return false;
    }
    
    return true;
}


bool touch(const char* regfle_path, std::uint32_t mods, std::error_code* err_code) noexcept
{
    if (::mknod(regfle_path, mods, S_IFREG) == -1)
    {
        assign_system_error_code(errno, err_code);
        return false;
    }
    
    return true;
}


}
}
}


#endif
