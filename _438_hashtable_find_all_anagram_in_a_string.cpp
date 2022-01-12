#include <vector>
#include <iostream>

using namespace std;

class Solution
{
public:
    vector<int> findAnagrams(string s, string p)
    {
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
Time Complexity:
Space Complexity:
*/

int main()
{

    return 0;
}