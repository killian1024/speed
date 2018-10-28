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
 * @file        speed/system/glibc/terminal.hpp
 * @brief       terminal functions header.
 * @author      Killian
 * @date        2017/10/18 - 01:08
 */

#ifndef SPEED_SYSTEM_GLIBC_TERMINAL_HPP
#define SPEED_SYSTEM_GLIBC_TERMINAL_HPP

#include "../system_macros.hpp"
#ifdef SPEED_GLIBC

#include <cstdio>
#include <iostream>

#include "../data_types.hpp"
#include "../error_code.hpp"


namespace speed {
namespace system {
namespace glibc {


/**
 * @brief       Flush the input terminal buffer.
 * @param       fd : The file descriptor of the terminal.
 * @param       err_code : If function fails it holds the platform-dependent error code.
 * @return      If function was successful true is returned, otherwise false is returned.
 */
bool flush_input_terminal(int fd, std::error_code* err_code = nullptr) noexcept;


/**
 * @brief       Flush the input terminal buffer.
 * @param       fd : The file descriptor of the terminal.
 * @param       err_code : If function fails it holds the platform-dependent error code.
 * @return      If function was successful true is returned, otherwise false is returned.
 */
bool flush_output_terminal(int fd, std::error_code* err_code = nullptr) noexcept;


/**
 * @brief       Print a message and pause de program execution until a key is pressed
 * @param       mess : The message to print before the pause process. If a null pointer is used
 *              there won't be a message printed.
 * @param       flush_input_term : Is it is true the input terminal buffer will be flused before the
 *              operation.
 * @param       err_code : If function fails it holds the platform-dependent error code.
 * @return      If the function was successful true is returned, otherwise false is returned.
 */
bool kbhit(
        const char* mess = nullptr,
        bool flush_input_term = true,
        std::error_code* err_code = nullptr
) noexcept;


/**
 * @brief       Set a terminal text attribute.
 * @param       strm : Stream in which set the attribute.
 * @param       term_text_attribute : Attribute to set.
 * @return      If function was successful 0 is returned, otherwise -1 is returned.
 */
bool set_terminal_text_attribute(
        ::FILE* strm,
        terminal_text_attribute term_text_attribute
) noexcept;


/**
 * @brief       Set a terminal text attribute.
 * @param       os : Ostream in which set the attribute.
 * @param       term_text_attribute : Attribute to set.
 * @return      If function was successful 0 is returned, otherwise -1 is returned.
 */
template<typename TpChar, typename TpCharTraits>
bool set_terminal_text_attribute(
        std::basic_ostream<TpChar, TpCharTraits>& os,
        terminal_text_attribute term_text_attribute
)
{
    switch (term_text_attribute)
    {
        case terminal_text_attribute::DEFAULT:
            os << "\033[0m";
            break;
        case terminal_text_attribute::BLACK:
            os << "\033[0;30m";
            break;
        case terminal_text_attribute::RED:
            os << "\033[0;31m";
            break;
        case terminal_text_attribute::GREEN:
            os << "\033[0;32m";
            break;
        case terminal_text_attribute::BROWN:
            os << "\033[0;33m";
            break;
        case terminal_text_attribute::BLUE:
            os << "\033[0;34m";
            break;
        case terminal_text_attribute::PURPLE:
            os << "\033[0;35m";
            break;
        case terminal_text_attribute::CYAN:
            os << "\033[0;36m";
            break;
        case terminal_text_attribute::LIGHT_GRAY:
            os << "\033[0;37m";
            break;
        case terminal_text_attribute::DARK_GRAY:
            os << "\033[1;30m";
            break;
        case terminal_text_attribute::LIGHT_RED:
            os << "\033[1;31m";
            break;
        case terminal_text_attribute::LIGHT_GREEN:
            os << "\033[1;32m";
            break;
        case terminal_text_attribute::YELLOW:
            os << "\033[1;33m";
            break;
        case terminal_text_attribute::LIGHT_BLUE:
            os << "\033[1;34m";
            break;
        case terminal_text_attribute::LIGHT_PURPLE:
            os << "\033[1;35m";
            break;
        case terminal_text_attribute::LIGHT_CYAN:
            os << "\033[1;36m";
            break;
        case terminal_text_attribute::WHITE:
            os << "\033[1;37m";
            break;
    }
    
    return os.good();
}


}
}
}


#endif

#endif
