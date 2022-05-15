#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
  string longestCommonPrefix(vector<string> &strs) {
    if (strs.empty())
      return "";

    string ans;
    for (int i = 0; i < strs[0].size(); ++i) {
      for (const string &s : strs)
        if (s.length() <= i || s[i] != strs[0][i])
          return ans;
      ans += strs[0][i];
    }
    return ans;
  }
};

class Solution2 {
public:
  string longestCommonPrefix(vector<string> &strs) {
    if (strs.empty())
      return "";

    string ans = "";

    for (int i = 0; i < strs[0].size(); ++i) {
      for (const string &s : strs)
        if (s.length() <= i || s[i] != strs[0][i])
          return ans;
      ans.push_back(strs[0][i]);
    }
    return ans;
  }
};

int main() {
  vector<string> strs = {"flower", "flow", "flight"};
  Solution sol;
  auto res = sol.longestCommonPrefix(strs);

  cout << res << endl;

  return 0;
}