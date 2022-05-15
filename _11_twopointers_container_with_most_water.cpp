#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  int maxArea(const vector<int> &height) {
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

int main() {
  vector<int> height{1, 8, 6, 2, 5, 4, 8, 3, 7};
  Solution sol;

  auto res = sol.maxArea(height);
  cout << res << endl;

  return 0;
}