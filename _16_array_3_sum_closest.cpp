#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  int threeSumClosest(vector<int> &num, int target) {
    int n = num.size();
    int d = INT_MAX;
    int ans = target;
    sort(num.begin(), num.end());

    for (int i = 0; i < n - 2; i++) {
      int s = i + 1, t = n - 1;
      while (s < t) {
        int sum = num[i] + num[s] + num[t];
        if (sum == target)
          return target;

        int diff = abs(sum - target);
        if (diff < d) {
          d = diff;
          ans = sum;
        }

        if (sum > target)
          --t;
        else
          ++s;
      }
    }

    return ans;
  }
};

class Solution2 {
public:
  int threeSumClosest(vector<int> &nums, int target) {
    sort(nums.begin(), nums.end());
    pair<int, int> res{INT_MAX, 0};
    auto n = nums.size();

    for (auto i = 0; i < n - 2; i++) {
      if (i != 0 and nums[i] == nums[i - 1])
        continue;
      auto left = i + 1;
      auto right = n - 1;

      while (left < right) {
        auto tmp = nums[i] + nums[left] + nums[right];
        auto diff = abs(target - tmp);

        if (diff < res.first)
          res = {diff, tmp};

        if (tmp < target)
          left += 1;
        else
          right -= 1;
      }
    }
    return res.second;
  }
};

int main() {
  vector<int> nums1{-1, 2, 1, -4};
  auto target1{1};

  vector<int> nums2{0, 0, 0};
  auto target2{1};

  Solution sol;
  auto res1 = sol.threeSumClosest(nums1, target1);
  auto res2 = sol.threeSumClosest(nums2, target2);

  cout << res1 << endl;
  cout << res2 << endl;

  return 0;
}