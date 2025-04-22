#include <cstdlib>
#include <ctime>
#include <iostream>

#include "Sorting.hpp"

int main() {
  const int size = 10;
  int array[size] = {10, 3, 7, 1, 9, 4, 6, 2, 8, 5};

  std::cout << "Original array: ";
  for (int i = 0; i < size; i++) {
    std::cout << array[i] << " ";
  }
  std::cout << std::endl;

  Sorting<int>::mergeSort(array, 0, size - 1);

  std::cout << "Sorted array: ";
  for (int i = 0; i < size; i++) {
    std::cout << array[i] << " ";
  }
  std::cout << std::endl;
  return 0;
}
