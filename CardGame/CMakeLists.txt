set(PROJECT_SRC_DIR ${CMAKE_CURRENT_SOURCE_DIR}/src)
set(PROJECT_INCLUDE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/include)
add_compile_options(-std=c++17 -Wall)

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

add_library(CardGame SHARED
    ${source_files}
    ${header_files} 
)

target_include_directories(CardGame PRIVATE ${PROJECT_INCLUDE_DIR})

#add_executable(CardGameTests tests/CardGameTests.cpp)
#target_link_libraries(CardGameTests CardGame)
#target_include_directories(CardGame PUBLIC include include/Carte include/Joueur)

#set(EXECUTABLE_OUTPUT_PATH bin/${CMAKE_BUILD_TYPE})
