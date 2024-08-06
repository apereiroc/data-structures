#include "dynamic_array.h"
#include <iostream>

int main() {

  std::cout << "A:\n";
  Array<int> a{5};
  a.print();

  std::cout << "Pushing back 1,2,3\n";
  a.push_back(1, 2, 3);
  a.print();

  std::cout << "Pushing back 4,5,6... 20\n";
  for (int i = 4; i <= 20; i++) {
    a.push_back(i);
  }
  a.print();

  std::cout << "\nB:\n";

  Array<int> b(1);

  std::cout << "Pushing 1,2,3,4,5\n";
  b.push_back(1, 2, 3, 4, 5);
  b.print();

  std::cout << "Clearing\n";
  b.clear();
  b.print();

  std::cout << "Pushing 1,2,3,4,5\n";
  b.push_back(1, 2, 3, 4, 5);
  b.print();

  return 0;
}
