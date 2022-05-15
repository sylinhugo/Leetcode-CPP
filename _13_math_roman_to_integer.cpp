#include <iostream>
#include <map>
#include <string>

using namespace std;

class Solution {
public:
  int romanToInt(string s) {
    map<char, int> m{{'I', 1},   {'V', 5},   {'X', 10},  {'L', 50},
                     {'C', 100}, {'D', 500}, {'M', 1000}};
    int ans = 0;
    for (int i = 0; i < s.length(); i++) {
      ans += m[s[i]];
      if (i > 0 && m[s[i]] > m[s[i - 1]])
        ans -= 2 * m[s[i - 1]];
    }
    return ans;
  }
};

int main() {
  auto s1 = "MCMXCIV"s;
  auto s2 = "LVIII"s;

  Solution sol;
  auto res1 = sol.romanToInt(s1);
  auto res2 = sol.romanToInt(s2);

  cout << res1 << endl;
  cout << res2 << endl;

  return 0;
}