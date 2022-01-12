#include <vector>
#include <iostream>
#include <unordered_map>

using namespace std;

class Solution
{
public:
    vector<int> findAnagrams(string s, string p)
    {
        auto ns = s.length();
        auto np = p.length();
        unordered_map<char, int> wordP;
        unordered_map<char, int> wordS;
        vector<int> res;

        for (auto i = 0; i != np; ++i)
        {
            wordP[p[i]] += 1;
        }

        for (auto i = 0; i != ns; ++i)
        {
            wordS[s[i]] += 1;

            if (i >= np)
            {
                if (wordS[s[i - np]] == 1)
                {
                    wordS.erase(s[i - np]);
                }
                else
                {
                    wordS[s[i - np]] -= 1;
                }
            }
            if (wordP == wordS)
            {
                res.push_back(i - np + 1);
            }
        }
        return res;
    }
};

class Solution2
{
public:
    vector<int> findAnagrams(string s, string p)
    {
        int n = s.length();
        int l = p.length();
        vector<int> ans;
        vector<int> vp(26, 0);
        vector<int> vs(26, 0);
        for (char c : p)
            ++vp[c - 'a'];
        for (int i = 0; i < n; ++i)
        {
            if (i >= l)
                --vs[s[i - l] - 'a'];
            ++vs[s[i] - 'a'];
            if (vs == vp)
                ans.push_back(i + 1 - l);
        }
        return ans;
    }
};

/*
Approach 2: Sliding Window
Time Complexity: O(len(s) + len(p))
Space Complexity: O(1)
*/

int main()
{
    Solution sol;
    string s1 = "cbaebabacd";
    string p1 = "abc";

    auto res1 = sol.findAnagrams(s1, p1);
    for_each(res1.begin(), res1.end(), [&](int e)
             { cout << e << " "; });
    cout << endl;

    s1 = "abab";
    p1 = "ab";
    res1 = sol.findAnagrams(s1, p1);
    for_each(res1.begin(), res1.end(), [&](int e)
             { cout << e << " "; });

    return 0;
}