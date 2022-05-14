#include <iostream>

using namespace std;

class Solution {
public:
  int reverse(int x) {
    int ans = 0;

    while (x != 0) {
      int r = x % 10;

      // check whether the ans will overflow or not under 32-bits environment
      if (ans > INT_MAX / 10 || ans < INT_MIN / 10)
        return 0;

      ans = ans * 10 + r;
      x /= 10;
    }

    return ans;
  }
};

/**
 * @brief
 * This will failed; however, this would not be failed in Java
 * This use overflow trick to check whether it is overflow or not
 *
 */
class Solution2 {
public:
  int reverse(int x) {
    int res = 0;

    while (x != 0) {
      int tail = x % 10;
      int newRes = res * 10 + tail;

      if (newRes / 10 != res) {
        return 0;
      }

      res = newRes;
      x /= 10;
    }
    return res;
  }
};

int main() {
  auto x1 = 123;
  auto x2 = -123;
  auto x3 = 120;

  Solution sol;
  auto res1 = sol.reverse(x1);
  auto res2 = sol.reverse(x2);
  auto res3 = sol.reverse(x3);

  cout << res1 << endl;
  cout << res2 << endl;
  cout << res3 << endl;

  return 0;
}