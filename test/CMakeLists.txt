

cmake_minimum_required(VERSION 3.10)

project(Open4DTest C)

set(CMAKE_C_STANDARD 11)

find_package(raylib REQUIRED)


if (APPLE)
    set(OPEN4D_LIB_PATH "${CMAKE_SOURCE_DIR}/../build/libOpen4D.dylib")
elseif (WIN32) 
    set(OPEN4D_LIB_PATH "${CMAKE_SOURCE_DIR}/../build/libOpen4D.dll")
elseif (UNIX)
    set(OPEN4D_LIB_PATH "${CMAKE_SOURCE_DIR}/../build/libOpen4D.so")
endif()

set(OPEN4D_INCLUDE_PATH "${CMAKE_SOURCE_DIR}/../include") 


include_directories(${OPEN4D_INCLUDE_PATH})


add_executable(Open4DTest 
    main.c
    renderer.c
)


target_link_libraries(Open4DTest 
    ${OPEN4D_LIB_PATH}
    raylib
)