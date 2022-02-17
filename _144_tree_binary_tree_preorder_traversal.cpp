#include <iostream>
#include <stack>
#include <vector>

using namespace std;

// Definition for a binary tree node.
struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right)
      : val(x), left(left), right(right) {}
};

class Solution {
 public:
  vector<int> preorderTraversal(TreeNode *root) {
    vector<int> ans;
    function<void(TreeNode *)> preorder = [&](TreeNode *n) {
      if (!n) return;
      ans.push_back(n->val);
      preorder(n->left);
      preorder(n->right);
    };
    preorder(root);
    return ans;
  }
};

class Solution2 {
 public:
  vector<int> preorderTraversal(TreeNode *root) {
    vector<int> ans;
    stack<TreeNode *> s;
    if (root) s.push(root);
    while (!s.empty()) {
      TreeNode *n = s.top();
      ans.push_back(n->val);
      s.pop();
      if (n->right) s.push(n->right);
      if (n->left) s.push(n->left);
    }
    return ans;
  }
};

/*
Approach 1: Recursion
Time Complexity:
Space Complexity:

Approach 2: Iteration
Time Complxity:
Space Complxity:
*/

int main() { return 0; }