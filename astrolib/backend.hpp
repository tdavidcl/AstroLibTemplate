#pragma once

#include <string>



////////////////////////////////////////////////
// define the library name for logs
////////////////////////////////////////////////
#define LIBNAME "AstroLib"
////////////////////////////////////////////////



////////////////////////////////////////////////
// logic to check backend modes
////////////////////////////////////////////////
constexpr std::string_view libname = LIBNAME;

//#define BACKEND_CPP
//#define BACKEND_SYCL
//#define BACKEND_KOKKOS
//#define BACKEND_HIP
//#define BACKEND_CUDA

#ifdef BACKEND_CPP
#define BACKEND_CPP_CHOSEN
#endif

#define BACKEND_CPP

#ifdef BACKEND_SYCL
#undef BACKEND_CPP
#endif

#ifdef BACKEND_KOKKOS
#undef BACKEND_CPP
#endif

#ifdef BACKEND_HIP
#undef BACKEND_CPP
#endif

#ifdef BACKEND_CUDA
#undef BACKEND_CPP
#endif

constexpr auto selected_backend = []() -> int {
    return 
        0
        #ifdef BACKEND_CPP_CHOSEN
        +1
        #endif
        #ifdef BACKEND_SYCL
        +1
        #endif
        #ifdef BACKEND_KOKKOS
        +1
        #endif
        #ifdef BACKEND_HIP
        +1
        #endif
        #ifdef BACKEND_CUDA
        +1
        #endif
    ;
};

static_assert(selected_backend() <= 1,LIBNAME" : you can not use two backend simultaneously"
" Selected backends : "
#ifdef BACKEND_CPP_CHOSEN
"CPP "
#endif
#ifdef BACKEND_SYCL
"SYCL "
#endif
#ifdef BACKEND_KOKKOS
"KOKKOS "
#endif
#ifdef BACKEND_HIP
"HIP "
#endif
#ifdef BACKEND_CUDA
"CUDA "
#endif
);

#undef LIBNAME
#undef BACKEND_CPP_CHOSEN
////////////////////////////////////////////////
////////////////////////////////////////////////
////////////////////////////////////////////////




namespace astro {

    // option 1
    // issues : - repetitive declaration
    //          - no specific erros if no or too much backends
    enum BackendMode {
        CPP,SYCL,KOKKOS,CUDA,HIP
    };

    //constexpr lambda for static assert if no backend or too much
    constexpr auto get_backend = []() -> BackendMode{
        #ifdef BACKEND_CPP
        return CPP;
        #endif

        #ifdef BACKEND_SYCL
        return SYCL;
        #endif

        #ifdef BACKEND_KOKKOS
        return KOKKOS;
        #endif

        #ifdef BACKEND_CUDA
        return CUDA;
        #endif

        #ifdef BACKEND_HIP
        return HIP;
        #endif

        return CPP;
    };

    constexpr BackendMode mode = get_backend();

    //forward declaration of the init/finalize fct
    //backend init and finalize are declared & impl in respective backends

}