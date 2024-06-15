#include "Array.hpp"
#include "Test.hpp"

// Test function for default constructor and size method
void testDefaultConstructorAndSize() {
	std::cout << "\n--- Test: Default Constructor and Size Method ---" << std::endl;
	Array<int> defaultArray;
	std::cout << "Default constructor, size: " << defaultArray.size() << " (expected: 0)" << std::endl;
}

// Test function for constructor with size parameter
void testConstructorWithSize() {
	std::cout << "\n--- Test: Constructor with Size Parameter ---" << std::endl;
	Array<int> sizedArray(5);
	std::cout << "Constructor with size 5, elements: ";
	for (std::size_t i = 0; i < sizedArray.size(); ++i) {
		std::cout << sizedArray[i] << " ";
	}
	std::cout << " (expected: 0 0 0 0 0)" << std::endl;
}

// Test function for copy constructor
void testCopyConstructor() {
	std::cout << "\n--- Test: Copy Constructor ---" << std::endl;
	Array<int> originalArray(3);
	for (std::size_t i = 0; i < originalArray.size(); ++i) {
		originalArray[i] = i + 1;
	}
	Array<int> copiedArray = originalArray;
	std::cout << "Original array: ";
	for (std::size_t i = 0; i < originalArray.size(); ++i) {
		std::cout << originalArray[i] << " ";
	}
	std::cout << "\nCopied array: ";
	for (std::size_t i = 0; i < copiedArray.size(); ++i) {
		std::cout << copiedArray[i] << " ";
	}
	std::cout << " (expected: 1 2 3)" << std::endl;
}

// Test function for copy assignment operator
void testCopyAssignmentOperator() {
	std::cout << "\n--- Test: Copy Assignment Operator ---" << std::endl;
	Array<int> array1(3);
	for (std::size_t i = 0; i < array1.size(); ++i) {
		array1[i] = i + 1;
	}
	Array<int> array2(5);
	array2 = array1;
	std::cout << "Array1: ";
	for (std::size_t i = 0; i < array1.size(); ++i) {
		std::cout << array1[i] << " ";
	}
	std::cout << "\nArray2 (after assignment): ";
	for (std::size_t i = 0; i < array2.size(); ++i) {
		std::cout << array2[i] << " ";
	}
	std::cout << " (expected: 1 2 3)" << std::endl;
}

// Test function for subscript operator
void testSubscriptOperator() {
	std::cout << "\n--- Test: Subscript Operator ---" << std::endl;
	Array<int> array(3);
	for (std::size_t i = 0; i < array.size(); ++i) {
		array[i] = i + 10;
	}
	const Array<int>& constArray = array;
	std::cout << "Array elements: ";
	for (std::size_t i = 0; i < constArray.size(); ++i) {
		std::cout << constArray[i] << " ";
	}
	std::cout << " (expected: 10 11 12)" << std::endl;
}

// Test function for out-of-bounds access
void testOutOfBoundsAccess() {
	std::cout << "\n--- Test: Out-of-Bounds Access ---" << std::endl;
	Array<int> array(3);
	try {
		std::cout << "Trying to access array[10]: " << array[10] << std::endl;
	} catch (const std::out_of_range& e) {
		std::cout << "Exception caught: " << e.what() << " (expected: Index out of bounds)" << std::endl;
	}
}

// Test function for memory leaks
void testMemoryLeaks() {
	std::cout << "\n--- Test: Memory Leaks ---" << std::endl;
	{
		Array<Test> testArray(3);
		std::cout << "Array of Test objects created.\n";
		testArray[0] = Test(1);
		std::cout << "Assigned Test(1) to testArray[0]\n";
		testArray[1] = Test(2);
		std::cout << "Assigned Test(2) to testArray[1]\n";
		testArray[2] = Test(3);
		std::cout << "Assigned Test(3) to testArray[2]\n";
	}
	std::cout << "End of scope, destructors should have been called." << std::endl;
}

// Test function for self-assignment
void testSelfAssignment() {
	std::cout << "\n--- Test: Self-Assignment ---" << std::endl;
	Array<int> array(3);
	for (std::size_t i = 0; i < array.size(); ++i) {
		array[i] = i + 10;
	}
	array = array;
	std::cout << "Self-assignment array: ";
	for (std::size_t i = 0; i < array.size(); ++i) {
		std::cout << array[i] << " ";
	}
	std::cout << " (expected: 10 11 12)" << std::endl;
}

int main() {
	try {
		testDefaultConstructorAndSize();
		testConstructorWithSize();
		testCopyConstructor();
		testCopyAssignmentOperator();
		testSubscriptOperator();
		testOutOfBoundsAccess();
		testMemoryLeaks();
		testSelfAssignment();
	} catch (const std::exception& e) {
		std::cerr << "Exception: " << e.what() << std::endl;
	}
	return 0;
}
