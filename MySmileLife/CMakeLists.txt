set(PROJECT_SRC_DIR ${CMAKE_CURRENT_SOURCE_DIR}/src)
set(PROJECT_INCLUDE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/include)
add_compile_options(-Wall -Wextra -Wpedantic)

file(GLOB_RECURSE
     source_files
     ${PROJECT_SRC_DIR}/*.cpp
     ${PROJECT_SRC_DIR}/*.cxx
     EXCLUDE
     ${PROJECT_SRC_DIR}/*.o
     ${PROJECT_SRC_DIR}/*.a
     ${PROJECT_SRC_DIR}/*~
)

file(GLOB_RECURSE
     header_files
     ${PROJECT_INCLUDE_DIR}/*.h
     ${PROJECT_INCLUDE_DIR}/*.hpp
)

add_library(MySmileLife SHARED
    ${source_files}
    ${header_files} 
)

target_link_libraries(MySmileLife CardGame)
target_include_directories(MySmileLife PRIVATE ${PROJECT_INCLUDE_DIR} ../CardGame/include)

#add_executable(MySmileLifeTests tests/MySmileLifeTest.cpp tests/CreationJoueur.cpp)
#target_link_libraries(MySmileLifeTests MySmileLife CardGame)