#pragma once

#include "backend.hpp"

#include "defs.hpp"


#ifdef BACKEND_CPP
#include "backend/backend_cpp.hpp"
#endif

#ifdef BACKEND_SYCL
#include "backend/backend_sycl.hpp"
#endif


namespace impl::libname {

    using namespace ::libname;

    template<BackendMode mode = CPP> void test1();

    template<> inline void test1<CPP>(){

    }

    template<> inline void test1<CUDA>(){

    }
}

namespace libname {

    void test1();



    inline void test1(){
        impl::libname::test1<mode>();
    }


    

}