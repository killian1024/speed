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
 * @file       speed/containers/i_iterator.hpp
 * @brief      i_iterator interface header.
 * @author     Killian
 * @date       2018/01/19 - 22:17
 */

#ifndef SPEED_CONTAINERS_I_ITERATOR_HPP
#define SPEED_CONTAINERS_I_ITERATOR_HPP

#include <cstddef>


namespace speed {
namespace containers {


/**
 * @brief       Class that represents the interface of the iterators base.
 */
template<typename TpValue, typename TpIterator>
class i_iterator
{
public:
    /** The value encapsulated by the iterator. */
    using value_type = TpValue;
    
    /** The iterator derived type. */
    using iterator_type = TpIterator;
    
    /** The class itself. */
    using self_type = i_iterator<value_type, iterator_type>;
    
    /**
     * @brief       Default destructor.
     */
    virtual ~i_iterator() = default;
    
    /**
     * @brief       Move to the forward node.
     * @return      A reference to an iterator pointing the current node.
     */
    virtual iterator_type& operator ++() = 0;
    
    /**
     * @brief       Move to the backward node.
     * @return      A reference to an iterator pointing the current node.
     */
    virtual iterator_type& operator --() = 0;
    
    /**
     * @brief       Allows knowing whether the two iterators are the same.
     * @param       rhs : The value to compare.
     * @return      If function was successful true is returned, otherwise false is returned.
     */
    virtual bool operator ==(const iterator_type& rhs) const noexcept = 0;
    
    /**
     * @brief       Allows knowing whether the iterator is past-the-end or not.
     * @return      If function was successful true is returned, otherwise false is returned.
     */
    virtual bool end() const noexcept = 0;
    
    /**
     * @brief       Move to the forward node.
     * @return      A reference to the the iterator pointing the node before the operation.
     */
    virtual const iterator_type operator ++(int)
    {
        iterator_type old_it(dynamic_cast<iterator_type&>(*this));
    
        operator ++();
        
        return old_it;
    }
    
    /**
     * @brief       Move to the backward node.
     * @return      A reference to the iterator pointing the node before the operation.
     */
    virtual const iterator_type operator --(int)
    {
        iterator_type old_it(dynamic_cast<iterator_type&>(*this));
    
        operator --();
        
        return old_it;
    }
    
    /**
     * @brief       Move to the forward node n times.
     * @param       n : The number of times to move.
     * @return      A reference to a iterator pointing the resulting node.
     */
    virtual const iterator_type operator +(std::size_t n) const
    {
        iterator_type old_it(dynamic_cast<const iterator_type&>(*this));
        
        for (std::size_t i = 0; i < n; i++)
        {
            ++old_it;
        }
        
        return old_it;
    }
    
    /**
     * @brief       Move to the backward node n times.
     * @param       n : The number of times to move.
     * @return      A reference to a iterator pointing the resulting node.
     */
    virtual const iterator_type operator -(std::size_t n) const
    {
        iterator_type old_it(dynamic_cast<const iterator_type&>(*this));
        
        for (std::size_t i = 0; i < n; i++)
        {
            --old_it;
        }
        
        return old_it;
    }
    
    /**
     * @brief       Move to the forward node n times.
     * @param       n : The number of times to move.
     * @return      A reference to a iterator pointing the current node.
     */
    virtual iterator_type& operator +=(std::size_t n)
    {
        for (std::size_t i = 0; i < n; i++)
        {
            operator ++();
        }
    
        return dynamic_cast<iterator_type&>(*this);
    }
    
    /**
     * @brief       Move to the backward node n times.
     * @param       n : The number of times to move.
     * @return      A reference to a iterator pointing the current node.
     */
    virtual iterator_type& operator -=(std::size_t n)
    {
        for (std::size_t i = 0; i < n; i++)
        {
            operator --();
        }
    
        return dynamic_cast<iterator_type&>(*this);
    }
    
    /**
     * @brief       Allows knowing whether two iterators are inequal.
     * @param       rhs : The iterator to compare.
     * @return      If function was successful true is returned, otherwise false is returned.
     */
    virtual bool operator !=(const iterator_type& rhs) const noexcept
    {
        return !(*this == rhs);
    }
    
    /**
     * @brief       Allows knowing whether a specified iterator is lower than the current.
     * @param       rhs : The iterator to compare.
     * @return      If function was successful true is returned, otherwise false is returned.
     */
    virtual bool operator <(const iterator_type& rhs) const noexcept
    {
        iterator_type it(dynamic_cast<const iterator_type&>(*this));
        
        while (!it.end())
        {
            ++it;
        
            if (it == rhs)
            {
                return true;
            }
        }
    
        return false;
    }
    
    /**
     * @brief       Allows knowing whether a specified iterator is greater than the current.
     * @param       rhs : The iterator to compare.
     * @return      If function was successful true is returned, otherwise false is returned.
     */
    virtual bool operator >(const iterator_type& rhs) const noexcept
    {
        iterator_type it(dynamic_cast<const iterator_type&>(*this));
    
        while (!it.end())
        {
            --it;
        
            if (it == rhs)
            {
                return true;
            }
        }
    
        return false;
    }
    
    /**
     * @brief       Allows knowing whether a specified iterator is lower or equal than the current.
     * @param       rhs : The iterator to compare.
     * @return      If function was successful true is returned, otherwise false is returned.
     */
    virtual bool operator <=(const iterator_type& rhs) const noexcept
    {
        if (*this == rhs)
        {
            return true;
        }
    
        return *this < rhs;
    }
    
    /**
     * @brief       Allows knowing whether a specified iterator is greater or equal than the
     *              current.
     * @param       rhs : The iterator to compare.
     * @return      If function was successful true is returned, otherwise false is returned.
     */
    virtual bool operator >=(const iterator_type& rhs) const noexcept
    {
        if (*this == rhs)
        {
            return true;
        }
    
        return *this > rhs;
    }
};


}
}


#endif
