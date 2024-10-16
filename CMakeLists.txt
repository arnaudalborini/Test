# Nous voulons un cmake "récent" pour utiliser les dernières fonctionnalités
cmake_minimum_required(VERSION 3.14)

# Notre projet est étiqueté hello
project(MySmileLife VERSION 0.1.0 LANGUAGES C CXX)

add_library(CardGamelib
    hello.cpp 
    include/hello.hpp 
)
target_include_directories(CardGamelib PUBLIC include)

add_executable(CardGamecli main.cpp)
target_link_libraries(CardGamecli PRIVATE CardGamelib)

