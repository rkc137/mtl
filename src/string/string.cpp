#include "string.hpp"

namespace mtl
{

string::string(const letter_type *str)
{
    const letter_type *p = str;
    for(; *p != '\0'; p++);
    data_size = p - str;
    data_ptr = new letter_type[data_size];
    for(int i = 0; i < data_size; i++)
        data_ptr[i] = str[i];
}

string::string(int n, letter_type c)
{
    data_size = n;
    data_ptr = new letter_type[data_size];
    for(auto *p = data_ptr; p < data_ptr + n; p++)
        *p = c;
}

string& string::operator+=(const letter_type *str)
{
    auto *p = str;
    for(; *p != '\0'; p++);
    int str_size = p - str;
    int new_data_size = data_size + str_size;
    auto *new_data = new letter_type[new_data_size];
    for(int i = 0; i < data_size; i++)
        new_data[i] = data_ptr[i];
    for(int i = 0; i < str_size; i++)
        new_data[i + data_size] = str[i];
    delete[] data_ptr;
    data_ptr = new_data;
    data_size = new_data_size;
    return *this;
}

string& string::operator+=(const string &str)
{
    int new_data_size = data_size + str.data_size;
    auto *new_data = new letter_type[new_data_size];
    for(int i = 0; i < data_size; i++)
        new_data[i] = data_ptr[i];
    for(int i = 0; i < str.data_size; i++)
        new_data[i + data_size] = str.data_ptr[i];
    delete[] data_ptr;
    data_ptr = new_data;
    data_size = new_data_size;
    return *this;
    // return *this += str.data_ptr;
}

string::letter_type& string::operator[](int indx)
{
    return data_ptr[indx];
}

int string::size() const
{
    return data_size;
}

char* string::c_str() const
{
    return data_ptr;
}

string::~string()
{
    delete[] data_ptr;
}

}