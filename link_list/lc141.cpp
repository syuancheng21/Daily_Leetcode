#include "list_node.h"

class Solution {
public:
  bool hasCycle(ListNode *head) {
    if (head == nullptr || head->next == nullptr) {
      return false;
    }

    ListNode *l1 = head, *l2 = head;

    while (l2 != nullptr && l2->next != nullptr) {
      l1 = l1->next;
      l2 = l2->next->next;

      if (l1 == l2) {
        return true;
      }
    }

    return false;
  }
};