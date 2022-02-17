#include <iostream>
#include <vector>

using namespace std;

//   Definition for a binary tree node.
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
  vector<TreeNode *> generateTrees(int n) {
    if (n == 0) return {};

    const auto &ans = generateTrees(1, n);
    cout << ans.size() << endl;

    return ans;
  }

 private:
  vector<TreeNode *> generateTrees(int l, int r) {
    if (l > r) return {nullptr};

    vector<TreeNode *> ans;

    for (int i = l; i <= r; ++i)
      for (TreeNode *left : generateTrees(l, i - 1))
        for (TreeNode *right : generateTrees(i + 1, r)) {
          ans.push_back(new TreeNode(i));
          ans.back()->left = left;
          ans.back()->right = right;
        }
    return ans;
  }
};

/*
Approach 1: Recursion
Time Complexity: O(3^n)
Space Complexity: O(3^n)
*/

int main() {
  Solution sol;
  auto input1 = 3;

  vector<TreeNode *> res = sol.generateTrees(input1);

  return 0;
}