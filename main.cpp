// debug
// g++ -std=c++17 -Wconversion -Wall  -Wextra -pedantic -g3 -DDEBUG -fsanitize=address -fsanitize=undefined -D_GLIBCXX_DEBUG main.cpp -o main_debug

// make main
// g++ main.cpp -o main
#include <iostream>

int main()
{
    // Write C++ code here
    std::cout << "Hello world!";
    int k;
    std::cin >> k;
    std::cout << k;

    return 0;
}