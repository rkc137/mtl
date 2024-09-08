#include <gtest/gtest.h>

#include "../src/string/include/string.hpp"
#include <string.hpp>

TEST(string_tests, test_cstr)
{
    mtl::string str("LOL");
    str += " Bruh";
    

    std::string S("LOL Bruh");
    std::string F(str.c_str());
    ASSERT_EQ(S, F);
}

int main(int argc, char *argv[])
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}