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
#include <memory>

namespace {
    // The struct FormulaValues and CalculateBsValues are only used in this file, so not needed in the header.

    // Struct for passing calculated values
    struct FormulaValues {
        double pv_k;
        double d1;
        double d2;
    };

    // Calculates values used in Black-Scholes formulae from data, returns a unique_ptr to a populated FormulaValues
    std::unique_ptr<FormulaValues> CalculateBsValues(const BlackScholes::Data &data) {
        std::unique_ptr<FormulaValues> result {std::make_unique<FormulaValues>(FormulaValues {0, 0, 0})};
        // This value gets used a couple of times, so calculate it once
        double sig_sqrt_t = data.sigma * std::sqrt(data.maturity);

        // PV(K)
        result->pv_k = data.strike * std::exp(-data.rate * data.maturity);

        // d1
        result->d1 = (std::log(data.value / data.strike) + (data.rate + 0.5 * data.sigma * data.sigma) * data.maturity) /
                     sig_sqrt_t;

        // d2
        result->d2 = result->d1 - sig_sqrt_t;

        return result;
    }
}

namespace BlackScholes {
    double Call(const Data &data) {
        // Using formula C(St,t)=N(d1)St - N(d2)PV(K)
        std::unique_ptr<::FormulaValues> values {::CalculateBsValues(data)};

        // Normal values
        double n1{mathutils::normal(values->d1)};
        double n2{mathutils::normal(values->d2)};

        return data.value * n1 - values->pv_k * n2;
    }

    double Put(const Data &data) {
        // Using formula P(St,t)=N(-d2)PV(K) - N(-d1)St
        std::unique_ptr<::FormulaValues> values {::CalculateBsValues(data)};

        // Normal values
        double n1{mathutils::normal(-values->d1)};
        double n2{mathutils::normal(-values->d2)};

        return values->pv_k * n2 - data.value * n1;
    }

    double Vega(const Data &data) {
        std::unique_ptr<::FormulaValues> values {::CalculateBsValues(data)};

        // Derivative of the CDF is the standard normal distribution: e^(-x^2/2)/sqrt(2*PI)
        return data.value * std::exp(-0.5*values->d1*values->d1)/std::sqrt(2*mathutils::PI);
    }

}