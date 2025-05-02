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

# Nome do projeto
project(led_cyw43 C CXX ASM)

# Define as versões do C e C++
set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)

# Inicializa o SDK da Pico
pico_sdk_init()

# Adiciona o executável com todos os arquivos .c organizados
add_executable(led_cyw43
    app/main.c
    hal/hal_led.c
    drivers/led_embutido.c
)

# Adiciona os diretórios com os arquivos .h
target_include_directories(led_cyw43 PRIVATE
    include
)

# Liga com as bibliotecas necessárias
target_link_libraries(led_cyw43
    pico_stdlib
    pico_cyw43_arch
)

if (PICO_CYW43_SUPPORTED)
    target_link_libraries(led_cyw43 pico_cyw43_arch_none)
endif()


# Gera .uf2, .bin, .elf, etc.
pico_add_extra_outputs(led_cyw43)
