# set common FLAGS
set(CMAKE_C_FLAGS "-fPIC -fstack-protector-all -D_FORTIFY_SOURCE=2 -O2 -Wall -Werror -rdynamic")
set(CMAKE_CXX_FLAGS "-fPIC -std=c++11 -fstack-protector-all -D_FORTIFY_SOURCE=2 -O2 -Wall -Werror")
set(CMAKE_SHARED_LINKER_FLAGS "-Wl,-E -Wl,-z,relro -Wl,-z,now -Wl,-z,noexecstack -Wtrampolines -fPIE -pie -shared -pthread")
set(CMAKE_EXE_LINKER_FLAGS "-Wl,-E -Wl,-z,relro -Wl,-z,now -Wl,-z,noexecstack -Wtrampolines -fPIE -pie")

if (LCR_GCOV)
    set(CMAKE_C_FLAGS_DEBUG "-Wall -fprofile-arcs -ftest-coverage")
    set(CMAKE_CXX_FLAGS_DEBUG "-Wall -fprofile-arcs -ftest-coverage")
    message("-----CXXFLAGS: " ${CMAKE_CXX_FLAGS_DEBUG})
    message("------compile with gcov-------------")
    message("-----CFLAGS: " ${CMAKE_C_FLAGS_DEBUG})
    message("------------------------------------")
endif()
