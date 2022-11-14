#pragma once


#include "../defs.hpp"

#include <memory>
#include <sycl/sycl.hpp>

namespace libname {

    std::unique_ptr<sycl::queue> queue;

    inline void backend_init(){queue = std::make_unique<sycl::queue>{};}
    inline void backend_finalize(){}

    

    inline void init(){}
    inline void finalize(){queue.reset();}

    template<class T> inline T fma(T a , T b, T c){
        return sycl::fma(a,b,c);
    }

}