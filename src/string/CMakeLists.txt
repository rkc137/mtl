add_library(string STATIC string.cpp)

target_include_directories(string PUBLIC include)

install(TARGETS string
        ARCHIVE DESTINATION lib)
install(DIRECTORY include/ DESTINATION include)