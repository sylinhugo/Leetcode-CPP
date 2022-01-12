#include <string>
#include <iostream>
#include <map>

using namespace std;

class Solution
{
public:
    int romanToInt(string s)
    {
        map<char, int> m{{'I', 1}, {'V', 5}, {'X', 10}, {'L', 50}, {'C', 100}, {'D', 500}, {'M', 1000}};
        int ans = 0;
        for (int i = 0; i < s.length(); i++)
        {
            ans += m[s[i]];
            if (i > 0 && m[s[i]] > m[s[i - 1]])
                ans -= 2 * m[s[i - 1]];
        }
        return ans;
    }
};

/*
Time Complexity: O(n)
Space Complexity: O(1)
*/

int main()
{
    Solution sol;
    auto input1 = "LVIII";

    auto res1 = sol.romanToInt(input1);

    cout << res1 << endl;
    return 0;
}