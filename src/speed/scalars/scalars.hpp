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
 * @file        speed/scalars/scalars.hpp
 * @brief       scalars functions header.
 * @author      Killian
 * @date        2018/04/28 - 22:56
 */

#ifndef SPEED_SCALARS_SCALARS_HPP
#define SPEED_SCALARS_SCALARS_HPP


namespace speed {
namespace scalars {


// FIXME(killian.poulaud@etu.upmc.fr): This method doesn't work with negatives numbers.
/**
 * @brief       Get the number of digits of the given scalar.
 * @param       scalr : The scalar to get the number of digits.
 * @return      The number of digits of the given scalar.
 */
template<typename TpScalar>
TpScalar get_n_digits(TpScalar scalr) noexcept
{
    TpScalar cur_n_digits = 1;
    
    while (scalr > 9)
    {
        ++cur_n_digits;
        scalr /= 10;
    }
    
    return cur_n_digits;
}


}
}


#endif
