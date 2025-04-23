#ifndef QUICKSORT_HPP
#define QUICKSORT_HPP
#include <chrono>
#include <cmath>
#include <functional>
#include <map>
#include <memory>
#include <random>
template <class T>
class Sorting {
 public:
  static void quickSort(T* array, const int size) {
    quickSortUtil(array, 0, size - 1);
  }
  static void mergeSort(T* array, const int size) {
    mergeSortUtil(array, 0, size - 1);
  }

  static void introSort(T* array, const int size) {
    const int depthLimit = 2 * static_cast<int>(log(size));

    introSortUtil(array, 0, size - 1, depthLimit);
  }
  static void prepareArr(T* array, const int size,
                         const double sortedPercentage) {
    const auto sortedSize = static_cast<int>(size * sortedPercentage);
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<T> dis(std::numeric_limits<T>::min(),
                                         std::numeric_limits<T>::max());
    for (int i = 0; i < size; i++) {
      array[i] = dis(gen);
    }
    quickSort(array, sortedSize - 1);
    if (sortedPercentage >= .999) {
      for (int i = 0; i <= size / 2; i++) {
        std::swap(array[i], array[size - i - 1]);
      }
    }
  }
  static std::map<int, long> test(std::function<void(T*, int)> sorting,
                                  double sortedPercentage) {
    std::map<int, long> map;

    std::vector sizes = {100,    500,     1'000,   5'000,    10'000,
                         50'000, 100'000, 500'000, 1'000'000};
    for (const int size : sizes) {
      long res = 0;
      for (int i = 0; i < 100; i++) {
        std::cout << "Test " << i << " for size " << size << " percetage "
                  << sortedPercentage << std::endl;
        auto array = std::make_unique<T[]>(size);
        prepareArr(array.get(), size, sortedPercentage);
        auto start = std::chrono::high_resolution_clock::now();
        sorting(array.get(), size);
        auto finish = std::chrono::high_resolution_clock::now();
        res += std::chrono::duration_cast<std::chrono::microseconds>(finish -
                                                                     start)
                   .count();
      }
      map.insert(std::pair(size, res / 100));
    }
    return map;
  }

 private:
  static void mergeSortUtil(T* array, const int start, const int stop) {
    if (start >= stop) {
      return;
    }
    const int mid = std::midpoint(start, stop);
    mergeSortUtil(array, start, mid);
    mergeSortUtil(array, mid + 1, stop);
    merge(array, start, mid, stop);
  }
  static void quickSortUtil(T* array, const int start, const int stop) {
    if (start >= stop) {
      return;
    }
    const int pivot = partition(array, start, stop);
    quickSortUtil(array, start, pivot);
    quickSortUtil(array, pivot + 1, stop);
  }
  static void insertionSort(T* array, const int size) {
    for (int i = 1; i < size; i++) {
      T key = array[i];
      int j = i - 1;
      while (j >= 0 && array[j] > key) {
        array[j + 1] = array[j];
        j--;
      }
      array[j + 1] = key;
    }
  }
  static void introSortUtil(T* array, const int start, const int stop,
                            const int depthLimit) {
    if (stop - start < 16) {
      insertionSort(array + start, stop - start + 1);
      return;
    }

    if (depthLimit <= 0) {
      std::make_heap(array + start, array + stop + 1);
      std::sort_heap(array + start, array + stop + 1);
      return;
    }
    const int pivot = partition(array, start, stop);
    introSortUtil(array, start, pivot, depthLimit - 1);
    introSortUtil(array, pivot + 1, stop, depthLimit - 1);
  }
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
#endif
