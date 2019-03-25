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

#include <filesystem>
#include <regex>
#include <set>

#include "../containers.hpp"
#include "../system.hpp"


namespace speed {
namespace filesystem {


class directory_iteration
{
public:
    
    //class iterator : public containers::i_mutable_iterator<std::filesystem::path, iterator>
    //{
    //public:
    //    using self_type = iterator;
    //
    //    using base_type = containers::i_mutable_iterator<std::filesystem::path, iterator>;
    //
    //    iterator(directory_iteration* compo);
    //
    //    ~iterator() override;
    //
    //    self_type& operator ++() override { return *this; };
    //
    //private:
    //    std::stack<system::directory_entity> stck_;
    //
    //    std::set<std::uint64_t> vistd_inos_;
    //
    //    std::filesystem::path cur_pth_;
    //
    //    bool end_;
    //
    //    bool opend_;
    //
    //    directory_iteration* compo_;
    //};
    //
    //directory_iteration(
    //        std::filesystem::path dir_pth,
    //        system::file_types fle_typs = system::file_types::NIL,
    //        std::uint64_t deep_lv = ~0ul,
    //        std::string regx_to_match = ""
    //);

private:
    std::filesystem::path dir_pth_;
    
    containers::flags<system::file_types> fle_typs_;
    
    std::uint64_t deep_lv_;
    
    std::string regx_to_match_;
    
    //friend class iterator;
};


}
}


#endif
