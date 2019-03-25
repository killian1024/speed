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
 * @file        speed/system/glibc/time.hpp
 * @brief       time functions definitions.
 * @author      Killian
 * @date        2017/10/18 - 22:26
 */

#include "../system_macros.hpp"
#ifdef SPEED_GLIBC

#include <ctime>
#include <sys/times.h>

#include "time.hpp"


namespace speed {
namespace system {
namespace glibc {


bool get_monotonic_time(time_specification* time_spec, std::error_code* err_code) noexcept
{
    struct ::timespec tp;
    int clk;

#if defined(__linux__) && LINUX_VERSION_CODE >= KERNEL_VERSION(2, 6, 39)
    clk = CLOCK_BOOTTIME;
#else
    clock = CLOCK_MONOTONIC;
#endif
    
    if (::clock_gettime(clk, &tp) == -1)
    {
        assign_system_error_code(errno, err_code);
        return false;
    }
    
    time_spec->sec = (std::uint64_t)tp.tv_sec;
    time_spec->nsec = (std::uint64_t)tp.tv_nsec;
    
    return true;
}


bool get_cpu_time(time_specification* time_spec, std::error_code* err_code) noexcept
{
    ::clock_t cpu_tme;
    struct ::tms buf;
    const long cps = ::sysconf(_SC_CLK_TCK);
    
    if (cps == -1)
    {
        assign_system_error_code(errno, err_code);
        return false;
    }
    
    if (::times(&buf) == -1)
    {
        assign_system_error_code(errno, err_code);
        return false;
    }
    cpu_tme = buf.tms_utime + buf.tms_stime;
    
    time_spec->sec = (std::uint64_t)cpu_tme / cps;
    time_spec->nsec = (1'000'000'000 / cps) * ((std::uint64_t)cpu_tme % cps);
    
    return true;
}


bool get_child_cpu_time(time_specification* time_spec, std::error_code* err_code) noexcept
{
    ::clock_t cpu_tme;
    struct ::tms buf;
    const long cps = ::sysconf(_SC_CLK_TCK);
    
    if (cps == -1)
    {
        assign_system_error_code(errno, err_code);
        return false;
    }
    
    if (::times(&buf) == -1)
    {
        assign_system_error_code(errno, err_code);
        return false;
    }
    cpu_tme = buf.tms_cutime + buf.tms_cstime;
    
    time_spec->sec = (std::uint64_t)cpu_tme / cps;
    time_spec->nsec = (1'000'000'000 / cps) * ((std::uint64_t)cpu_tme % cps);
    
    return true;
}


}
}
}


#endif
