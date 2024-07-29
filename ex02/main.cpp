#include "Array.hpp"
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <sstream>
#include <string>

// #define MAX_VAL 750
// int main(int, char **) {
//   Array<int> numbers(MAX_VAL);
//   int *mirror = new int[MAX_VAL];
//   srand(time(NULL));
//   for (int i = 0; i < MAX_VAL; i++) {
//     const int value = rand();
//     numbers[i] = value;
//     mirror[i] = value;
//   }
//   // SCOPE
//   {
//     Array<int> tmp = numbers;
//     Array<int> test(tmp);
//   }

//   for (int i = 0; i < MAX_VAL; i++) {
//     if (mirror[i] != numbers[i]) {
//       std::cerr << "didn't save the same value!!" << std::endl;
//       return 1;
//     }
//   }
//   try {
//     numbers[-2] = 0; //"Index out of bounds"
//   } catch (const std::exception &e) {
//     std::cerr << e.what() << '\n';
//   }
//   try {
//     numbers[MAX_VAL] = 0; //"Index out of bounds"
//   } catch (const std::exception &e) {
//     std::cerr << e.what() << '\n';
//   }

//   for (int i = 0; i < MAX_VAL; i++) {
//     numbers[i] = rand();
//   }
//   delete[] mirror; //
//   return 0;
// }

#include "Array.hpp"
#include <iostream>
#include <sstream>
#include <string>

class Complex {
public:
  Complex(double r = 0, double i = 0) : real(r), imag(i) {}
  std::string toString() const {
    std::ostringstream oss;
    oss << real << "+" << imag << "i";
    return oss.str();
  }

private:
  double real, imag;
};

template <typename T> void printArray(const Array<T> &arr) {
  for (size_t i = 0; i < arr.size(); ++i) {
    std::cout << "arr[" << i << "] = " << arr[i] << std::endl;
  }
}

template <> void printArray(const Array<Complex> &arr) {
  for (size_t i = 0; i < arr.size(); ++i) {
    std::cout << "arr[" << i << "] = " << arr[i].toString() << std::endl;
  }
}

int main() {
  try {
    // Test construction with no parameter
    std::cout << "1. Testing construction with no parameter:" << std::endl;
    Array<int> emptyArray;
    std::cout << "Size of empty array: " << emptyArray.size() << std::endl;

    // Test construction with unsigned int parameter
    std::cout << "\n2. Testing construction with unsigned int parameter:"
              << std::endl;
    Array<int> intArray(5);
    std::cout << "Size of int array: " << intArray.size() << std::endl;
    std::cout << "Default values:" << std::endl;
    printArray(intArray);

    // Test element access and modification
    std::cout << "\n3. Testing element access and modification:" << std::endl;
    for (size_t i = 0; i < intArray.size(); ++i) {
      intArray[i] = i * 10;
    }
    printArray(intArray);

    // Test copy construction
    std::cout << "\n4. Testing copy construction:" << std::endl;
    Array<int> copiedArray(intArray);
    std::cout << "Original array:" << std::endl;
    printArray(intArray);
    std::cout << "Copied array:" << std::endl;
    printArray(copiedArray);

    // Modify original array to prove deep copy
    intArray[2] = 100;
    std::cout << "After modifying original array:" << std::endl;
    std::cout << "Original array:" << std::endl;
    printArray(intArray);
    std::cout << "Copied array (should remain unchanged):" << std::endl;
    printArray(copiedArray);

    // Test assignment operator
    std::cout << "\n5. Testing assignment operator:" << std::endl;
    Array<int> assignedArray;
    assignedArray = intArray;
    std::cout << "Assigned array:" << std::endl;
    printArray(assignedArray);

    // Modify original array to prove deep copy
    intArray[3] = 200;
    std::cout << "After modifying original array:" << std::endl;
    std::cout << "Original array:" << std::endl;
    printArray(intArray);
    std::cout << "Assigned array (should remain unchanged):" << std::endl;
    printArray(assignedArray);

    // Test out of bounds access
    std::cout << "\n6. Testing out of bounds access:" << std::endl;
    try {
      intArray[5] = 50; // This should throw an exception
    } catch (const std::exception &e) {
      std::cout << "Exception caught: " << e.what() << std::endl;
    }

    // Test size() function
    std::cout << "\n7. Testing size() function:" << std::endl;
    std::cout << "Size of intArray: " << intArray.size() << std::endl;
    std::cout << "Size of emptyArray: " << emptyArray.size() << std::endl;

    // Test with complex type
    std::cout << "\n8. Testing with Array<Complex>:" << std::endl;
    Array<Complex> complexArray(3);
    complexArray[0] = Complex(1.0, 2.0);
    complexArray[1] = Complex(3.0, 4.0);
    complexArray[2] = Complex(5.0, 6.0);
    printArray(complexArray);

    std::cout << "\nAll tests completed successfully!" << std::endl;
  } catch (const std::exception &e) {
    std::cerr << "Unexpected exception: " << e.what() << std::endl;
    return 1;
  }

  return 0;
}