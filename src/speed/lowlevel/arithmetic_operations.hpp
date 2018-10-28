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
 * @file        speed/lowlevel/arithmetic_operations.hpp
 * @brief       arithmetic_operations functions header.
 * @author      Killian
 * @date        2017/01/28 - 23:50
 */

#ifndef SPEED_LOWLEVEL_ARITHMETIC_OPERATIONS_HPP
#define SPEED_LOWLEVEL_ARITHMETIC_OPERATIONS_HPP

#include <limits>
#include <stdexcept>

#include "lowlevel_exception.hpp"


namespace speed {
namespace lowlevel {


// TODO(killian.poulaud@etu.upmc.fr): Add support for signed integrals.
/**
 * @brief       Fonction that allows to do an addition with overflow detection.
 * @param       trg : Integral to increment.
 * @param       val : Value to add to the integral.
 * @throw       speed::lowlevel::overflow_exception : If the addition will produce an overflow an
 *              exception is thrown.
 */
template<typename TpTarget, typename TpValue>
inline TpTarget add(
        TpTarget trg,
        const TpValue& val
)
{
    constexpr TpTarget max_trg = std::numeric_limits<TpTarget>::max();
    
    if (trg > max_trg - static_cast<TpTarget>(val))
    {
        throw overflow_exception();
    }
    
    return trg + static_cast<TpTarget>(val);
}


/**
 * @brief       Fonction that allows to do an addition with overflow detection.
 * @param       trg : Integral to increment.
 * @param       vals : Values to add to the integral.
 * @throw       speed::lowlevel::overflow_exception : If the addition will produce an overflow an
 *              exception is thrown.
 */
template<typename TpTarget, typename... TpValues>
inline TpTarget addl(
        TpTarget trg,
        const TpValues&... vals
)
{
    constexpr TpTarget max_trg = std::numeric_limits<TpTarget>::max();
    
    int dummy[sizeof...(TpValues)] = { (
        (trg > max_trg - static_cast<TpTarget>(vals)) ?
                throw overflow_exception() :
                trg += static_cast<TpTarget>(vals), 0
    )... };
    
    return trg;
}


/**
 * @brief       Fonction that allows to do an addition with overflow detection.
 * @param       trg : Integral to increment.
 * @param       val : Value to add to the integral.
 * @return      If the function was successful true is returned, otherwise false is returned.
 */
template<typename TpTarget, typename TpValue>
inline bool try_add(
        TpTarget* trg,
        const TpValue& val
) noexcept
{
    constexpr TpTarget max_trg = std::numeric_limits<TpTarget>::max();
    bool scs = true;
    
    if (*trg > max_trg - static_cast<TpTarget>(val))
    {
        scs = false;
    }
    
    *trg += static_cast<TpTarget>(val);
    
    return scs;
}


/**
 * @brief       Fonction that allows to do an addition with overflow detection.
 * @param       trg : Integral to increment.
 * @param       vals : Values to add to the integral.
 * @return      If the function was successful true is returned, otherwise false is returned.
 */
template<typename TpTarget, typename... TpValues>
inline bool try_addl(
        TpTarget* trg,
        const TpValues& ... vals
) noexcept
{
    constexpr TpTarget max_trg = std::numeric_limits<TpTarget>::max();
    bool scs = true;
    
    int dummy[sizeof...(TpValues)] = { (
        ((*trg > max_trg - static_cast<TpTarget>(vals)) ?
                scs = false : 0),
        *trg += static_cast<TpTarget>(vals), 0
    )... };
    
    return scs;
}


/**
 * @brief       Fonction that allows to do an addition with overflow detection and in the overflow
 *              case the maximum value of the type will be set to target.
 * @param       trg : Integral to increment.
 * @param       val : Values to add to the integral.
 */
template<typename TpTarget, typename TpValue>
inline TpTarget addm(
        TpTarget trg,
        const TpValue& val
)
{
    constexpr TpTarget max_trg = std::numeric_limits<TpTarget>::max();
    
    if (trg > max_trg - static_cast<TpTarget>(val))
    {
        trg = max_trg;
    }
    else
    {
        trg += static_cast<TpTarget>(val);
    }
    
    return trg;
}


/**
 * @brief       Fonction that allows to do an addition with overflow detection and in the overflow
 *              case the maximum value of the type will be set to target.
 * @param       trg : Integral to increment.
 * @param       vals : Values to add to the integral.
 */
template<typename TpTarget, typename... TpValues>
inline TpTarget addml(
        TpTarget trg,
        const TpValues&... vals
)
{
    constexpr TpTarget max_trg = std::numeric_limits<TpTarget>::max();
    
    int dummy[sizeof...(TpValues)] = { (
        (trg > max_trg - static_cast<TpTarget>(vals)) ?
                trg = max_trg :
                trg += static_cast<TpTarget>(vals), 0
    )... };
    
    return trg;
}


/**
 * @brief       Fonction that allows to do an addition with overflow detection and in the overflow
 *              case the maximum value of the type will be set to target.
 * @param       trg : Integral to increment.
 * @param       val : Values to add to the integral.
 * @return      If the function was successful true is returned, otherwise false is returned.
 */
template<typename TpTarget, typename TpValue>
inline bool try_addm(
        TpTarget* trg,
        const TpValue& val
) noexcept
{
    constexpr TpTarget max_trg = std::numeric_limits<TpTarget>::max();
    bool scs = true;
    
    if (*trg > max_trg - static_cast<TpTarget>(val))
    {
        *trg = max_trg;
        scs = false;
    }
    else
    {
        *trg += static_cast<TpTarget>(val);
    }
    
    return scs;
}


/**
 * @brief       Fonction that allows to do an addition with overflow detection and in the overflow
 *              case the maximum value of the type will be set to target.
 * @param       trg : Integral to increment.
 * @param       vals : Values to add to the integral.
 * @return      If the function was successful true is returned, otherwise false is returned.
 */
template<typename TpTarget, typename... TpValues>
inline bool try_addml(
        TpTarget* trg,
        const TpValues& ... vals
) noexcept
{
    constexpr TpTarget max_trg = std::numeric_limits<TpTarget>::max();
    bool scs = true;
    
    int dummy[sizeof...(TpValues)] = { (
        (*trg > max_trg - static_cast<TpTarget>(vals)) ?
                *trg = max_trg, scs = false :
                *trg += static_cast<TpTarget>(vals), 0
    )... };
    
    return scs;
}
    
    
}
}


#endif
