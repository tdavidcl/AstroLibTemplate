# AstroLibTemplate

The goal is to standardize header only libs for astro physics


## Structure of a project

Would be nice to take inspiration from https://github.com/g-truc/glm, a long standing backend agnostic header only lib.

```
.
├── **lib name** (only headers here)
│   ├── header1.hpp
│   └── dir1 ....
├── src
│   ├── ... (c++ -> c wrapper) 
│   └── CMakeLists.txt
├── tests
│   ├── unitests
│   ├── physical_test
│   └── ...
├── doc
│   ├── doc.ipynb
│   └── ...
└── wrapper
    ├── pyAstroLib (c -> py wrapper)
    ├── rustAstroLib (c -> rust wrapper)
    ├── brainfuckAstroLib (c -> brainfuck wrapper)
    └── ...
```


## Compilation flags for specialized execution routes

**subject to change**

 - ```BACKEND_CPP``` (raw c++)
 - ```BACKEND_SYCL``` 
 - ```BACKEND_KOKKOS```
 - ```BACKEND_CUDA```
 - ```BACKEND_HIP```
 
 ## Mandatory Files
 
 ```c++ 
 
 ////// when using in codes
 #include <libname/libname.hpp>
 
  //////////////// libname.hpp //////////////// 
 #pragma once
 #include "backend.hpp"
 
 ///////////// libname/backend.hpp //////////// 
 #pragma once
 namespace libname {
 
 
    // option 1
    // issues : - repetitive declaration
    //          - no specific erros if no or too much backends
    enum BackendMode {
        CPP,SYCL,KOKKOS,CUDA,HIP
    };
    
    #ifdef BACKEND_CPP
    constexpr BackendMode mode = CPP;
    #endif
    
    #ifdef BACKEND_SYCL
    constexpr BackendMode mode = SYCL;
    #endif
    
    ..
    
    //forward declaration of the init/finalize fct
    void backend_init();
    void backend_finalize();
    
    void init();
    void finalize();
 
 }
 
 ```
