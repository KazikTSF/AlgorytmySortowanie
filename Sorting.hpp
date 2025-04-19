#ifndef QUICKSORT_HPP
#define QUICKSORT_HPP
#include <random>
template <class T>
class Sorting {
 public:
  static void quickSort(T* array, const int start, const int stop) {
    if (start >= stop) {
      return;
    }
    const int pivot = partition(array, start, stop);
    quickSort(array, start, pivot);
    quickSort(array, pivot + 1, stop);
  }

 private:
  static int partition(T* arr, const int start, const int stop) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution dis(start, stop);
    int random = dis(gen);
    std::swap(arr[start], arr[random]);
    int pivot = arr[start];

    int i = start - 1;
    int j = stop + 1;
    while (true) {
      do {
        i++;
      } while (arr[i] < pivot);

      do {
        j--;
      } while (arr[j] > pivot);

      if (i >= j) {
        return j;
      }

      std::swap(arr[i], arr[j]);
    }
  }
};
#endif  // QUICKSORT_HPP
