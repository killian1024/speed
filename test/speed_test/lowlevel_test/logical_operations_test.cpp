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
 * @file        speed_test/lowlevel_test/lowlevel_operations_test.cpp
 * @brief       lowlevel_operations unit test.
 * @author      Killian
 * @date        2018/10/10 - 22:42
 */

#include "gtest/gtest.h"
#include "speed/lowlevel.hpp"


TEST(lowlevel_logical_operations, onehot_to_binary)
{
    for (std::size_t i = 0; i < 32; ++i)
    {
        EXPECT_TRUE(speed::lowlevel::onehot_to_binary((std::uint32_t)0x1 << i) == i + 1);
    }
}
