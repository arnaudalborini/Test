# Nous voulons un cmake "récent" pour utiliser les dernières fonctionnalités
cmake_minimum_required(VERSION 3.14)

# Notre projet est étiqueté hello
project(MySmileLife VERSION 0.1.0 LANGUAGES C CXX)

add_subdirectory(CardGame)
add_subdirectory(Test)
