#pragma once


#include "../defs.hpp"
#include <cmath>

#include "backend_cpp/custom_stuff.hpp"



namespace libname {


    inline void backend_init(){}
    inline void backend_finalize(){}

    inline void init(){}
    inline void finalize(){}


    template<> inline float fma(float a , float b, float c){
        return std::fma(a,b,c);
    }

    template<> inline double fma(double a , double b, double c){
        return std::fma(a,b,c);
    }

    template<> inline long double fma(long double a , long double b, long double c){
        return std::fma(a,b,c);
    }

}