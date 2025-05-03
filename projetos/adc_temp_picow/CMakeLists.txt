# Generated Cmake Pico project file

cmake_minimum_required(VERSION 3.13)

set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Initialise pico_sdk from installed location
# (note this can come from environment, CMake cache etc)

# == DO NOT EDIT THE FOLLOWING LINES for the Raspberry Pi Pico VS Code Extension to work ==
if(WIN32)
    set(USERHOME $ENV{USERPROFILE})
else()
    set(USERHOME $ENV{HOME})
endif()
set(sdkVersion 2.1.1)
set(toolchainVersion 14_2_Rel1)
set(picotoolVersion 2.1.1)
set(picoVscode ${USERHOME}/.pico-sdk/cmake/pico-vscode.cmake)
if (EXISTS ${picoVscode})
    include(${picoVscode})
endif()
# ====================================================================================
set(PICO_BOARD pico_w CACHE STRING "Board type")

# Importa o SDK da Pico
include(pico_sdk_import.cmake)

project(adc_temp_picow C CXX ASM)
set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)

pico_sdk_init()

add_executable(adc_temp
    app/main.c
    hal/hal_temp.c
    drivers/sensor_temp.c
)

target_include_directories(adc_temp PRIVATE
    include
)

target_link_libraries(adc_temp pico_stdlib)

pico_add_extra_outputs(adc_temp)

# Teste com Unity
add_executable(test_temp
    test/test_temp.c
    hal/hal_temp.c
    drivers/sensor_temp.c
    unity/unity.c
)

target_include_directories(test_temp PRIVATE
    include
    unity
)

target_link_libraries(test_temp pico_stdlib)

pico_add_extra_outputs(test_temp)