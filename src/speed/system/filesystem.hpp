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
 * @file        speed/system/filesystem.hpp
 * @brief       filesystem functions header.
 * @author      Killian
 * @date        2017/05/26 - 17:20
 */

#ifndef SPEED_SYSTEM_FILESYSTEM_HPP
#define SPEED_SYSTEM_FILESYSTEM_HPP

#include <cstdint>

#include "../lowlevel.hpp"
#include "data_types.hpp"
#include "error_code.hpp"
#include "glibc/filesystem.hpp"
#include "system_macros.hpp"


namespace speed {
namespace system {


/**
 * @brief       Checks whether the calling process can access the file path. If pathname is a
 *              symbolic link, it is dereferenced.
 * @param       fle_path : The file path.
 * @param       acss_modes : Specifies the accessibility check(s) to be performed.
 * @param       err_code : If function fails it holds the platform-dependent error code.
 * @return      On success the true is returned, otherwise false is returned.
 */
inline bool access(
        const char* fle_path,
        access_modes acss_modes,
        std::error_code* err_code = nullptr
)
{
    return SPEED_SELECT_API(access, false, fle_path, acss_modes, err_code);
}


/**
 * @brief       Checks whether the calling process can access the file path. If pathname is a
 *              symbolic link, it is dereferenced.
 * @param       fle_path : The file path.
 * @param       acss_modes : Specifies the accessibility check(s) to be performed.
 * @param       fle_type : The file type.
 * @param       err_code : If function fails it holds the platform-dependent error code.
 * @return      On success the true is returned, otherwise false is returned.
 */
inline bool access(
        const char* fle_path,
        access_modes acss_modes,
        file_type fle_type,
        std::error_code* err_code = nullptr
)
{
    return SPEED_SELECT_API(access, false, fle_path, acss_modes, fle_type, err_code);
}


/**
 * @brief       Change the current execution directory.
 * @param       dir_path : The path of the new current directory.
 * @param       err_code : If function fails it holds the platform-dependent error code.
 * @return      If function was successful true is returned, otherwise false is returned.
 */
inline bool chdir(const char* dir_path, std::error_code* err_code = nullptr) noexcept
{
    return SPEED_SELECT_API(chdir, false, dir_path, err_code);
}


/**
 * @brief       Get the inode number of the specified file.
 * @param       fle_path : The file to get the inode number.
 * @param       err_code : If function fails it holds the platform-dependent error code.
 * @return      On success the inode number of the sepcified file is returned, otherwise -1 is
 *              returned.
 */
inline uint64_t get_file_inode(const char* fle_path, std::error_code* err_code = nullptr) noexcept
{
    return SPEED_SELECT_API(get_file_inode, -1, fle_path, err_code);
}


/**
 * @brief       Get the UID of the specified file.
 * @param       fle_path : The file to get the UID.
 * @param       err_code : If function fails it holds the platform-dependent error code.
 * @return      On success the UID of the sepcified file is returned, otherwise -1 is returned.
 */
inline int get_file_uid(const char* fle_path, std::error_code* err_code = nullptr) noexcept
{
    return SPEED_SELECT_API(get_file_uid, -1, fle_path, err_code);
}


/**
 * @brief       Get the GID of the specified file.
 * @param       fle_path : The file to get the GID.
 * @param       err_code : If function fails it holds the platform-dependent error code.
 * @return      On success the GID of the sepcified file is returned, otherwise -1 is returned..
 */
inline int get_file_gid(const char* fle_path, std::error_code* err_code = nullptr) noexcept
{
    return SPEED_SELECT_API(get_file_gid, -1, fle_path, err_code);
}


/**
 * @brief       Get the tmp system path.
 * @return      If function was successful the tmp system path is returned otherwise a null pointer
 *              is returned.
 */
inline const char* get_tmp_path() noexcept
{
    return SPEED_SELECT_API(get_tmp_path, nullptr);
}


/**
 * @brief       Checks if the given path corresponds to a block device.
 * @param       fle_path : Path to check.
 * @param       err_code : If function fails it holds the platform-dependent error code.
 * @return      If function was successful true is returned, otherwise false is returned.
 */
inline bool is_block_device(const char* fle_path, std::error_code* err_code = nullptr) noexcept
{
    return SPEED_SELECT_API(is_block_device, false, fle_path, err_code);
}


/**
 * @brief       Checks if the given path corresponds to a character device.
 * @param       fle_path : Path to check.
 * @param       err_code : If function fails it holds the platform-dependent error code.
 * @return      If function was successful true is returned, otherwise false is returned.
 */
inline bool is_character_device(const char* fle_path, std::error_code* err_code = nullptr) noexcept
{
    return SPEED_SELECT_API(is_character_device, false, fle_path, err_code);
}


/**
 * @brief       Checks if the given path corresponds to a directory.
 * @param       fle_path : Path to check.
 * @param       err_code : If function fails it holds the platform-dependent error code.
 * @return      If function was successful true is returned, otherwise false is returned.
 */
inline bool is_directory(const char* fle_path, std::error_code* err_code = nullptr) noexcept
{
    return SPEED_SELECT_API(is_directory, false, fle_path, err_code);
}


/**
 * @brief       Checks if the given path corresponds to a named pipe.
 * @param       fle_path : Path to check.
 * @param       err_code : If function fails it holds the platform-dependent error code.
 * @return      If function was successful true is returned, otherwise false is returned.
 */
inline bool is_fifo(const char* fle_path, std::error_code* err_code = nullptr) noexcept
{
    return SPEED_SELECT_API(is_fifo, false, fle_path, err_code);
}


/**
 * @brief       Checks if the given path corresponds to a regular file.
 * @param       fle_path : Path to check.
 * @param       err_code : If function fails it holds the platform-dependent error code.
 * @return      If function was successful true is returned, otherwise false is returned.
 */
inline bool is_regular_file(const char* fle_path, std::error_code* err_code = nullptr) noexcept
{
    return SPEED_SELECT_API(is_regular_file, false, fle_path, err_code);
}


/**
 * @brief       Checks if the given path corresponds to a socket.
 * @param       fle_path : Path to check.
 * @param       err_code : If function fails it holds the platform-dependent error code.
 * @return      If function was successful true is returned, otherwise false is returned.
 */
inline bool is_socket(const char* fle_path, std::error_code* err_code = nullptr) noexcept
{
    return SPEED_SELECT_API(is_socket, false, fle_path, err_code);
}


/**
 * @brief       Checks if the given path corresponds to a socket.
 * @param       fle_path : Path to check.
 * @param       err_code : If function fails it holds the platform-dependent error code.
 * @return      If function was successful true is returned, otherwise false is returned.
 */
inline bool is_symlink(const char* fle_path, std::error_code* err_code = nullptr) noexcept
{
    return SPEED_SELECT_API(is_symlink, false, fle_path, err_code);
}


// TODO(killian.poulaud@etu.upmc.fr): Maybe the modes should have their own data type.
/**
 * @brief       Attempts to create a directory.
 * @param       dir_path : The path of the new directory.
 * @param       mods : Specifies the mode for the new directory.
 * @param       err_code : If function fails it holds the platform-dependent error code.
 * @return      If function was successful true is returned, otherwise false is returned.
 */
inline bool mkdir(
        const char* dir_path,
        std::uint32_t mods = 0755,
        std::error_code* err_code = nullptr
) noexcept
{
    return SPEED_SELECT_API(mkdir, false, dir_path, mods, err_code);
}


/**
 * @brief       Delete the specified directory.
 * @param       dir_path : The path of the directory to delete.
 * @param       err_code : If function fails it holds the platform-dependent error code.
 * @return      If function was successful true is returned, otherwise false is returned.
 */
inline bool rmdir(const char* dir_path, std::error_code* err_code = nullptr) noexcept
{
    return SPEED_SELECT_API(rmdir, false, dir_path, err_code);
}


/**
 * @brief       Creates a symbolic link named lnk_pth which contains the string trg.
 * @param       trg : The string to contain in the symlink.
 * @param       lnk_pth : The symbolilc link name.
 * @param       err_code : If function fails it holds the platform-dependent error code.
 * @return      If function was successful true is returned, otherwise false is returned.
 */
inline bool symlink(
        const char* trg,
        const char* lnk_pth,
        std::error_code* err_code = nullptr
) noexcept
{
    return SPEED_SELECT_API(symlink, false, trg, lnk_pth, err_code);
}


// TODO(killian.poulaud@etu.upmc.fr): Test this function.
/**
 * @brief       Attempts to create a regular file.
 * @param       regfle_path : The path of the new regular file.
 * @param       mods : Specifies the mode for the new regular file.
 * @param       err_code : If function fails it holds the platform-dependent error code.
 * @return      If function was successful true is returned, otherwise false is returned.
 */
inline bool touch(
        const char* regfle_path,
        std::uint32_t mods = 0755,
        std::error_code* err_code = nullptr
) noexcept
{
    return SPEED_SELECT_API(touch, false, regfle_path, mods, err_code);
}


}
}


#endif
