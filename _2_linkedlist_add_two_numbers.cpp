#include <iostream>

//   Definition for singly-linked list.
struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
  ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
    ListNode dummy{0};
    ListNode *tail = &dummy;
    int sum = 0;

    while (l1 || l2 || sum) {
      sum += (l1 ? l1->val : 0) + (l2 ? l2->val : 0);
      l1 = l1 ? l1->next : nullptr;
      l2 = l2 ? l2->next : nullptr;
      tail->next = new ListNode(sum % 10);
      sum /= 10;
      tail = tail->next;
    }
    return dummy.next;
  }
};

int main() {
  ListNode node1{2};
  ListNode node2{4};
  ListNode node3{3};
  node1.next = &node2;
  node2.next = &node3;

  ListNode node4{5};
  ListNode node5{6};
  ListNode node6{4};
  node4.next = &node5;
  node5.next = &node6;

  Solution sol;
  auto res = sol.addTwoNumbers(&node1, &node4);

  while (res) {
    std::cout << res->val << " ";
    res = res->next;
  }

  // Leetcode didn't provide constructor in class Solutiom,
  // So we are not suppose to create a pointer version class variable
  // We should just create a local storage variable(stack) instaed
  // Solution pSol = new Solution();

  return 0;
}