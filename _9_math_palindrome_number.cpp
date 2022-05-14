#include <cmath>
#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
  bool isPalindrome(int x) {
    string s = to_string(x);
    return s == string(rbegin(s), rend(s));
  }
};

class Solution2 {
public:
  bool isPalindrome(int x) {
    if (x < 0)
      return false;

    int d = static_cast<int>(log10(x) + 1);
    int t = pow(10, d - 1);

    for (int i = 0; i < d / 2; ++i) {
      if (x / t != x % 10)
        return false;

      x = (x - x / t * t) / 10;
      t /= 100;
    }

    return true;
  }
};

/**
 * @brief
 * This will failed !!!!!!!
 * I mimic python solution to finish it; however, in Leetcode environment c++ is
 * 32 bit; hence, this would failed !!!
 *
 */
class Solution3 {
public:
  bool isPalindrome(int x) {
    auto ans = 0;
    auto origin = x;

    if (x < 0) {
      return false;
    }

    while (x != 0) {
      auto temp = x % 10;
      ans = ans * 10 + temp;
      x = x / 10;
    }

    if (origin == ans) {
      return true;
    } else
      return false;
  }
};

class Solution4 {
public:
  bool isPalindrome(int x) {

    // Special cases:
    // As discussed above, when x < 0, x is not a palindrome.
    // Also if the last digit of the number is 0, in order to be a palindrome,
    // the first digit of the number also needs to be 0.
    // Only 0 satisfy this property.
    if (x < 0 || (x % 10 == 0 && x != 0)) {
      return false;
    }

    int revertedNumber = 0;
    while (x > revertedNumber) {
      revertedNumber = revertedNumber * 10 + x % 10;
      x /= 10;
    }

    // When the length is an odd number, we can get rid of the middle digit by
    // revertedNumber/10 For example when the input is 12321, at the end of the
    // while loop we get x = 12, revertedNumber = 123, since the middle digit
    // doesn't matter in palidrome(it will always equal to itself), we can
    // simply get rid of it.
    return x == revertedNumber || x == revertedNumber / 10;
  }
};

/**
 * @brief
 * Look Leetcode explaination!!!!!!!!!
 *
 * @return int
 */
int main() {

  auto x1 = 121;
  auto x2 = -121;
  auto x3 = 10;
  int x4 = 1234567899;
  auto x5 = 1123211;

  Solution2 sol2;
  bool res1 = sol2.isPalindrome(x1);
  bool res2 = sol2.isPalindrome(x2);
  bool res3 = sol2.isPalindrome(x3);

  cout << boolalpha << res1 << endl;
  cout << boolalpha << res2 << endl;
  cout << boolalpha << res3 << endl;

  Solution3 sol3;
  auto res4 = sol3.isPalindrome(x1);
  cout << boolalpha << res4 << endl;

  Solution4 sol4;
  auto res5 = sol4.isPalindrome(x4);
  cout << boolalpha << res5 << endl;

  auto res6 = sol4.isPalindrome(x5);
  cout << boolalpha << res6 << endl;

  return 0;
}