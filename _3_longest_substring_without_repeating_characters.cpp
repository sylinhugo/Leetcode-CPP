#include <string>
#include <iostream>
#include <vector>

using std::max;
using std::string;
using std::vector;

class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        vector<int> chars(128);

        int left = 0;
        int right = 0;

        int res = 0;
        while (right < s.length())
        {
            char r = s[right];
            chars[r]++;

            while (chars[r] > 1)
            {
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

/*
Approach 1: Sliding Window
Time Complexity: O(n)
Space Complxity: O(1)
*/

int main()
{
    Solution sol;
    string input1 = "abcabcbb";
    string input2 = "pwwkew";

    auto res1 = sol.lengthOfLongestSubstring(input1);
    auto res2 = sol.lengthOfLongestSubstring(input2);

    std::cout << res1 << std::endl; // 3
    std::cout << res2 << std::endl; // 3

    return 0;
}