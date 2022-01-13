
#include <unordered_set>
#include <set>

using namespace std;

// Definition for singly-linked list.
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
class Solution
{
public:
    ListNode *detectCycle(ListNode *head)
    {
        unordered_set<ListNode *> s;
        for (ListNode *cur = head; cur; cur = cur->next)
            if (!s.insert(cur).second)
                return cur;
        return nullptr;
    }
};

class Solution
{
public:
    ListNode *detectCycle(ListNode *head)
    {
        unordered_set<ListNode *> s;
        for (ListNode *cur = head; cur; cur = cur->next)
            if (!s.insert(cur).second)
                return cur;
        return nullptr;
    }
};