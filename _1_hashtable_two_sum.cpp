#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
  vector<int> twoSum(vector<int> &nums, int target) {
    std::unordered_map<int, int> hashMap;

    for (int i = 0; i < nums.size(); ++i) {
      hashMap[nums[i]] = i;
    }

    for (int i = 0; i < nums.size(); ++i) {
      int left = target - nums[i];
      if (hashMap.count(left) && hashMap[left] != i) {
        return {i, hashMap[left]};
      }
    }
    return {};
  }
};

// Input: nums = [2,7,11,15], target = 9
// Output: [0,1]
// Explanation: Because nums[0] + nums[1] == 9, we return [0, 1].

int main() {
  std::vector<int> nums = {2, 7, 11, 15};
  int target = 9;

  Solution sol;
  auto res = sol.twoSum(nums, target);

  for (auto i = 0; i < res.size(); ++i) {
    cout << res[i] << " ";
  }
  cout << endl;

  for (auto &x : res) {
    cout << x << " ";
  }
  cout << endl;

  for (auto i = res.begin(); i != res.end(); ++i) {
    cout << *i << " ";
  }
  cout << endl;

  std::vector<int>::iterator it;
  for (it = res.begin(); it != res.end(); ++it) {
    cout << *it << " ";
  }

  return 0;
}