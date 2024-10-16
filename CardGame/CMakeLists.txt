
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

add_library(CardGame
    ${source_files}
    ${header_files} 
)
target_include_directories(CardGame PUBLIC include include/Carte)


