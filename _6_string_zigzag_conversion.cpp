#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
 public:
  string convert(string s, int numRows) {
    if (numRows == 1) return s;

    vector<string> rows(min(numRows, int(s.size())));
    int curRow = 0;
    bool goingDown = false;

    for (char c : s) {
      rows[curRow] += c;
      if (curRow == 0 || curRow == numRows - 1) goingDown = !goingDown;
      curRow += goingDown ? 1 : -1;
    }

    string ret;
    for (string row : rows) ret += row;
    return ret;
  }
};

/*
Approach 1: sorted row
Time Complexity: O(n)
Space Complexity: O(n)
*/

int main() {
  Solution sol;
  string s1 = "PAYPALISHIRING";
  int numRows = 3;

  auto res = sol.convert(s1, numRows);
  cout << res << endl;

  return 0;
}