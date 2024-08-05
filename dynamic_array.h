#include <iostream>
#include <memory>

template <typename T> class Array {
private:
  std::size_t capacity_{0}, size_{0};
  std::unique_ptr<T[]> data_{nullptr};

public:
  Array() : capacity_(1), size_(0), data_(std::make_unique<T[]>(1)) {}

  Array(const std::size_t &new_capacity)
      : capacity_(new_capacity), size_(0),
        data_(std::make_unique<T[]>(new_capacity)) {}

  void resize(const std::size_t &new_capacity) {
    auto new_data{std::make_unique<T[]>(new_capacity)};

    for (std::size_t i = 0; i < size_; i++) {
      new_data[i] = std::move(data_[i]);
    }

    data_ = std::move(new_data);
    capacity_ = new_capacity;
  }

  void push(const T &val) {
    if (size_ == capacity_)
      resize(2 * capacity_);

    data_[size_] = val;
    size_++;
  }

  template <typename... Values> void push(const Values &...vals) {
    (push(vals), ...);
  }

  T &operator[](std::size_t idx) {
    if (idx >= size_) {
      throw std::out_of_range("Index out of range");
    }
    return data_[idx];
  }

  const T &operator[](const std::size_t &idx) const {
    if (idx >= size_) {
      throw std::out_of_range("Index out of range");
    }
    return data_[idx];
  }

  void clear() { size_ = 0; }

  void print() {
    std::string print_str{"[ "};

    for (std::size_t i = 0; i < size_; i++) {
      print_str += std::to_string(data_[i]) + " ";
    }

    print_str += "]";

    std::cout << print_str << '\n';
  }

  std::size_t size() { return size_; }

  std::size_t capacity() { return capacity_; }
};
