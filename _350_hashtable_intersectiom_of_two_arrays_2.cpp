#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
 public:
  vector<int> intersect(vector<int> &nums1, vector<int> &nums2) {
    unordered_map<int, int> count;
    vector<int> ans;
    for (int num : nums1) ++count[num];
    for (int num : nums2)
      if (count.count(num) && count[num] > 0) {
        --count[num];
        ans.push_back(num);
      }
    return ans;
  }
};

/*
Approach 1: Hashtable
Time Complexity: O(n)
Space Complexity: O(n)
*/

int main() {
  Solution sol;
  vector<int> nums1 = {1, 2, 2, 1};
  vector<int> nums2 = {2, 2};

  auto res1 = sol.intersect(nums1, nums2);
  for_each(res1.begin(), res1.end(), [&](const auto &e) { cout << e << " "; });
  cout << endl;

  nums1 = {4, 9, 5};
  nums2 = {9, 4, 9, 8, 4};
  res1 = sol.intersect(nums1, nums2);
  for_each(res1.begin(), res1.end(), [&](const auto &e) { cout << e << " "; });

  return 0;
}