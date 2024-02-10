#pragma once
#include <iostream>


typedef unsigned int uint;

class string {

    uint size;
    uint cap;
    char* arr;

public:
    void reserve(uint new_cap);

    string();

    string(const char* c_str);

    string(const string& another);

    string(string&& another);

    string& operator=(const string& another);

    string& operator=(string&& another);

    ~string();

    string operator+(const string& another) const;

    string& operator+=(const string& another);

    char& operator[](uint index);

    const char& operator[](uint index) const;

    bool operator>(const string& another) const;

    bool operator==(const string& another) const;

    bool operator<(const string& another) const;

    uint find(char c) const;

    uint length() const;

    char* c_str() const;

    char& at(uint index);

    friend std::ostream& operator<<(std::ostream& ostm, const string& str);

    friend std::istream& operator>>(std::istream& istm, string& str);
};