cmake_minimum_required(VERSION 3.13)
include(pico_sdk_import.cmake)

project(pico_threadx_project)

pico_sdk_init()

include_directories(threadx/common/inc)
include_directories(threadx/ports/cortex_m0/gnu/inc)
add_executable(${PROJECT_NAME} main.c tx_initialize_low_level.S)

set(THREADX_ARCH "cortex_m0")
set(THREADX_TOOLCHAIN "gnu")
add_subdirectory(threadx)

target_link_libraries(pico_threadx_project pico_stdlib pico_multicore threadx)
