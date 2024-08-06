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

  // Move assignment operator
  Array &operator=(Array &&other) noexcept {
    if (this != &other) {
      capacity_ = other.capacity_;
      size_ = other.size_;
      data_ = std::move(other.data_);

      // Reset other
      other.capacity_ = 0;
      other.size_ = 0;
    }
    return *this;
  }

  // Move constructor
  Array(Array &&other) noexcept
      : capacity_(other.capacity_), size_(other.size_),
        data_(std::move(other.data_)) {
    other.capacity_ = 0;
    other.size_ = 0;
  }

  // Deleted copy assignment operator to prevent copying
  Array &operator=(const Array &other) = delete;

  // Deleted copy constructor to prevent copying
  Array(const Array &other) = delete;

  // Resize array if it needs to grow
  inline void resize(const std::size_t &new_capacity) {
    auto new_data{std::make_unique<T[]>(new_capacity)};

    for (std::size_t i = 0; i < size_; i++) {
      new_data[i] = std::move(data_[i]);
    }

    data_ = std::move(new_data);
    capacity_ = new_capacity;
  }

  // Preallocate memory without changing the size
  inline void reserve(const std::size_t &new_capacity) {
    if (new_capacity > capacity_) {
      resize(new_capacity);
    }
  }

  inline void push_back(const T &val) {
    if (size_ == capacity_)
      resize(2 * capacity_);

    data_[size_] = val;
    size_++;
  }

  template <typename... Values> inline void push_back(const Values &...vals) {
    (push_back(vals), ...);
  }

  inline void pop_back() {
    if (size_ > 0) {
      --size_;
    }
  }

  inline T &operator[](std::size_t idx) {
    if (idx >= size_) {
      std::cout << "ERROR: trying to access idx " << idx << " but size is "
                << size_ << '\n';
      throw std::out_of_range("Index out of range");
    }
    return data_[idx];
  }

  inline const T &operator[](const std::size_t &idx) const {
    if (idx >= size_) {
      throw std::out_of_range("Index out of range");
    }
    return data_[idx];
  }

  inline void clear() { size_ = 0; }

  inline void print() {
    std::string print_str{"[ "};

    for (std::size_t i = 0; i < size_; i++) {
      print_str += std::to_string(data_[i]) + " ";
    }

    print_str += "]";

    std::cout << print_str << '\n';
  }

  inline std::size_t size() { return size_; }

  inline std::size_t capacity() { return capacity_; }
};
