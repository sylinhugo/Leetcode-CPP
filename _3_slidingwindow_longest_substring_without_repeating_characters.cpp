#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

// Sliding Window (Leetcode)
// O(2n)
class Solution {
public:
  int lengthOfLongestSubstring(string s) {
    vector<int> chars(128);

    int left = 0;
    int right = 0;

    int res = 0;
    while (right < s.length()) {
      char r = s[right];
      chars[r]++;

      while (chars[r] > 1) {
        char l = s[left];
        chars[l]--;
        left++;
      }

      res = max(res, right - left + 1);

      right++;
    }

    return res;
  }
};

// Sliding Window Optimized (Leetcode)
// O(n)
class Solution2 {
public:
  int lengthOfLongestSubstring(string s) {
    const int n = s.length();
    int ans = 0;
    unordered_map<char, int> hashMap;

    for (auto j = 0, i = 0; j < n; ++j) {
      if (hashMap.count(s[j])) {
        i = max(hashMap[s[j]], i);
      }
      ans = max(ans, j - i + 1);
      hashMap[s[j]] = j + 1;
    }

    return ans;
  }
};

// hashTable + Sliding Window (Hua Hua)
// Time: O(n), Space: O(128)
class Solution3 {
public:
  int lengthOfLongestSubstring(string s) {
    const int n = s.length();
    int ans = 0;
    vector<int> idx(128, -1);

    for (int i = 0, j = 0; j < n; ++j) {
      i = max(i, idx[s[j]] + 1);
      ans = max(ans, j - i + 1);
      idx[s[j]] = j;
    }

    return ans;
  }
};

// HashTable + Sliding Window (Leetcode)
// Time: O(n), Space: O(128)
class Solution4 {
public:
  int lengthOfLongestSubstring(string s) {
    // we will store a senitel value of -1 to simulate 'null'/'None' in C++
    vector<int> chars(128, -1);

    int left = 0;
    int right = 0;

    int res = 0;
    while (right < s.length()) {
      char r = s[right];

      int index = chars[r];
      if (index != -1 and index >= left and index < right) {
        left = index + 1;
      }
      res = max(res, right - left + 1);

      chars[r] = right;
      right++;
    }
    return res;
  }
};

/**
 * @brief
 * sol3 is better than sol4, although hashMap would be O(1) access;
 * however, it is under amortized scenario, in some edgs case it may not be
 * O(1), by the way, we really don't need the feature of map in this question,
 * so just use vector!
 *
 * @return int
 */
int main() {
  Solution sol;
  Solution2 sol2;
  Solution3 sol3;
  Solution4 sol4;
  string s = "abcabcbb";

  auto res1 = sol.lengthOfLongestSubstring(s);
  auto res2 = sol2.lengthOfLongestSubstring(s);
  auto res3 = sol3.lengthOfLongestSubstring(s);
  auto res4 = sol4.lengthOfLongestSubstring(s);

  cout << res1 << endl;
  cout << res2 << endl;
  cout << res3 << endl;
  cout << res4;

  return 0;
}