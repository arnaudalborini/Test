cmake_minimum_required(VERSION 3.10)
project(MySmileLifeProject)
add_compile_options(-std=c++17 -Wall)

# Ajout des sous-projets
add_subdirectory(CardGame)
add_subdirectory(MySmileLife)

# Création de l'exécutable principal
add_executable(MySmileLifeProject main.cpp)
target_link_libraries(MySmileLifeProject CardGame MySmileLife)
target_include_directories(MySmileLifeProject PRIVATE MySmileLife/include CardGame/include)


# Itérer sur les bibliothèques et leurs dossiers de tests
foreach(LIB MySmileLife)
    # Chemin vers le dossier tests de la bibliothèque
    set(LIB_TEST_DIR ${CMAKE_CURRENT_SOURCE_DIR}/${LIB}/tests)

    file(GLOB
        source_files
        ${LIB_TEST_DIR}/*.cpp
        EXCLUDE
        ${PROJECT_SRC_DIR}/*.o
        ${PROJECT_SRC_DIR}/*.a
        ${PROJECT_SRC_DIR}/*~
    )

    # Ajouter un exécutable de test pour chaque bibliothèque
    add_executable(${LIB}Tests ${source_files})
    target_link_libraries(${LIB}Tests ${LIB})
    target_include_directories(${LIB}Tests PRIVATE MySmileLife/include CardGame/include)

    # Ajouter les tests à CTest (si vous l'utilisez)
    include(CTest)
    add_test(NAME ${LIB}Tests COMMAND ${CMAKE_BINARY_DIR}/${LIB}Tests)
endforeach()