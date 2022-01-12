#include <vector>
#include <iostream>
#include <stack>

using namespace std;

//   Definition for a binary tree node.
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
public:
    vector<int> inorderTraversal(TreeNode *root)
    {
        vector<int> ans;
        inorderTraversal(root, ans);
        return ans;
    }

private:
    void inorderTraversal(TreeNode *root, vector<int> &ans)
    {
        if (root == nullptr)
            return;
        inorderTraversal(root->left, ans);
        ans.push_back(root->val);
        inorderTraversal(root->right, ans);
    }
};

class Solution2
{
public:
    vector<int> inorderTraversal(TreeNode *root)
    {
        if (root == nullptr)
            return {};

        vector<int> ans;
        stack<TreeNode *> s;
        TreeNode *curr = root;

        while (curr != nullptr || !s.empty())
        {
            while (curr != nullptr)
            {
                s.push(curr);
                curr = curr->left;
            }
            curr = s.top();
            s.pop();
            ans.push_back(curr->val);
            curr = curr->right;
        }
        return ans;
    }
};

/*
Approach 1: Recursion
Time Complexity: O(n)
Space Complexity: O(n)

Approach 2: Iteration
Time Complexity: O(n)
Space Complexity: O(n)
*/

int main()
{
    Solution sol1;
    Solution2 sol2;

    TreeNode root(1);
    root.right = new TreeNode(2);
    root.right->left = new TreeNode(3);

    auto res = sol1.inorderTraversal(&root);
    for_each(res.begin(), res.end(), [&](int e)
             { cout << e << " "; }); // [1, 3, 2]

    return 0;
}