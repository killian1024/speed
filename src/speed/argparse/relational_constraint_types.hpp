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
 * @file        speed/argparse/relational_constraint_types.hpp
 * @brief       relational_constraint_types enum header.
 * @author      Killian
 * @date        2017/10/21 - 01:21
 */

#ifndef SPEED_ARGPARSE_RELATIONAL_CONSTRAINT_TYPES_HPP
#define SPEED_ARGPARSE_RELATIONAL_CONSTRAINT_TYPES_HPP

#include "../lowlevel.hpp"


namespace speed {
namespace argparse {


/**
 * @brief       Contains all arguments relational constraints types.
 */
enum class relational_constraint_types : std::uint8_t
{
    /** Null flag. */
    NIL = 0x0,
    
    /** At least one of the arguments have to be found during the parsing in the argv container. */
    AT_LEAST_ONE_FOUND = 0x1,
    
    /** All flags. */
    ALL = 0x1,
};


/** Contains all arguments relational constraints types. Alias of 'args_relational_constraints'
 * enumeration. */
using rct_t = relational_constraint_types;


}
}


/** @cond */
namespace speed {
namespace lowlevel {
template<>
struct enum_bitwise_operators<speed::argparse::relational_constraint_types>
{
    static constexpr bool enable = true;
};
}
}
/** @endcond */


#endif
