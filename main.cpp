/*
 * Code for week 6 exercises of C++ for Finance.
 *
 * Copyright 2019 Laurence Alexander Hurst
 *
 * This file is part of C++ for Finance.
 *
 *     C++ for Finance is free software: you can redistribute it and/or modify
 *     it under the terms of the GNU General Public License as published by
 *     the Free Software Foundation, either version 3 of the License, or
 *     (at your option) any later version.
 *
 *     C++ for Finance is distributed in the hope that it will be useful,
 *     but WITHOUT ANY WARRANTY; without even the implied warranty of
 *     MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *     GNU General Public License for more details.
 *
 *     You should have received a copy of the GNU General Public License
 *     along with Foobar.  If not, see <https://www.gnu.org/licenses/>.
 *
 * See the file LICENCE in the original source code repository for the
 * full licence.
 */

#include <iostream>
#include "BlackScholes.hpp"

int main() {

    // Exercise 1

    // value, strike, maturity, rate, sigma
    const BlackScholes::Data bs_data_1 {20, 25, 0.25, 0.05, 0.24, BlackScholes::OptionType::Call};
    const BlackScholes::Data bs_data_2 {20, 25, 0.25, 0.05, 0.24, BlackScholes::OptionType::Put};

    // Check the 'Call' option has been calculated correctly
    std::cout << BlackScholes::Call(bs_data_1) << " = " << BlackScholes::Option(bs_data_1) << std::endl;
    // Check the 'Put' option has been calculated correctly
    std::cout << BlackScholes::Put(bs_data_2) << " = " << BlackScholes::Option(bs_data_2) << std::endl;

    return 0;
}