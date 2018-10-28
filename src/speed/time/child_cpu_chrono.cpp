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
 * @file       speed/time/child_cpu_chrono.cpp
 * @brief      child_cpu_chrono class definition.
 * @author     Killian
 * @date       2017/10/28 - 22:16
 */

#include "child_cpu_chrono.hpp"


namespace speed {
namespace time {


child_cpu_chrono::child_cpu_chrono() noexcept
        : start_time_spec_()
        , elapsed_time_spec_()
        , chrn_state_(chrono_states::READY)
{
}


bool child_cpu_chrono::start() noexcept
{
    if (chrn_state_ == chrono_states::READY)
    {
        chrn_state_ = chrono_states::RUNNING;
        speed::system::get_child_cpu_time(&start_time_spec_);
        return true;
    }
    
    return false;
}


bool child_cpu_chrono::stop() noexcept
{
    if (chrn_state_ == chrono_states::RUNNING)
    {
        chrn_state_ = chrono_states::STOPED;
        speed::system::get_child_cpu_time(&elapsed_time_spec_);
        elapsed_time_spec_ = speed::system::get_elapsed_time(start_time_spec_, elapsed_time_spec_);
        return true;
    }
    
    return false;
}


bool child_cpu_chrono::resume() noexcept
{
    if (chrn_state_ == chrono_states::STOPED)
    {
        chrn_state_ = chrono_states::RUNNING;
        speed::system::get_child_cpu_time(&start_time_spec_);
        start_time_spec_ = speed::system::get_elapsed_time(elapsed_time_spec_, start_time_spec_);
        return true;
    }
    
    return false;
}


bool child_cpu_chrono::restart() noexcept
{
    chrn_state_ = chrono_states::RUNNING;
    speed::system::get_child_cpu_time(&start_time_spec_);
    return true;
}


long double child_cpu_chrono::get_elapsed_time() const noexcept
{
    speed::system::time_specification cur_time_spec;
    
    if (chrn_state_ == chrono_states::READY)
    {
        return 0.0L;
    }
    else if (chrn_state_ == chrono_states::RUNNING)
    {
        speed::system::get_child_cpu_time(&cur_time_spec);
        cur_time_spec = speed::system::get_elapsed_time(start_time_spec_, cur_time_spec);
    }
    else
    {
        cur_time_spec = elapsed_time_spec_;
    }
    
    long double res = cur_time_spec.sec;
    res += (long double)cur_time_spec.nsec / 10e8l;
    
    return res;
}


speed::system::time_specification child_cpu_chrono::get_elapsed_raw_time() const noexcept
{
    speed::system::time_specification elapsed_tme;
    
    if (chrn_state_ == chrono_states::READY)
    {
        elapsed_tme.sec = 0;
        elapsed_tme.nsec = 0;
    }
    else if (chrn_state_ == chrono_states::RUNNING)
    {
        speed::system::get_child_cpu_time(&elapsed_tme);
        elapsed_tme = speed::system::get_elapsed_time(start_time_spec_, elapsed_tme);
    }
    else
    {
        elapsed_tme = elapsed_time_spec_;
    }
    
    return elapsed_tme;
}


}
}
