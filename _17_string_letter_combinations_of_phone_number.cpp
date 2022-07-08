#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
  vector<string> letterCombinations(string digits) {
    if (digits.empty())
      return {};

    vector<vector<char>> d(10);
    d[0] = {' '};
    d[1] = {};
    d[2] = {'a', 'b', 'c'};
    d[3] = {'d', 'e', 'f'};
    d[4] = {'g', 'h', 'i'};
    d[5] = {'j', 'k', 'l'};
    d[6] = {'m', 'n', 'o'};
    d[7] = {'p', 'q', 'r', 's'};
    d[8] = {'t', 'u', 'v'};
    d[9] = {'w', 'x', 'y', 'z'};

    string cur;
    vector<string> ans;
    dfs(digits, d, 0, cur, ans);
    return ans;
  }

private:
  void dfs(const string &digits, const vector<vector<char>> &d, int l,
           string &cur, vector<string> &ans) {
    if (l == digits.length()) {
      ans.push_back(cur);
      return;
    }

    for (const char c : d[digits[l] - '0']) {
      cur.push_back(c);
      dfs(digits, d, l + 1, cur, ans);
      cur.pop_back();
    }
  }
};

class Solution2 {
public:
  vector<string> letterCombinations(string digits) {
    if (digits.empty())
      return {};

    unordered_map<char, vector<char>> phone;
    phone = {
        {'0', {' '}},           {'1', {}},
        {'2', {'a', 'b', 'c'}}, {'3', {'d', 'e', 'f'}},
        {'4', {'g', 'h', 'i'}}, {'5', {'j', 'k', 'l'}},
        {'6', {'m', 'n', 'o'}}, {'7', {'p', 'q', 'r', 's'}},
        {'8', {'t', 'u', 'v'}}, {'9', {'w', 'x', 'y', 'z'}},
    };

    vector<string> res;
    string cur;
    backtrack(digits, phone, 0, cur, res);
    return res;
  }

private:
  void backtrack(const string &digits,
                 const unordered_map<char, vector<char>> &phone, int length,
                 string &cur, vector<string> &res) {
    // push_back() use copy
    if (length == digits.length()) {
      res.push_back(cur);
    } else {
      for (const char letter : phone.at(digits[length])) {
        cur.push_back(letter);
        backtrack(digits, phone, length + 1, cur, res);
        cur.pop_back();
      }
    }
  }
};

class Solution3 {
public:
  vector<string> letterCombinations(string digits) {
    if (digits.empty())
      return {};

    unordered_map<char, vector<char>> phone;
    phone = {
        {'0', {' '}},           {'1', {}},
        {'2', {'a', 'b', 'c'}}, {'3', {'d', 'e', 'f'}},
        {'4', {'g', 'h', 'i'}}, {'5', {'j', 'k', 'l'}},
        {'6', {'m', 'n', 'o'}}, {'7', {'p', 'q', 'r', 's'}},
        {'8', {'t', 'u', 'v'}}, {'9', {'w', 'x', 'y', 'z'}},
    };

    vector<string> res;
    string cur;
    backtrack(digits, phone, cur, res);
    return res;
  }

private:
  void backtrack(const string &digits,
                 const unordered_map<char, vector<char>> &phone, string &cur,
                 vector<string> &res) {
    // push_back() use copy
    if (digits.length() == 0) {
      res.push_back(cur);
    } else {
      for (const char letter : phone.at(digits[0])) {
        cur.push_back(letter);
        backtrack(digits.substr(1), phone, cur, res);
        cur.pop_back();
      }
    }
  }
};

int main() {
  auto digits1 = "23"s;
  auto digits2 = ""s;
  auto digits3 = "2"s;

  Solution sol;
  auto res1 = sol.letterCombinations(digits1);
  auto res2 = sol.letterCombinations(digits2);
  auto res3 = sol.letterCombinations(digits3);

  cout << "[";
  for (auto i = 0; i < res1.size(); ++i) {
    if (i == res1.size() - 1)
      cout << res1[i];
    else
      cout << res1[i] << ", ";
  }
  cout << "]";
  cout << endl;

  cout << "[";
  for (auto i = 0; i < res2.size(); ++i) {
    if (i == res2.size() - 1)
      cout << res2[i];
    else
      cout << res2[i] << ", ";
  }
  cout << "]";
  cout << endl;

  cout << "[";
  for (auto i = 0; i < res3.size(); ++i) {
    if (i == res3.size() - 1)
      cout << res3[i];
    else
      cout << res3[i] << ", ";
  }
  cout << "]";
  cout << endl;

  Solution3 sol3;
  auto ress = sol3.letterCombinations(digits1);

  return 0;
}