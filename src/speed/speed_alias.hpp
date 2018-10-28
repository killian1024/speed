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
 * @file        speed/speed_alias.hpp
 * @brief       File that include the librarie namespace alias.
 * @author      Killian
 * @date        2018/10/09 - 21:46
 */

#ifndef SPEED_SPEED_ALIAS_HPP
#define SPEED_SPEED_ALIAS_HPP


namespace speed {


namespace algorithm {}
namespace argparse {}
namespace containers {}
namespace exception {}
namespace iostream {}
namespace lowlevel {}
namespace math {}
namespace scalars {}
namespace stringutils {}
namespace system {}
namespace time {}
namespace type_casting {}
namespace type_traits {}


/**
 * @brief       Contians a set of algorithms.
 */
namespace algo = algorithm;


/**
 * @brief       Contians all argument parser resources.
 */
namespace ap = argparse;


/**
 * @brief       Contians definitions of containers.
 */
namespace contain = containers;


/**
 * @brief       Contains resources for all exceptions thrown by the elements of speed along with
 *              several types and utilities to assist handling exceptions.
 */
namespace except = exception;


/**
 * @brief       Contains resources for input and output streams.
 */
namespace ios = iostream;


/**
 * @brief       Constains lowlevel resources.
 */
namespace low = lowlevel;


/**
 * @brief       Contains a set of resources to compute common mathematical operations and
 *              transformations.
 */
namespace mth = math;


/**
 * @brief       Contains a set of resources to compute common scalars operations.
 */
namespace scals = scalars;


/**
 * @brief       Contains resources for common strings operations.
 */
namespace str = stringutils;


/**
 * @brief       Contains resources for interact with the system.
 */
namespace sys = system;


/**
 * @brief       Contains resources and facilities related to time manipulation.
 */
namespace tm = time;


/**
 * @brief       Contains utilities for type casting.
 */
namespace cast = type_casting;


/**
 * @brief       Contains utilities for compile-time introspection and modification, including type
 *              classification traits, type property inspection traits and type transformation
 *              traits.
 */
namespace traits = type_traits;


}


/**
 * @brief       Contians all speed librarie.
 */
namespace spd = speed;


#endif
