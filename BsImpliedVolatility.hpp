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

#ifndef CPP_FINANCE_WEEK6_CODE_BSIMPLIEDVOLATILITY_HPP
#define CPP_FINANCE_WEEK6_CODE_BSIMPLIEDVOLATILITY_HPP

#include "BlackScholes.hpp"

namespace BlackScholes {
    /* Estimates the volatility using a Newton Raphson method
     * Arguments:
     *   data - BlackScholes::Data for the option
     *   market_price - current price calculating for
     *   initial_guess - initial value for sigma
     *   max_iterations - maximum loops to try and achieve the tolerance (default 100)
     *   tolerance - if this tolerance is reached will exit immediately
     * Returns:
     *   calculated sigma
     */
    double ImpliedVolatility(const Data & data, const double market_price, const double initial_guess,
                      const double max_iterations=100, const double tolerance=0.00000000001);
}

#endif //CPP_FINANCE_WEEK6_CODE_BSIMPLIEDVOLATILITY_HPP
