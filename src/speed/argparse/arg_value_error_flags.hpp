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
 * @file        speed/argparse/arg_value_error_flags.hpp
 * @brief       arg_value_error_flags enum class header.
 * @author      Killian
 * @date        2016/08/06 - 13:59
 */

#ifndef SPEED_ARGPARSE_ARG_VALUE_ERROR_FLAGS_HPP
#define SPEED_ARGPARSE_ARG_VALUE_ERROR_FLAGS_HPP

#include "../lowlevel.hpp"


namespace speed {
namespace argparse {


/**
 * @brief       Contains all argument value error flags constants.
 */
enum class arg_value_error_flags : std::uint8_t
{
    /** Null flag. */
    NIL = 0x0,
    
    /** The value specified is not correct. */
    WRONG_VALUE_ERROR = 0x1,
    
    /** The argument value has not matched the regex. */
    REGEX_TO_MATCH_ERROR = 0x2,
    
    /** All the argument value error flags. */
    ALL = 0x3
};


/** Contains all argument value error flags constants. Alias of 'arg_value_error_flags'
 *  enumeration. */
using avef_t = arg_value_error_flags;


}
}


/** @cond */
namespace speed {
namespace lowlevel {
template<>
struct enum_bitwise_operators<speed::argparse::arg_value_error_flags>
{
    static constexpr bool enable = true;
};
}
}
/** @endcond */


#endif
