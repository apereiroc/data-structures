#include "dynamic_array.h"
#include <iostream>

int main() {

  std::cout << "A:\n";
  Array<int> a{5};
  a.print();

  a.push(1, 2, 3);
  a.print();

  for (int i = 1; i <= 20; i++) {
    a.push(i);
  }

  a.print();

  std::cout << "\nB:\n";

  Array<int> b(1);

  b.push(1, 2, 3, 4, 5);

  b.print();

  b.clear();

  b.print();

  b.push(1, 2, 3, 4, 5);

  b.print();

  return 0;
}
