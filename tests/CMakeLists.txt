find_package(GTest REQUIRED)
enable_testing()

add_executable(string_tests string_tests.cpp)

target_link_libraries(string_tests
    PRIVATE
    GTest::GTest
    string
)

add_test(strings_gtests string_tests)
