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
 * @file        speed_test/system_test/filesystem_test.cpp
 * @brief       filesystem unit test.
 * @author      Killian
 * @date        2018/06/01 - 00:31
 */

#include "gtest/gtest.h"
#include "speed/system.hpp"


TEST(system_filesystem, access_1)
{
    ASSERT_TRUE(speed::system::access(".", speed::system::am_t::EXISTS));
}


TEST(system_filesystem, access_2)
{
    ASSERT_TRUE(speed::system::access(".", speed::system::am_t::EXISTS, speed::system::ft_t::DIRECTORY));
}


TEST(system_filesystem, chdir)
{
    ASSERT_TRUE(speed::system::chdir("."));
}


TEST(system_filesystem, get_file_uid)
{
    ASSERT_TRUE(speed::system::get_file_uid(".") != -1);
}


TEST(system_filesystem, get_file_gid)
{
    ASSERT_TRUE(speed::system::get_file_gid(".") != -1);
}


TEST(system_filesystem, get_tmp_path)
{
    ASSERT_TRUE(speed::system::get_tmp_path() != nullptr);
}


TEST(system_filesystem, is_block_device)
{
    ASSERT_TRUE(!speed::system::is_block_device("."));
}


TEST(system_filesystem, is_character_device)
{
    ASSERT_TRUE(!speed::system::is_character_device("."));
}


TEST(system_filesystem, is_directory)
{
    ASSERT_TRUE(speed::system::is_directory("."));
}


TEST(system_filesystem, is_fifo)
{
    ASSERT_TRUE(!speed::system::is_fifo("."));
}


TEST(system_filesystem, is_regular_file)
{
    ASSERT_TRUE(!speed::system::is_regular_file("."));
}


TEST(system_filesystem, is_socket)
{
    ASSERT_TRUE(!speed::system::is_socket("."));
}


TEST(system_filesystem, is_symlink)
{
    ASSERT_TRUE(!speed::system::is_symlink("."));
}


TEST(system_filesystem, mkdir)
{
    ASSERT_TRUE(speed::system::mkdir("tmp_dir"));
}


TEST(system_filesystem, rmdir)
{
    ASSERT_TRUE(speed::system::rmdir("tmp_dir"));
}
