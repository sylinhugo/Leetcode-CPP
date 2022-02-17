#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  int maxArea(vector<int> &height) {
    int ans = 0;
    int l = 0;
    int r = height.size() - 1;
    while (l < r) {
      int h = min(height[l], height[r]);
      ans = max(ans, h * (r - l));
      if (height[l] < height[r])
        ++l;
      else
        --r;
    }
    return ans;
  }
};

/*
Approach 1: Two pointers
Time Complexity: O(n)
Space Complexity: O(1)
 */

int main() {
  Solution sol;
  vector<int> input1 = {1, 8, 6, 2, 5, 4, 8, 3, 7};

  auto res = sol.maxArea(input1);
  cout << res << endl;

  return 0;
}