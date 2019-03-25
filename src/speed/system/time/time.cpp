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
 * @brief       time functions definitions.
 * @author      Killian
 * @date        2017/10/18 - 22:26
 */
 
#include "time.hpp"


namespace speed {
namespace system {


time_specification get_elapsed_time(
        const time_specification& first_time_spec,
        const time_specification& last_time_spec
) noexcept
{
    time_specification elapsed_time_spec;
    
    if (last_time_spec.sec < first_time_spec.sec ||
        (last_time_spec.sec == first_time_spec.sec &&
         last_time_spec.nsec < first_time_spec.nsec))
    {
        elapsed_time_spec.sec = 0;
        elapsed_time_spec.nsec = 0;
        return elapsed_time_spec;
    }
    
    elapsed_time_spec.sec = last_time_spec.sec - first_time_spec.sec;
    elapsed_time_spec.nsec = last_time_spec.nsec - first_time_spec.nsec;
    
    if (last_time_spec.nsec < first_time_spec.nsec)
    {
        elapsed_time_spec.sec -= 1;
        elapsed_time_spec.nsec += 1000000000L;
    }
    
    return elapsed_time_spec;
}


}
}

