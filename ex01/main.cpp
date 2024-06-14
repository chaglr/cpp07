#include <iostream>
#include <string>
#include "iter.hpp"

void printInt(const int& x) {
	std::cout << x << " ";
}

void printString(const std::string& str) {
	std::cout << str << " ";
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
	// Test with int array
	int intArray[] = {1, 2, 3, 4, 5};
	std::size_t intLength = 5;
	iter(intArray, intLength, printInt);
	std::cout << std::endl;

	// Test with std::string array
	std::string strArray[] = {"Hello", "World", "Test"};
	std::size_t strLength = 3;
	iter(strArray, strLength, printString);
	std::cout << std::endl;

	// Test with custom class array
	Test testArray[] = {Test(10), Test(20), Test(30)};
	std::size_t testLength = 3;
	iter(testArray, testLength, printTest);
	std::cout << std::endl;

	// Edge cases
	// Test with empty int array
	int emptyIntArray[] = {};
	std::size_t emptyIntLength = 0;
	iter(emptyIntArray, emptyIntLength, printInt);
	std::cout << std::endl;

	// Test with single element int array
	int singleElementIntArray[] = {42};
	std::size_t singleElementIntLength = 1;
	iter(singleElementIntArray, singleElementIntLength, printInt);
	std::cout << std::endl;

	// Test with empty string array
	std::string emptyStrArray[] = {};
	std::size_t emptyStrLength = 0;
	iter(emptyStrArray, emptyStrLength, printString);
	std::cout << std::endl;

	// Test with single element string array
	std::string singleElementStrArray[] = {"Single"};
	std::size_t singleElementStrLength = 1;
	iter(singleElementStrArray, singleElementStrLength, printString);
	std::cout << std::endl;

	// Test with empty custom class array
	Test emptyTestArray[] = {};
	std::size_t emptyTestLength = 0;
	iter(emptyTestArray, emptyTestLength, printTest);
	std::cout << std::endl;

	// Test with single element custom class array
	Test singleElementTestArray[] = {Test(99)};
	std::size_t singleElementTestLength = 1;
	iter(singleElementTestArray, singleElementTestLength, printTest);
	std::cout << std::endl;

	return 0;
}
