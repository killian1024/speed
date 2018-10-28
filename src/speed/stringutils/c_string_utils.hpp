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
 * @file        speed/stringutils/c_string_utils.hpp
 * @brief       c_string_utils functions header.
 * @author      Killian
 * @date        2016/01/08 - 19:32
 */

#ifndef SPEED_STRINGUTILS_C_STRING_UTILS_HPP
#define SPEED_STRINGUTILS_C_STRING_UTILS_HPP

#include <string>
#include <vector>


namespace speed {
namespace stringutils {


/**
 * @brief       Returns the length of a C string str.
 * @param       str : A C string.
 * @return      The length of the C string.
 */
template<typename TpChar>
[[nodiscard]] std::size_t strlen(const TpChar* str) noexcept
{
    std::size_t len = 0;
    
    if (str != nullptr)
    {
        for (; *str != '\0'; ++str)
        {
            ++len;
        }
    }
    
    return len;
}


/**
 * @brief       Copies the C string pointed by source into the array pointed by destination,
 *              including the terminating null character (and stopping at that point).
 * @param       dest : Pointer to the destination array where the content is to be copied.
 * @param       src : C string to be copied.
 * @return      The pointer to the destination array.
 */
template<typename TpDestinationChar, typename TpSourceChar>
TpDestinationChar* strcpy(TpDestinationChar* dest, const TpSourceChar* src) noexcept
{
    TpDestinationChar* orig_dest = dest;
    
    if (dest != nullptr && src != nullptr)
    {
        while (*src != '\0')
        {
            *dest++ = *src++;
        }
    
        *dest = '\0';
    }
    
    return orig_dest;
}


/**
 * @brief       Copies the C string first cnt characters of source to destination. If the end of the
 *              source C string (which is signaled by a null-character) is found before num
 *              characters have been copied, destination is padded with zeros until a total of nbr
 *              characters have been written to it.
 * @param       dest : Pointer to the 'destination' array where the content is to be copied.
 * @param       src : C string to be copied.
 * @param       nbr : Maximum number of characters to be copied from source.
 * @return      The pointer to the destination array
 */
template<typename TpDestinationChar, typename TpSourceChar>
TpDestinationChar* strncpy(
        TpDestinationChar* dest,
        const TpSourceChar* src,
        std::size_t nbr
) noexcept
{
    TpDestinationChar* orig_dest = dest;
    const TpDestinationChar* const end_dest = orig_dest + nbr;
    
    if (dest != nullptr && src != nullptr)
    {
        while (*src != '\0' && dest != end_dest)
        {
            *dest++ = *src++;
        }
        
        while (dest != end_dest)
        {
            *dest++ = '\0';
        }
        
        *dest = '\0';
    }
    
    return orig_dest;
}


/**
 * @brief       Compare the target string to the destination.
 * @param       src : Comparation source.
 * @param       trg : Comparation target.
 * @return      If the first character that does not match has a lower value in source than in
 *              target <0 is returned, if the contents of both strings are equal 0 is returned, and
 *              if the first character that does not match has a greater value in source than in
 *              target >0 is returned.
 */
template<typename TpSourceChar, typename TpTargetChar>
[[nodiscard]] int strcmp(const TpSourceChar* src, const TpTargetChar* trg) noexcept
{
    if (src == nullptr)
    {
        return (trg == nullptr) ? 0 : -1;
    }
    if (trg == nullptr)
    {
        return 1;
    }
    
    for (; *src != '\0' && *trg != '\0'; ++src, ++trg)
    {
        if (*src != *trg)
        {
            return *src < *trg ? -1 : 1;
        }
    }
    
    if (*src == '\0')
    {
        return (*trg == '\0') ? 0 : -1;
    }
    return 1;
}


/**
 * @brief       Compare the first nbr characters of source to the destination.
 * @param       src : Comparation source.
 * @param       trg : Comparation target.
 * @param       nbr : Maximum number of characters to be compared from source.
 * @return      If the first character that does not match has a lower value in source than in
 *              target <0 is returned, if the contents of both strings are equal 0 is returned, and
 *              if the first character that does not match has a greater value in source than in
 *              target >0 is returned.
 */
template<typename TpSourceChar, typename TpTargetChar>
[[nodiscard]] int strncmp(
        const TpSourceChar* src,
        const TpTargetChar* trg,
        const std::size_t nbr
) noexcept
{
    const TpSourceChar* const end_src = src + nbr;
    
    if (src == nullptr)
    {
        return (trg == nullptr) ? 0 : -1;
    }
    if (trg == nullptr)
    {
        return 1;
    }
    
    for (; *src != '\0' && *trg != '\0' && src != end_src; ++src, ++trg)
    {
        if (*src != *trg)
        {
            return *src < *trg ? -1 : 1;
        }
    }
    
    if (src != end_src)
    {
        if (*src == '\0')
        {
            return (*trg == '\0') ? 0 : -1;
        }
        if (*trg == '\0')
        {
            return 1;
        }
    }
    
    return 0;
}


/**
 * @brief       Returns a pointer to the first occurrence of a value in the C string str.
 * @param       str : The C string.
 * @param       val : Character to be located.
 * @return      A pointer to the first occurrence of val in str. If the character is not
 *              found, the function returns a null pointer.
 */
template<typename TpChar, typename TpIntegral>
[[nodiscard]] TpChar* strchr(TpChar* str, const TpIntegral val) noexcept
{
    if (str != nullptr)
    {
        while (*str != '\0' && *str != val)
        {
            ++str;
        }
        
        if (*str != val)
        {
            str = nullptr;
        }
    }
    
    return str;
}


/**
 * @brief       Returns a pointer to the first occurrence of a value in the C string str. Only the
 *              firs num characters will be evaluated.
 * @param       str : The C string.
 * @param       val : Character to be located.
 * @param       nbr : Maximum number of characters in which search.
 * @return      A pointer to the first occurrence of val in str. If the character is not
 *              found, the function returns a null pointer.
 */
template<typename TpChar, typename TpIntegral>
TpChar* strnchr(TpChar* str, const TpIntegral val, std::size_t nbr) noexcept
{
    std::size_t i;
    
    if (str != nullptr)
    {
        for (i = 0; *str != '\0' && *str != val && i < nbr - 1; ++i)
        {
            ++str;
        }
        
        if (*str != val)
        {
            str = nullptr;
        }
    }
    
    return str;
}


/**
 * @brief       Split a C string by a specified separator.
 * @param       str : The C string to split.
 * @param       sep : The character used to split the string.
 * @return      A 'std::vector' of 'std::basic_string' with all the values obtained.
 */
template<
        typename TpChar,
        typename TpIntegral,
        typename TpCharTraits = std::char_traits<TpChar>,
        typename TpAllocator = std::allocator<int>
>
[[nodiscard]] std::vector<std::basic_string<TpChar, TpCharTraits, TpAllocator>, TpAllocator>
strsplit(
        const TpChar *str,
        const TpIntegral sep
)
{
    using string_type = std::basic_string<TpChar, TpCharTraits, TpAllocator>;
    
    std::vector<string_type, TpAllocator> values;
    string_type value_builder;
    
    if (str != nullptr)
    {
        for (const TpChar* it = str; *it != '\0'; ++it)
        {
            if (*it != sep)
            {
                if (*it == '\\' &&
                    *(it + 1) != '\0' &&
                    *(it + 1) == sep)
                {
                    continue;
                }
                
                else
                {
                    value_builder += *it;
                }
            }
            
            else
            {
                if (it != str && *(it - 1) == '\\')
                {
                    value_builder += *it;
                }
                
                else if (!value_builder.empty())
                {
                    values.push_back(std::move(value_builder));
                }
            }
            
            if (*(it + 1) == '\0' && !value_builder.empty())
            {
                values.push_back(std::move(value_builder));
            }
        }
    }
    
    return values;
}


// TODO(killian.poulaud@etu.upmc.fr): Replace this function by a generic one with a predicate.
/**
 * @brief       Get a C string without the values lower than the specified value.
 * @param       str : The C string to erase the values lower than the specified value.
 * @param       val : The value used to discard characters.
 * @return      The C string without the values lower than the specified value.
 */
template<typename TpChar, typename TpIntegral>
TpChar* strdisclower(TpChar* str, const TpIntegral val) noexcept
{
    TpChar* it = str;
    bool shift = false;
    
    if (str != nullptr)
    {
        for (; *it != '\0'; ++it)
        {
            if (*it < val)
            {
                shift = true;
                break;
            }
        }
        
        if (shift)
        {
            for (TpChar* forward_it = it; *forward_it != '\0'; ++it, ++forward_it)
            {
                while (*forward_it < val)
                {
                    ++forward_it;
                    
                    if (*forward_it == '\0')
                    {
                        goto for_end;
                    }
                }
        
                *it = *forward_it;
            }
    
            for_end:
            *it = '\0';
        }
    }
    
    return str;
}
    
    
}
}


#endif
