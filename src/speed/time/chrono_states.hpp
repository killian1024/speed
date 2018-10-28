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
 * @file       speed/time/chrono_states.hpp
 * @brief      chrono_states enum class header.
 * @author     Killian
 * @date       2017/10/28 - 11:58
 */

#ifndef SPEED_TIME_CHRONO_STATES_HPP
#define SPEED_TIME_CHRONO_STATES_HPP

#include <cstdint>


namespace speed {
namespace time {


/**
 * @brief       Enumeration that represents the chronos states.
 */
enum class chrono_states : std::uint8_t
{
    READY,
    RUNNING,
    STOPED
};


/** Enumeration that represents the chronos states. */
using cs_t = chrono_states;


}
}


#endif
