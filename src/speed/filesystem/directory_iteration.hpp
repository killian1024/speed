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
 * @file        speed/filesystem/directory_iteration.hpp
 * @brief       directory_iteration class header.
 * @author      Killian
 * @date        2018/11/25 - 14:08
 */

#ifndef SPEED_FILESYSTEM_DIRECTORY_ITERATION_HPP
#define SPEED_FILESYSTEM_DIRECTORY_ITERATION_HPP

#include <regex>

#include "../containers.hpp"
#include "../system.hpp"


namespace speed {
namespace filesystem {

class directory_iteration
{
public:
    directory_iteration();

private:
    system::directory_entity dir_ent_;
    
    containers::flags<file_type> fle_typs_;
    
    std::uint64_t deep_lv_;
    
    std::string regx_to_match_;
};

}
}


#endif
