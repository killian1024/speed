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
 * @file        speed/system/process.hpp
 * @brief       process functions header.
 * @author      Killian
 * @date        2017/01/08 - 16:37
 */

#ifndef SPEED_SYSTEM_PROCESS_HPP
#define SPEED_SYSTEM_PROCESS_HPP

#include "data_types.hpp"
#include "error_code.hpp"
#include "glibc/process.hpp"
#include "system_macros.hpp"
#include "time.hpp"


namespace speed {
namespace system {


/**
 * @brief       Execute the specified command.
 * @param       cmd : The command to execute.
 * @param       ret_val : The return value of the command.
 * @param       err_code : If function fails it holds the platform-dependent error code.
 * @return      If function was successful true is returned, otherwise false is returned.
 */
inline bool execute_command(
        const char* cmd,
        int* ret_val = nullptr,
        std::error_code* err_code = nullptr
) noexcept
{
    return SPEED_SELECT_API(execute_command, false, cmd, ret_val, err_code);
}


/**
 * @brief       Get the PID of the current process.
 * @return      The PID of the current process.
 */
inline int get_pid() noexcept
{
    return SPEED_SELECT_API(get_pid, -1);
}


/**
 * @brief       Get the PPID of the current process.
 * @return      The PPID of the current process.
 */
inline int get_ppid() noexcept
{
    return SPEED_SELECT_API(get_ppid, -1);
}


/**
 * @brief       Get the UID of the current process.
 * @return      The UID of the current process.
 */
inline unsigned int get_uid() noexcept
{
    return SPEED_SELECT_API(get_uid, -1);
}


/**
 * @brief       Get the GID of the current process.
 * @return      The GID of the current process.
 */
inline unsigned int get_gid() noexcept
{
    return SPEED_SELECT_API(get_gid, -1);
}


/**
 * @brief       Suspends  the  execution  of the calling thread until either at least the time
 *              specified has elapsed, or the delivery of a signal that triggers the invocation of a
 *              handler in the calling thread or that terminates the process.
 * @param       sec : The number of seconds.
 * @param       nsec : The number of nano seconds.
 * @param       rem_time : The remaining time if the function was interrupted.
 * @param       err_code : If function fails it holds the platform-dependent error code.
 * @return      If function was successful true is returned, otherwise false is returned.
 */
inline bool nanosleep(
        std::uint64_t sec,
        std::uint64_t nsec,
        time_specification* rem_time = nullptr,
        std::error_code* err_code = nullptr
) noexcept
{
    return SPEED_SELECT_API(nanosleep, false, sec, nsec, rem_time, err_code);
}


/**
 * @brief       Suspends  the  execution  of the calling thread until either at least the time
 *              specified has elapsed, or the delivery of a signal that triggers the invocation of a
 *              handler in the calling thread or that terminates the process.
 * @param       time_spec : The time to suspend the execution.
 * @param       rem_time : The remaining time if the function was interrupted.
 * @param       err_code : If function fails it holds the platform-dependent error code.
 * @return      If function was successful true is returned, otherwise false is returned.
 */
inline bool nanosleep(
        const time_specification& time_spec,
        time_specification* rem_time = nullptr,
        std::error_code* err_code = nullptr
) noexcept
{
    return nanosleep(time_spec.sec, time_spec.nsec, rem_time, err_code);
}


}
}


#endif
