#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
  string intToRoman(int num) {
    vector<pair<int, string>> v{
        {1000, "M"}, {900, "CM"}, {500, "D"}, {400, "CD"}, {100, "C"},
        {90, "XC"},  {50, "L"},   {40, "XL"}, {10, "X"},   {9, "IX"},
        {5, "V"},    {4, "IV"},   {1, "I"}};

    string ans;
    auto it = cbegin(v);

    while (num) {
      if (num >= it->first) {
        num -= it->first;
        ans += it->second;
      } else {
        ++it;
      }
    }
    return ans;
  }
};

int main() {
  auto num1 = 58;
  auto num2{1994};

  Solution sol;

  auto res1 = sol.intToRoman(num1);
  auto res2 = sol.intToRoman(num2);

  cout << res1 << endl;
  cout << res2 << endl;

  return 0;
}