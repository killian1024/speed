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
 * @file        speed/containers/containers_exception.hpp
 * @brief       containers_exception main header.
 * @author      Killian
 * @date        2018/01/12 - 23:39
 */

#ifndef SPEED_CONTAINERS_CONTAINERS_EXCEPTION_HPP
#define SPEED_CONTAINERS_CONTAINERS_EXCEPTION_HPP

#include "../exception.hpp"


namespace speed {
namespace containers {


/**
 * @brief       Base class used to throw exceptions when a containers operation fails.
 */
class containers_exception : public speed::exception::exception_base
{
public:
    /**
     * @brief       Get the message of the exception.
     * @return      The exception message.
     */
    char const* what() const noexcept override
    {
        return "containers exception";
    }
};


/**
 * @brief       Class used to throw exceptions when an insertion error occurs.
 */
class insertion_exception : public containers_exception
{
public:
    /**
     * @brief       Get the message of the exception.
     * @return      The exception message.
     */
    char const* what() const noexcept override
    {
        return "insertion exception";
    }
};


/**
 * @brief       This class defines the type of objects thrown as exceptions to report an empty
 *              container error
 */
class empty_container_exception : public containers_exception
{
public:
    /**
     * @brief       Get the message of the exception.
     * @return      The exception message.
     */
    char const* what() const noexcept override
    {
        return "empty container exception";
    }
};


/**
 * @brief       This class defines the type of objects thrown as exceptions to report an
 *              out-of-range error
 */
class out_of_range_exception : public containers_exception
{
public:
    /**
     * @brief       Get the message of the exception.
     * @return      The exception message.
     */
    char const* what() const noexcept override
    {
        return "out of range exception";
    }
};


/**
 * @brief       This class defines the type of objects thrown as exceptions to report an
 *              exhausted resources error
 */
class exhausted_resources_exception : public containers_exception
{
public:
    /**
     * @brief       Get the message of the exception.
     * @return      The exception message.
     */
    char const* what() const noexcept override
    {
        return "exhausted resources exception";
    }
};


/**
 * @brief       Class used to throw exceptions when an insertion error occurs.
 */
class bad_iteration_exception : public containers_exception
{
public:
    /**
     * @brief       Get the message of the exception.
     * @return      The exception message.
     */
    char const* what() const noexcept override
    {
        return "bad iteration exception";
    }
};


}
}


#endif
