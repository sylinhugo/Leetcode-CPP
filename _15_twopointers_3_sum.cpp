#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  vector<vector<int>> threeSum(vector<int> &nums) {
    vector<vector<int>> ans;

    std::sort(nums.begin(), nums.end());
    const int n = nums.size();

    for (auto i = 0; i < n - 2; ++i) {
      if (i != 0 and nums[i] == nums[i - 1]) {
        continue;
      }
      auto left = i + 1;
      auto right = n - 1;

      while (left < right) {
        auto tmp = nums[i] + nums[left] + nums[right];
        if (tmp > 0) {
          right -= 1;
        } else if (tmp < 0) {
          left += 1;
        } else {
          ans.push_back({nums[i], nums[left], nums[right]});
          while (left < right and nums[left] == nums[left + 1]) {
            left += 1;
          }
          while (left < right and nums[right - 1] == nums[right]) {
            right -= 1;
          }
          left += 1;
          right -= 1;
        }
      }
    }
    return ans;
  }
};

int main() {
  vector<int> nums1{-1, 0, 1, 2, -1, -4};
  vector<int> nums2{};
  vector<int> nums3{0};

  Solution sol;
  auto res1 = sol.threeSum(nums1);
  auto res2 = sol.threeSum(nums2);
  auto res3 = sol.threeSum(nums3);

  for (const auto &row : res1) {
    cout << "[";
    for (const auto &i : row) {
      cout << i << ", ";
    }
    cout << "]";
  }
  cout << endl;

  for (const auto &row : res1) {
    cout << "[";
    for (auto i = 0; i < row.size(); ++i) {
      if (i == row.size() - 1) {
        cout << row[i];
      } else {
        cout << row[i] << ", ";
      }
    }
    cout << "]";
  }

  return 0;
}