#include <fstream>
#include <iostream>
#include <map>
#include <string>
#include <vector>

#include "Sorting.hpp"
void writeToFile(const std::string &filename, const std::map<int, long> &data) {
  std::ofstream ofs("../" + filename + ".csv");
  if (!ofs.is_open()) {
    std::cerr << "Failed to open file " << filename << std::endl;
  }
  ofs << "size;time" << std::endl;
  for (const auto &[key, value] : data) {
    ofs << key << ";" << value << std::endl;
  }
  ofs.close();
}
int main() {
  const std::array<double, 7> percentages = {0.0, .25, .5, .75, .95, .997, 1.0};
  for (const double percentage : percentages) {
    auto data = Sorting<int>::test(Sorting<int>::quickSort, percentage);
    writeToFile(std::format("quickSort{}", percentage), data);
  }
  for (const double percentage : percentages) {
    auto data = Sorting<int>::test(Sorting<int>::mergeSort, percentage);
    writeToFile(std::format("mergeSort{}", percentage), data);
  }
  for (const double percentage : percentages) {
    auto data = Sorting<int>::test(Sorting<int>::introSort, percentage);
    writeToFile(std::format("introSort{}", percentage), data);
  }
  return 0;
}
