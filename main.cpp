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
#include "BsImpliedVolatility.hpp"

int main() {

    // Exercise 1

    // value, strike, maturity, rate, sigma
    const BlackScholes::Data ex1_bs_data_1 {20, 25, 0.25, 0.05, 0.24, BlackScholes::OptionType::Call};
    const BlackScholes::Data ex1_bs_data_2 {20, 25, 0.25, 0.05, 0.24, BlackScholes::OptionType::Put};

    // Check the 'Call' option has been calculated correctly
    std::cout << BlackScholes::Call(ex1_bs_data_1) << " = " << BlackScholes::Option(ex1_bs_data_1) << std::endl;
    // Check the 'Put' option has been calculated correctly
    std::cout << BlackScholes::Put(ex1_bs_data_2) << " = " << BlackScholes::Option(ex1_bs_data_2) << std::endl;

    // Exercise 2

    // Exercise 2.1
    const BlackScholes::Data ex2_bs_data {BlackScholes::Read()};
    // Exercise 2.2
    const BlackScholes::Data ex2_bs_data {BlackScholes::Read("../bs.dat")};

    std::cout << "BlackScholes values:" <<
                " Strike: " << ex2_bs_data.strike <<
                " Maturity: " << ex2_bs_data.maturity <<
                " Value: " << ex2_bs_data.value <<
                " Risk-free rate: " << ex2_bs_data.rate <<
                " Volitility: " << ex2_bs_data.sigma <<
                " Tyoe: " << ((ex2_bs_data.type == BlackScholes::OptionType::Call) ? "call" : "put") <<
                std::endl;

    // Exercise 3

    // value, strike, maturity, rate, sigma
    const BlackScholes::Data ex3_option_1 {100, 100, 1, 0.05};
    const BlackScholes::Data ex3_option_2 {100, 100, 1.1, 0.05};

    std::cout << "Option 1's implied volatility is calculated as: " <<
        BlackScholes::ImpliedVolatility(ex3_option_1, 10.55, 0.2) << std::endl;
    std::cout << "Option 2's implied volatility is calculated as: " <<
        BlackScholes::ImpliedVolatility(ex3_option_2, 11.2, 0.2) << std::endl;

    return 0;
}