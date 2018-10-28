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
 * @file        speed_test/lowlevel_test/enum_bitwise_operators_test.cpp
 * @brief       enum_bitwise_operators unit test.
 * @author      Killian
 * @date        2018/06/08 - 00:55
 */

#include "gtest/gtest.h"
#include "speed/lowlevel.hpp"


enum class colors : std::uint8_t
{
    NIL = 0x0,
    RED  = 0x1,
    BLUE = 0x2,
    YELLOW = 0x4,
    GREEN = 0x8,
    FULL = 0xF
};


namespace speed {
namespace lowlevel {
template<>
struct enum_bitwise_operators<colors>
{
    static constexpr bool enable = true;
};
}
}


TEST(lowlevel_enum_bitwise_operators, enable)
{
    colors colrs1 = colors::RED;
    colors colrs2 = colors::BLUE;
    
    EXPECT_TRUE((colrs1 | colrs2) != colors::NIL);
    EXPECT_TRUE((colrs1 & colrs2) == colors::NIL);
    EXPECT_TRUE((colrs1 ^ colrs2) != colors::NIL);
    EXPECT_TRUE((colrs1 << colors::RED) == colors::BLUE);
    EXPECT_TRUE((colrs2 >> colors::RED) == colors::RED);
    EXPECT_TRUE((~colrs1) != colors::RED);
    
    colrs1 |= colors::YELLOW;
    EXPECT_TRUE((colrs1 & colors::YELLOW) != colors::NIL);
    
    colrs1 &= colors::RED;
    EXPECT_TRUE((colrs1 & colors::YELLOW) == colors::NIL);
    
    colrs1 ^= colors::RED;
    EXPECT_TRUE(colrs1 == colors::NIL);
    
    colrs1 = colors::RED;
    colrs1 <<= colors::RED;
    EXPECT_TRUE(colrs1 == colors::BLUE);
    
    colrs1 >>= colors::RED;
    EXPECT_TRUE(colrs1 == colors::RED);
}

// TODO(killian.poulaud@etu.upmc.fr): Implement the test for the operators with scalars.
