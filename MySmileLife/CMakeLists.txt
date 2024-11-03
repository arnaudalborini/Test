set(PROJECT_SRC_DIR ${CMAKE_CURRENT_SOURCE_DIR}/src)
set(PROJECT_INCLUDE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/include)

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


find_package(boost 1.74 COMPONENTS ALL )
INCLUDE_DIRECTORIES( ${Boost_INCLUDE_DIR})

target_link_libraries(MySmileLife CardGame ${Boost_LIBRARIES})
target_include_directories(MySmileLife PRIVATE ${PROJECT_INCLUDE_DIR} ../CardGame/include)

#add_executable(MySmileLifeTests tests/MySmileLifeTest.cpp tests/CreationJoueur.cpp)
#target_link_libraries(MySmileLifeTests MySmileLife CardGame)