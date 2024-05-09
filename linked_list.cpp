#include <iostream>
#include <memory>
#include <ostream>
#include <string>

template <typename T> struct ListNode {
  T val;
  ListNode *next = nullptr;
  ListNode(const T &val) : val(val){};
};

template <typename T> class List {
private:
  struct ListNode<T> *head;
  struct ListNode<T> *tail;
  std::size_t num_elements{0};

public:
  List(const T &val) : head(new ListNode<T>(val)), tail(head) {}

  void add(const T &val) {
    ListNode<T> *temp = new ListNode(val);
    tail->next = temp;

    tail = temp;

    num_elements++;
  }

  void print() const {
    // Start from the list's beginning
    ListNode<T> *temp = head;

    // Create a str to print like: element 1 -> element 2 -> ... -> element n
    std::string print_str;

    // The size of the string to print will be:
    // Number of elements + (2 whitespaces + 2 per arrow) per number of elements
    // minus one
    // This will avoid unnecessary reallocations
    const std::size_t str_size = num_elements + 4 * (num_elements - 1);
    print_str.reserve(str_size);

    // Loop over the elements
    std::size_t num_elements_visited{0};
    while (temp != nullptr) {
      // Get current element
      print_str += std::to_string(temp->val);

      // Add an arrow if we are not in the end of the list
      if (num_elements_visited != num_elements)
        print_str += " -> ";

      // Update the counter
      num_elements_visited++;

      // Get next element
      temp = temp->next;
    }

    std::cout << print_str << '\n';
  }
};

int main() {

  const auto list = std::make_unique<List<int>>(0);

  for (int i = 1; i < 20; i++)
    list->add(i);

  list->print();

  return 0;
}
