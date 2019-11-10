cmake_minimum_required(VERSION 3.12)
project(cpp_finance_week6_code)

set(CMAKE_CXX_STANDARD 14)
add_executable(cpp_finance_week6_code main.cpp BlackScholes.cpp BlackScholes.hpp mathutils.cpp mathutils.hpp BsImpliedVolatility.cpp BsImpliedVolatility.hpp)
target_compile_options (cpp_finance_week6_code PRIVATE -W4)
