#include <iostream>
#include <memory>
#include <ostream>
#include <string>

template <typename T> class ListNode {
public:
  T val{};
  std::shared_ptr<ListNode> next{nullptr};

  ListNode(const T &val) : val(val){};
};

template <typename T> class List {
private:
  std::shared_ptr<ListNode<T>> head{nullptr};
  std::shared_ptr<ListNode<T>> tail{nullptr};
  std::size_t num_elements{0};

public:
  List(const T &val)
      : head(std::make_shared<ListNode<T>>(val)), tail(head), num_elements(1) {}

  void add(const T &val) {
    auto temp{std::make_shared<ListNode<T>>(val)};
    tail->next = temp;

    tail = temp;

    num_elements++;
  }

  void print() const {
    // Start from the list's beginning
    auto temp{head};

    // Create a str to print like: element 1 -> element 2 -> ... -> element n
    std::string print_str{};

    // The size of the string to be printed is determined as:
    // Number of elements + (2 whitespaces + 2 per arrow) per number of elements
    // minus one
    // This will avoid unnecessary reallocations
    const std::size_t str_size = num_elements + 4 * (num_elements - 1);
    print_str.reserve(str_size);

    // Loop over the list
    std::size_t num_elements_visited{0};
    while (temp != nullptr) {
      // Get current element
      print_str += std::to_string(temp->val);

      // Update the counter
      num_elements_visited++;

      // Add an arrow if we are not at the end of the list
      if (num_elements_visited != num_elements)
        print_str += " -> ";

      // Get next element
      temp = temp->next;
    }

    std::cout << print_str << '\n';
  }
};

int main() {

  const auto list{std::make_unique<List<int>>(1)};

  for (int i = 2; i <= 20; i++)
    list->add(i);

  list->print();

  return 0;
}
