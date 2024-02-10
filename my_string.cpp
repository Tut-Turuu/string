#include "my_string.hpp"
#include "cstring"
#include <stdexcept>

uint clength(const char* str) {
    uint i = 0;
    while (str[i] != '\0') ++i;
    return i;
}


void string::reserve(uint new_cap) {
    if (cap >= new_cap) return;
    cap = new_cap;

    char* new_arr = new char[new_cap];
    memcpy(new_arr, arr, size);
    delete[] arr;
    arr = new_arr;
}

string::string(): arr(nullptr), size(0), cap(0) {}

string::string(const char* c_str): size(clength(c_str)), cap(clength(c_str)) {
    arr = new char[cap];
    memcpy(arr, c_str, size);
}

string::string(const string& another): size(another.size), cap(another.cap) {
    arr = new char[cap];
    memcpy(arr, another.arr, size);
}

string::string(string&& another): size(size), cap(cap) {
    arr = another.arr;
    size = another.size;
    cap = another.cap;
    another.arr = nullptr;
    another.cap = 0;
    another.size = 0;
}

string& string::operator=(const string& another) {
    delete[] arr;

    size = another.size;
    cap = another.cap;

    arr = new char[cap];

    memcpy(arr, another.arr, size);

}

string& string::operator=(string&& another) {
    delete[] arr;

    size = another.size;
    cap = another.cap;
    arr = another.arr;

    another.arr = nullptr;
    another.cap = 0;
    another.size = 0;
}

string::~string() {
    delete[] arr;
}

string string::operator+(const string& another) const {
    
    string str;

    str.reserve(size + another.size);
    str.size = size + another.size;

    
    memcpy(str.arr, arr, size);
    memcpy(str.arr + size, another.arr, another.size);
    return std::move(str);
}

string& string::operator+=(const string& another) {

    if (size + another.size > cap) {
        reserve(size + another.size);
    }

    memcpy(arr + size, another.arr, another.size);

    return *this;
}

char& string::operator[](uint index) {
    return arr[index];
}

const char& string::operator[](uint index) const {
    return arr[index];
}

bool string::operator>(const string& another) const {
    return strcmp(arr, another.arr) > 0;
}

bool string::operator==(const string& another) const {
    return strcmp(arr, another.arr);
}

bool string::operator<(const string& another) const {
    return strcmp(arr, another.arr) < 0;

}

uint string::find(char c) const {
    for (uint i = 0; i < size; ++i) {
        if (arr[i] == c) return i;
    }
    return size;
}

uint string::length() const {
    return size;
}

char* string::c_str() const {
    return arr;
}

char& string::at(uint index) {
    if (index >= size) throw std::out_of_range("ERROR: string index out of range");
    return arr[index];
}

std::ostream& operator<<(std::ostream& ostm, const string& str) {
    ostm << str.arr;
}

std::istream& operator>>(std::istream& istm, string& str) {
    char buff[100];

    istm >> buff;

    str = string(buff);

}