add_library(SortingLib STATIC
        Quicksort.hpp
)
set_target_properties(SortingLib PROPERTIES LINKER_LANGUAGE CXX)
target_include_directories(SortingLib
        PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}
)

add_executable(Sorting
        main.cpp
)
target_include_directories(Sorting
        PRIVATE
        SortingLib
)
target_link_libraries(Sorting
        PRIVATE
        SortingLib
)
