#ifndef QUICKSORT_HPP
#define QUICKSORT_HPP
#include <memory>
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
  static void mergeSort(T* array, const int start, const int stop) {
    if (start >= stop) {
      return;
    }
    const int mid = std::midpoint(start, stop);
    mergeSort(array, start, mid);
    mergeSort(array, mid + 1, stop);
    merge(array, start, mid, stop);
  }
 private:
  static int partition(T* arr, const int start, const int stop) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution dis(start, stop);
    int pivot = arr[dis(gen)];

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
  static void merge(T* arr, const int start, const int mid, const int stop) {
    const int leftSize = mid - start + 1;
    const int rightSize = stop - mid;

    auto left = std::make_unique<T[]>(leftSize);
    auto right = std::make_unique<T[]>(rightSize);

    for (int i = 0; i < leftSize; i++) {
      left[i] = arr[start + i];
    }
    for (int j = 0; j < rightSize; j++) {
      right[j] = arr[mid + 1 + j];
    }

    int i = 0;
    int j = 0;
    int k = start;

    while (i < leftSize && j < rightSize) {
      if (left[i] <= right[j]) {
        arr[k] = left[i];
        i++;
      } else {
        arr[k] = right[j];
        j++;
      }
      k++;
    }

    while (i < leftSize) {
      arr[k] = left[i];
      i++;
      k++;
    }

    while (j < rightSize) {
      arr[k] = right[j];
      j++;
      k++;
    }
  }
};
#endif  // QUICKSORT_HPP
