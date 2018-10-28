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
 * @file        speed/iostream/stdio.cpp
 * @brief       stdio functions source.
 * @author      Killian
 * @date        2016/08/24 - 09:50
 */

#include <cstdarg>
#include <cstdio>
#include <cwchar>
#ifdef __GLIBC__
#include <stdio_ext.h>
#endif


namespace speed {
namespace iostream {


void fpurge(::FILE* fp) noexcept
{
#ifdef __GLIBC__
    ::__fpurge(fp);
#else
    ::fflush(fp);
#endif
}


int printf(const char* formt, ...) noexcept
{
    int dne;
    va_list args;
    va_start(args, formt);
    dne = ::vfprintf(stdout, formt, args);
    va_end(args);
    return dne;
}


int printf(const wchar_t* formt, ...) noexcept
{
    int dne;
    va_list args;
    va_start(args, formt);
    dne = ::vfwprintf(stdout, formt, args);
    va_end(args);
    return dne;
}


}
}
