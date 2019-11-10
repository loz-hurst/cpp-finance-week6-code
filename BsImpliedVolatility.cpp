/*
 * Black-Scholes functions for week 6 exercises of C++ for Finance.
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

#include "BlackScholes.hpp"
#include "BsImpliedVolatility.hpp"
#include <iostream>
#include <iomanip>

namespace {
    // Function to print out values during the loop - you might find it useful
    void Output(int i, double v, double der, double sigma)
    {
        std::cout << std::setw(2) << i;
        std::cout << std::setw(8) << std::setprecision(4) << v;
        std::cout << std::setw(8) << std::setprecision(4) << der;
        std::cout << std::setw(12) << std::setprecision(6) << sigma;
        std::cout << std::endl;
    }
}

namespace BlackScholes {
    double ImpliedVolatility (
            const Data & data, const double market_price, const double initial_guess,
            const double max_iterations, const double tolerance
    ){
        // Make a copy so we don't change the original - only safe because Data contains just primitive values
        Data our_data {data};
        our_data.sigma = initial_guess;

        double v {BlackScholes::Option(data)};
        double der {BlackScholes::Vega(data)};

        for (int i {0}; max_iterations > i; ++i) {
            // Don't forget to break if the tolerance is reached.
            ::Output(i, v, der, our_data.sigma);
        }

        return our_data.sigma;
    }
}
