#ifndef SOLUTION_H
#define SOLUTION_H

#include <random>

struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class List {
public:
  List(const std::initializer_list<int>& init)
    : size_(init.size()) {
    for (auto iter = init.begin(); iter != init.end(); ++iter) {
      head_ = new ListNode(*iter, head_);
    }

    distribution_ = std::uniform_int_distribution<int>{0, static_cast<int>(size() - 1)};
  }

  size_t size() const {
    return size_;
  }

  int at(size_t index) const {
    ListNode* node = head_;
    for (size_t i = 0; i <= index; ++i) {
      node = node->next;
    }

    return node->val;
  }

  int getRandom() {
    return at(distribution_(generator_));
  }
private:
  ListNode* head_ = nullptr;
  size_t size_ = 0;
  std::default_random_engine generator_;
  std::uniform_int_distribution<int> distribution_;
};

class Solution {
public:
  /** @param head The linked list's head.
        Note that the head is guaranteed to be not null, so it contains at least one node. */
  Solution(ListNode* head)
    : head_(head),
      length_(GetLength(head))
  {
    distribution_ = std::uniform_int_distribution<int>{0, static_cast<int>(length_ - 1)};
  }

  /** Returns a random node's value. */
  int getRandom() {
    size_t index = distribution_(generator_);
    ListNode* ptr = head_;
    for (size_t i = 0; i < index; ++i) {
      ptr = ptr->next;
    }

    return ptr->val;
  }

private:
  size_t GetLength(ListNode* head) {
    size_t length = 0;
    for (ListNode* ptr = head; ptr; ptr = ptr->next) {
      ++length;
    }

    return length;
  }

  ListNode* head_ = nullptr;
  size_t length_ = 0;
  std::default_random_engine generator_;
  std::uniform_int_distribution<int> distribution_;
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(head);
 * int param_1 = obj->getRandom();
 */

#endif // SOLUTION_H
