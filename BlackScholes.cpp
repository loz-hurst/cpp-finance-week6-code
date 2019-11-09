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
#include "mathutils.hpp"
#include <cmath>

namespace BlackScholes {
    // The struct FormulaValues and CalculateBsValues are only used in this file, so not needed in the header.

    // Struct for passing calculated values
    struct FormulaValues {
        double pv_k;
        double d1;
        double d2;
    };

    // Calculates values used in Black-Scholes formulae from data, stores result in values
    void CalculateBsValues(const Data &data, FormulaValues &values) {
        // This value gets used a couple of times, so calculate it once
        double sig_sqrt_t = data.sigma * std::sqrt(data.maturity);

        // PV(K)
        values.pv_k = data.strike * std::exp(-data.rate * data.maturity);

        // d1
        values.d1 = (std::log(data.value / data.strike) + (data.rate + 0.5 * data.sigma * data.sigma) * data.maturity) /
                    sig_sqrt_t;

        // d2
        values.d2 = values.d1 - sig_sqrt_t;
    }

    double Call(const Data &data) {
        // Using formula C(St,t)=N(d1)St - N(d2)PV(K)
        FormulaValues values{0, 0, 0};
        CalculateBsValues(data, values);

        // Normal values
        double n1{mathutils::normal(values.d1)};
        double n2{mathutils::normal(values.d2)};

        return data.value * n1 - values.pv_k * n2;
    }

    double Put(const Data &data) {
        // Using formula P(St,t)=N(-d2)PV(K) - N(-d1)St
        FormulaValues values{0, 0, 0};
        CalculateBsValues(data, values);

        // Normal values
        double n1{mathutils::normal(-values.d1)};
        double n2{mathutils::normal(-values.d2)};

        return values.pv_k * n2 - data.value * n1;
    }

}