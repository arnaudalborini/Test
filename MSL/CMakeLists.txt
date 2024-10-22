
file(
    GLOB
    source_files 
    src/*
)
file(
    GLOB
    header_files 
    include/*
)

add_executable(MSLexe main.cpp 
    ${source_files}
    ${header_files} 
)

target_include_directories(MSLexe PUBLIC include)
target_link_libraries(MSLexe PRIVATE CardGame)

set(EXECUTABLE_OUTPUT_PATH bin/${CMAKE_BUILD_TYPE})