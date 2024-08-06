#include "dynamic_array.h"

template <typename T> class Stack {
private:
  Array<T> data{};
  std::size_t top{0};

public:
  Stack(const std::size_t &size) : data(Array<T>(size)) {}

  Stack() : data(Array<T>()) {}

  inline void push(const T &val) {
    data.push_back(val);
    top++;
  }

  template <typename... Values> inline void push(const Values &...vals) {
    (this->push(vals), ...);
  }

  inline T pop() {
    if (top == 0) {
      throw std::out_of_range("Stack is empty, cannot pop");
    }
    top--;
    T value = std::move(data[top]);
    data.pop_back();
    return value;
  }

  inline void print() { data.print(); }

  inline void reserve(const std::size_t &new_size) { data.reserve(new_size); }
};

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
