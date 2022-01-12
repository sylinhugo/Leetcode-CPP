#include <iostream>

//  Definition for singly-linked list.
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        ListNode dummy(0);
        ListNode *tail = &dummy;
        int sum = 0;
        while (l1 || l2 || sum)
        {
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

int main()
{
    Solution sol;

    ListNode node1(2);
    node1.next = new ListNode(4);
    node1.next->next = new ListNode(3);

    ListNode node2(5);
    node2.next = new ListNode(6);
    node2.next->next = new ListNode(4);

    ListNode *res = sol.addTwoNumbers(&node1, &node2);

    while (res)
    {
        std::cout << res->val;
        res = res->next;
    }
    std::cout << std::endl;

    // Bad way
    // delete node1.next->next;
    // delete node1.next;
    // delete node2.next;
    // delete node2.next->next;

    ListNode *nextNode = node1.next;
    std::cout << "address of nextNode: " << nextNode << std::endl;
    std::cout << node1.next << std::endl;
    std::cout << node1.next->next << std::endl;

    while (nextNode)
    {
        ListNode *tmp;
        tmp = nextNode->next;
        std::cout << "inside while loop: " << nextNode << std::endl;
        delete nextNode;
        nextNode = tmp;
    }

    return 0;
}