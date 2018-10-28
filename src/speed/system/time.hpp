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
 * @file        speed/system/time.hpp
 * @brief       time functions header.
 * @author      Killian
 * @date        2017/10/18 - 22:26
 */

#ifndef SPEED_SYSTEM_TIME_HPP
#define SPEED_SYSTEM_TIME_HPP

#include <cstdint>

#include "data_types.hpp"
#include "error_code.hpp"
#include "glibc/time.hpp"
#include "system_macros.hpp"


namespace speed {
namespace system {


/**
 * @brief       Get the elapsed time between the two time specifications.
 * @param       first_time_spec : First time specification.
 * @param       last_time_spec : Last time specification.
 * @return      The time specification that holds the result of the operation.
 */
time_specification get_elapsed_time(
        const time_specification& first_time_spec,
        const time_specification& last_time_spec
) noexcept;


/**
 * @brief       Get a monotonic time since some unspecified starting point.
 * @param       time_spec : The value in which store the result.
 * @param       err_code : If function fails it holds the platform-dependent error code.
 * @return      If function was successful true is returned, otherwise false is returned.
 */
inline bool get_monotonic_time(
        time_specification* time_spec,
        std::error_code* err_code = nullptr
) noexcept
{
    return SPEED_SELECT_API(get_monotonic_time, false, time_spec, err_code);
}


/**
 * @brief       Get a cpu time since some unspecified starting point.
 * @param       time_spec : The value in which store the result.
 * @param       err_code : If function fails it holds the platform-dependent error code.
 * @return      If function was successful true is returned, otherwise false is returned.
 */
inline bool get_cpu_time(
        time_specification* time_spec,
        std::error_code* err_code = nullptr
) noexcept
{
    return SPEED_SELECT_API(get_cpu_time, false, time_spec, err_code);
}


/**
 * @brief       Get a child cpu time since some unspecified starting point.
 * @param       time_spec : The value in which store the result.
 * @param       err_code : If function fails it holds the platform-dependent error code.
 * @return      If function was successful true is returned, otherwise false is returned.
 */
inline bool get_child_cpu_time(
        time_specification* time_spec,
        std::error_code* err_code = nullptr
) noexcept
{
    return SPEED_SELECT_API(get_child_cpu_time, false, time_spec, err_code);
}


}
}


#endif
