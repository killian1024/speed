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
 * @file        speed/system/data_types.hpp
 * @brief       data_types header.
 * @author      Killian
 * @date        2018/05/31 - 22:31
 */

#ifndef SPEED_SYSTEM_DATA_TYPES_HPP
#define SPEED_SYSTEM_DATA_TYPES_HPP

#include <cstdint>
#include <utility>

#include "filesystem/types.hpp"


namespace speed {
namespace system {

using namespace filesystem;


/**
 * @brief       Represents a time specification.
 */
struct time_specification
{
    /**
     * @brief       Default constructor.
     */
    time_specification() noexcept = default;
    
    /**
     * @brief       Constructor with parameters.
     * @param       sec : The number of seconds.
     * @param       nsec : The number of nanoseconds.
     */
    time_specification(std::uint64_t sec, std::uint64_t nsec) noexcept
            : sec(sec)
            , nsec(nsec)
    {
    }
    
    /**
     * @brief       Copy constructor.
     * @param       rhs : The object to copy.
     */
    time_specification(const time_specification& rhs) = default;
    
    /**
     * @brief       Move constructor.
     * @param       rhs : Object to move.
     */
    time_specification(time_specification&& rhs) noexcept
            : sec(rhs.sec)
            , nsec(rhs.nsec)
    {
        rhs.sec = 0;
        rhs.nsec = 0;
    }
    
    /**
     * @brief       Destructor.
     */
    virtual ~time_specification() = default;
    
    /**
     * @brief       Copy assignment operator.
     * @param       rhs : Object to copy.
     * @return      The object who call the method.
     */
    time_specification& operator =(const time_specification& rhs) = default;
    
    /**
     * @brief       Move assignment operator.
     * @param       rhs : Object to move.
     * @return      The object who call the method.
     */
    time_specification& operator =(time_specification&& rhs) noexcept
    {
        if (this != &rhs)
        {
            std::swap(sec, rhs.sec);
            std::swap(nsec, rhs.nsec);
        }
    
        return *this;
    }
    
    /**
     * @brief       Check whether the time is null.
     * @return      If function was successful true is returned, otherwise false is returned.
     */
    bool is_null() const noexcept
    {
        return sec == 0 && nsec == 0;
    }
    
    /**
     * @brief       Get the number of minutes.
     * @return      The number of minutes.
     */
    inline std::uint64_t get_minutes() const noexcept
    {
        return sec / 60;
    }
    
    /**
     * @brief       Get the number of hours.
     * @return      The number of hours.
     */
    inline std::uint64_t get_hours() const noexcept
    {
        return sec / 3600;
    }
    
    /**
     * @brief       Allows knowing whether the two time specifications are the same.
     * @param       rhs : The object to compare.
     * @return      If the objects are the same true is returned, otherwise false is returned.
     */
    bool operator ==(const time_specification& rhs) const noexcept
    {
        return sec == rhs.sec &&
               nsec == rhs.nsec;
    }
    
    /**
     * @brief       Allows knowing whether two time specifications are different.
     * @param       rhs : The object to compare.
     * @return      If the objects are different true is returned, otherwise false is returned.
     */
    bool operator !=(const time_specification& rhs) const noexcept
    {
        return !(rhs == *this);
    }
    
    /** Seconds. */
    std::uint64_t sec;
    
    /** Nanoseconds. */
    std::uint64_t nsec;
};


}
}


#endif
