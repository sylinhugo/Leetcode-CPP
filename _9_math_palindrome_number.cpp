#include <algorithm>
#include <iostream>

class Solution {
 public:
  bool isPalindrome(int x) {
    int num = 0;
    int aNum = std::abs(x);

    while (aNum != 0) {
      int tmp = aNum % 10;
      num = num * 10 + tmp;
      aNum /= 10;
    }

    if (x >= 0 && x == num) {
      return true;
    } else {
      return false;
    }
  }
};

int main() {
  Solution sol;
  std::cout << sol.isPalindrome(121) << std::endl;
  std::cout << sol.isPalindrome(-121) << std::endl;

  return 0;
}