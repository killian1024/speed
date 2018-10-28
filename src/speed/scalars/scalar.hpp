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
 * @file        speed/scalars/scalar.hpp
 * @brief       scalar class header.
 * @author      Killian
 * @date        2018/01/10 - 20:35
 */

#ifndef SPEED_SCALARS_SCALAR_HPP
#define SPEED_SCALARS_SCALAR_HPP

#include <type_traits>


namespace speed {
namespace scalars {


/**
 * @brief       Class that represents a scalar type encapsulation.
 */
template<
        typename TpScalar,
        typename = std::enable_if_t<std::is_scalar<TpScalar>::value>
>
class scalar
{
public:
    /**
     * @brief       Default constructor.
     */
    scalar() = default;

    /**
     * @brief       Constructor with parameters.
     * @param       value : Value for the scalar type.
     */
    scalar(TpScalar value)
            : value_(value)
    {
    }
    
    /**
     * @brief       Copy constructor.
     * @param       rhs : Object to copy.
     */
    scalar(const scalar& rhs)
            : value_(rhs.value_)
    {
    }
    
    /**
     * @brief       Move constructor.
     * @param       rhs : Object to move.
     */
    template<
            typename TpScalar_ = TpScalar,
            typename = std::enable_if_t<!std::is_const<TpScalar_>::value>
    >
    scalar(scalar&& rhs) noexcept
            : value_(rhs.value_)
    {
        rhs.value_ = static_cast<TpScalar>(0);
    }
    
    /**
     * @brief       Destructor.
     */
    virtual ~scalar() = default;
    
    /**
     * @brief       Copy assignment operator.
     * @param       rhs : The object to copy.
     * @return      The object who call the method.
     */
    template<
            typename TpScalar_ = TpScalar,
            typename = std::enable_if_t<!std::is_const<TpScalar_>::value>
    >
    scalar& operator =(const scalar& rhs)
    {
        if (&value_ != &rhs)
        {
            value_ = rhs.value_;
        }
        
        return *this;
    }
    
    /**
     * @brief       Move assignement operator.
     * @param       rhs : The object to move.
     * @return      The object who call the method.
     */
    template<
            typename TpScalar_ = TpScalar,
            typename = std::enable_if_t<!std::is_const<TpScalar_>::value>
    >
    scalar& operator =(scalar&& rhs) noexcept
    {
        if (&value_ != &rhs)
        {
            TpScalar aux = value_;
            value_ = rhs.value_;
            rhs.value_ = aux;
        }
        
        return *this;
    }
    
    /**
     * @brief       Allows access to the underlying value.
     * @return      A reference to the underlying value.
     */
    TpScalar& value() noexcept
    {
        return value_;
    }
    
    /**
     * @brief       Implicit conversion to the underlying type.
     * @return      A reference to the underlying value.
     */
    operator TpScalar&() noexcept
    {
        return value_;
    }
    
    /**
     * @brief       Overloading of the reference operator.
     * @return      A pointer to the underlying scalar value.
     */
    TpScalar* operator &() noexcept
    {
        return &value_;
    }
    
    /**
     * @brief       Overloading of the indirection operator.
     * @return      A reference to the value pointed by the scalar value.
     */
    template<
            typename TpScalar_ = TpScalar,
            typename = std::enable_if_t<std::is_pointer<TpScalar_>::value>
    >
    std::remove_pointer_t<TpScalar>& operator *() noexcept
    {
        return *value_;
    }
    
    /**
     * @brief       Overloading of the indirection operator.
     * @return      A reference to the value pointed by the scalar value.
     */
    template<
            typename TpScalar_ = TpScalar,
            typename = std::enable_if_t<std::is_pointer<TpScalar_>::value>
    >
    TpScalar operator ->() noexcept
    {
        return value_;
    }

private:
    /** The underlying value. */
    TpScalar value_;
};


}
}


#endif
