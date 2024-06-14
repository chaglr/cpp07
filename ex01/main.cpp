#include <iostream>
#include "iter.hpp"

void increment(int& x) {
    ++x;
}

void print(const int& x) {
    std::cout << x << " ";
}

class Test {
public:
    int value;
    Test(int val) : value(val) {}
};

void printTest(const Test& t) {
    std::cout << t.value << " ";
}

int main() {
    // Existing test
    int array[] = {1, 2, 3, 4, 5};
    std::size_t length = 5;

    iter(array, length, increment);
    iter(array, length, print);
    std::cout << std::endl;

    // Edge cases
    int emptyArray[] = {};
    std::size_t emptyLength = 0;

    iter(emptyArray, emptyLength, increment);
    iter(emptyArray, emptyLength, print);
    std::cout << std::endl;

    int singleElementArray[] = {42};
    std::size_t singleLength = 1;

    iter(singleElementArray, singleLength, increment);
    iter(singleElementArray, singleLength, print);
    std::cout << std::endl;

    Test testArray[] = {Test(1), Test(2), Test(3)};
    std::size_t testLength = 3;

    iter(testArray, testLength, printTest);
    std::cout << std::endl;

    return 0;
}
