#include <iostream>
#include <vector>

using namespace std;

// Binary Search (Hua Hua)
class Solution {
public:
  double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2) {
    const int n1 = nums1.size();
    const int n2 = nums2.size();

    // Make sure n1 <= n2
    if (n1 > n2)
      return findMedianSortedArrays(nums2, nums1);

    const int partition = (n1 + n2 + 1) / 2;

    int left = 0;
    int right = n1;

    // You can also change it to l <= r-1
    while (left < right) {
      const int m1 = left + (right - left) / 2;
      const int m2 = partition - m1;
      if (nums1[m1] < nums2[m2 - 1])
        left = m1 + 1;
      else
        right = m1;
    }

    const int m1 = left;
    const int m2 = partition - left;

    const int c1 = max(m1 <= 0 ? INT_MIN : nums1[m1 - 1],
                       m2 <= 0 ? INT_MIN : nums2[m2 - 1]);

    if ((n1 + n2) % 2 == 1)
      return c1;

    const int c2 =
        min(m1 >= n1 ? INT_MAX : nums1[m1], m2 >= n2 ? INT_MAX : nums2[m2]);

    return (c1 + c2) * 0.5;
  }
};

// India Youtuber
class Solution2 {
public:
  double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2) {
    if (nums1.size() > nums2.size()) {
      return findMedianSortedArrays(nums2, nums1);
    }

    const int x = nums1.size();
    const int y = nums2.size();

    int low = 0;
    int high = x;

    while (low <= high) {
      int partitionX = low + (high - low) / 2;
      int partitionY = (x + y + 1) / 2 - partitionX;

      // if partitionX is 0 it means nothing is there on left side. Use -INF for
      // maxLeftX if partitionX is length of input then there is nothing on
      // right side. Use +INF for minRightX
      int maxLeftX = (partitionX == 0) ? INT_MIN : nums1[partitionX - 1];
      int minRightX = (partitionX == x) ? INT_MAX : nums1[partitionX];

      int maxLeftY = (partitionY == 0) ? INT_MIN : nums2[partitionY - 1];
      int minRightY = (partitionY == y) ? INT_MAX : nums2[partitionY];

      if (maxLeftX <= minRightY && maxLeftY <= minRightX) {
        //  We have partitioned array at correct place
        //  Now get max of left elements and min of right elements to get the
        //  median in case of even length combined array size or get max of left
        //  for odd length combined array size.
        if ((x + y) % 2 == 0) {
          return ((double)max(maxLeftX, maxLeftY) + min(minRightX, minRightY)) /
                 2;
        } else {
          return (double)max(maxLeftX, maxLeftY);
        }
      } else if (maxLeftX > minRightY) {
        // we are too far on right side for
        // partitionX. Go on left side.
        high = partitionX - 1;
      } else {
        // we are too far on left side for partitionX. Go on right side.
        low = partitionX + 1;
      }
    }
    return 0;
  }
};

/**
 * @brief
 * Highly recommend watch both Hua Hua and India to understand
 * At first, I tried to understand Hua Hua; however, it's hard to realize
 * So, I watch India and back to review Hua Hua
 * I found that I realize, and the way Hua Hua implement is better than India
 *
 * @return int
 */
int main() {
  vector<int> nums1{1, 3};
  vector<int> nums2{2};

  Solution sol;
  auto res = sol.findMedianSortedArrays(nums1, nums2);
  cout << res;

  return 0;
}