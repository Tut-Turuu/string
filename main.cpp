#include "my_string.hpp"


int main() {

    string str1("my_string");

    string str2("abcdef");

    string str3("123");

    str3 = str2 + str1;

    // str1 += str;

    std::cout << "str3: " << str3 << '\n';

    std::cout << "find: " << str1.find('c') << '\n';

    std::cout << "str1 > str2: " << (str1 > str2) << '\n';

    std::cout << "str1[1]: " << str1[1] << '\n';

    try {
        std::cout << "str1.at(1000)" << str1.at(1000) << '\n';
    } catch (std::out_of_range e) {
        std::cout << e.what() << '\n';
    }

}