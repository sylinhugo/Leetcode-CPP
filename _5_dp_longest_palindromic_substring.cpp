#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
  string longestPalindrome(string s) {
    const int n = s.length();

    // the [&] over here is because we want to use "n" inside getLen
    auto getLen = [&](int l, int r) {
      while (l >= 0 && r < n && s[l] == s[r]) {
        --l;
        ++r;
      }
      return r - l - 1;
    };

    int len = 0;
    int start = 0;

    for (int i = 0; i < n; ++i) {
      int cur = max(getLen(i, i), getLen(i, i + 1));
      if (cur > len) {
        len = cur;
        start = i - (len - 1) / 2;
      }
    }

    return s.substr(start, len);
  }
};

int main() {
  auto s1 = "babad"s;
  auto s2 = "cbbd"s;

  Solution sol;
  auto res1 = sol.longestPalindrome(s1);
  auto res2 = sol.longestPalindrome(s2);

  cout << res1 << endl;
  cout << res2 << endl;

  return 0;
}