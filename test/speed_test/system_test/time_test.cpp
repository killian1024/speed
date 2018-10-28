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
 * @file        speed_test/system_test/time_test.cpp
 * @brief       time unit test.
 * @author      Killian
 * @date        2018/06/01 - 13:57
 */

#include "gtest/gtest.h"
#include "speed/system.hpp"


TEST(system_time, get_elapsed_time)
{
    speed::system::time_specification tme_spec_1(1, 0);
    speed::system::time_specification tme_spec_2(3, 0);
    speed::system::time_specification res = speed::system::get_elapsed_time(tme_spec_1, tme_spec_2);
    
    ASSERT_TRUE(res.sec == 2);
    ASSERT_TRUE(res.nsec == 0);
}


TEST(system_time, get_monotonic_time)
{
    // TODO(killian.poulaud@etu.upmc.fr): Improve this test.
    speed::system::time_specification tme_spec;
    
    ASSERT_TRUE(get_monotonic_time(&tme_spec));
}


TEST(system_time, get_real_time)
{
    // TODO(killian.poulaud@etu.upmc.fr): Improve this test.
    speed::system::time_specification tme_spec;
    
    ASSERT_TRUE(get_cpu_time(&tme_spec));
}
