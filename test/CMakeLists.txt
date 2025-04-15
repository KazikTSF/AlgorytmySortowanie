find_package(GTest REQUIRED)

add_executable(Tests
        QuicksortTests.cpp
)
include_directories(${GTEST_INCLUDE_DIRS})
target_link_libraries(Tests
        PRIVATE
        SortingLib
        GTest::gtest
        GTest::gtest_main
)

add_test(
        NAME Tests
        COMMAND Tests
)
