#include <vector>

using namespace std;

int binarySearch1(vector<int> &nums, int target) {
  if (nums.size() == 0)
    return -1;

  int left = 0, right = nums.size() - 1;
  while (left <= right) {
    // Prevent (left + right) overflow
    int mid = left + (right - left) / 2;
    if (nums[mid] == target) {
      return mid;
    } else if (nums[mid] < target) {
      left = mid + 1;
    } else {
      right = mid - 1;
    }
  }

  // End Condition: left > right
  return -1;
}

int main() {
  vector<int> nums1{1, 2, 3, 4, 5};
  auto target = 4;

  auto res = binarySearch1(nums1, target);

  return 0;
}