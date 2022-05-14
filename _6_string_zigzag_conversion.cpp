#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
  string convert(string s, int numRows) {

    if (numRows <= 1) {
      return s;
    }

    vector<string> list(numRows);

    for (auto i = 0; i < s.length(); ++i) {
      auto index = i % (2 * numRows - 2);
      index = index < numRows ? index : 2 * numRows - 2 - index;
      list[index] += s[i];
    }

    // for (auto i = 1; i < list.size(); ++i) {
    //   list[0] += list[i];
    // }

    // return list[0];

    string res;
    for (auto str : list) {
      res += str;
    }
    return res;
  }
};

class Solution2 {
public:
  string convert(string s, int numRows) {

    if (numRows == 1)
      return s;

    vector<string> rows(min(numRows, int(s.size())));
    int curRow = 0;
    bool goingDown = false;

    for (char c : s) {
      rows[curRow] += c;
      if (curRow == 0 || curRow == numRows - 1)
        goingDown = !goingDown;
      curRow += goingDown ? 1 : -1;
    }

    string ret;
    for (string row : rows)
      ret += row;
    return ret;
  }
};

/**
 * @brief
 * The point of this question is, you need to find a relationship between index
 * and numRows
 *
 * @return int
 */
int main() {
  string s = "PAYPALISHIRING";
  auto numRows = 3;

  Solution sol;
  auto res = sol.convert(s, numRows);

  cout << res << endl;
}