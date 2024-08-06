#include "stack.h"
#include <iostream>

int main() {
  Stack<int> s{};

  s.push(1, 2, 3);
  std::cout << "Pushing 1, 2, 3:\n";
  s.print();

  std::cout << "Pushing 4:\n";
  s.push(4);
  s.print();

  std::cout << "Pushing 5, 6:\n";
  s.push(5, 6);
  s.print();

  std::cout << "Popping:\n";
  s.pop();
  s.print();

  std::cout << "Popping:\n";
  s.pop();
  s.print();

  return 0;
}
