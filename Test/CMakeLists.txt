
file(
    GLOB_RECURSE
    source_files 
    src/*
)
file(
    GLOB_RECURSE
    header_files 
    include/*
)

add_executable(CardGamecli main.cpp 
    ${source_files}
    ${header_files} 
)

target_include_directories(CardGamecli PUBLIC include)
target_link_libraries(CardGamecli PRIVATE CardGame)

set(EXECUTABLE_OUTPUT_PATH bin/${CMAKE_BUILD_TYPE})