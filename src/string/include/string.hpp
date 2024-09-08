#pragma once

//ostream
#include <iostream>

namespace mtl
{

class string
{
private:
    using letter_type = char;//later for <T>
    letter_type *data_ptr = nullptr;
    unsigned long data_size = 0;
    unsigned long data_capicity = 0;
public:
    explicit string(const letter_type *str);
    explicit string(int n, letter_type c);
    ~string();
    letter_type* c_str() const;
    letter_type& operator[](int indx);
    string& operator+=(const string &str);
    string& operator+=(const letter_type *str);
    int size() const;
};

inline std::ostream& operator<<(std::ostream& os, string &str)
{
    return os << str.c_str();
}

}