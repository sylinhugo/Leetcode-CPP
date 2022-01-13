#include <vector>
#include <iostream>
#include <stack>

using namespace std;

// Definition for a binary tree node.
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
    vector<int> postorderTraversal(TreeNode *root)
    {
        vector<int> ans;
        postorderTraversal(root, ans);
        return ans;
    }

    void postorderTraversal(TreeNode *root, vector<int> &ans)
    {
        if (!root)
            return;
        postorderTraversal(root->left, ans);
        postorderTraversal(root->right, ans);
        ans.push_back(root->val);
    }
};

class Solution2
{
public:
    vector<int> postorderTraversal(TreeNode *root)
    {
        if (!root)
            return {};
        vector<int> ans;
        const vector<int> l = postorderTraversal(root->left);
        const vector<int> r = postorderTraversal(root->right);
        ans.insert(ans.end(), l.begin(), l.end());
        ans.insert(ans.end(), r.begin(), r.end());
        ans.push_back(root->val);
        return ans;
    }
};

class Solution3
{
public:
    vector<int> postorderTraversal(TreeNode *root)
    {
        if (!root)
            return {};
        deque<int> ans;
        stack<TreeNode *> s;
        s.push(root);
        while (!s.empty())
        {
            TreeNode *n = s.top();
            s.pop();
            ans.push_front(n->val); // O(1)
            if (n->left)
                s.push(n->left);
            if (n->right)
                s.push(n->right);
        }
        return vector<int>(ans.begin(), ans.end());
    }
};

/*
Time Complexity:
Space Complexity:
*/

int main()
{

    return 0;
}