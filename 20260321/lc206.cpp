struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};


class Solution {
public:
  ListNode *reverseList(ListNode *head) {
    ListNode *dummy = new ListNode(0);

    ListNode *cur = head;
    while (cur) {
      ListNode *tmp = cur;
      cur = cur->next;

      tmp->next = dummy->next;
      dummy->next = tmp;

    }
    return dummy->next;
  }
};