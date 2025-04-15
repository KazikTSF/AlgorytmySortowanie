#ifndef QUICKSORT_HPP
#define QUICKSORT_HPP
template <class T>
class QuickSort
{
public:
  void partition(T* arr, const int size) const {
    int pivot = arr[0];

    int i = -1;
    int j = size;
    while (true) {

      do {
        i++;
      } while (arr[i] < pivot);

      do {
        j--;
      } while (arr[j] > pivot);

      if (i > j) break;

      swap(arr[i], arr[j]);
    }
  }
    void quickSort(T* array, const int size)
    {

    }
};
#endif // QUICKSORT_HPP
