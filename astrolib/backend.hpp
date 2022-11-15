#pragma once

namespace libname {


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

    void init();
    void finalize();

}