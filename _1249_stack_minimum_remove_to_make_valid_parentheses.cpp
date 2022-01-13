#include <string>
#include <stack>

using namespace std;

class Solution
{
public:
    string minRemoveToMakeValid(string s)
    {
        int close = count(begin(s), end(s), ')');
        int open = 0;
        string ans;

        for (char c : s)
        {
            if (c == '(')
            {
                if (open == close)
                    continue;
                ++open;
            }
            else if (c == ')')
            {
                --close;
                if (open == 0)
                    continue;
                --open;
            }
            ans += c;
        }
        return ans;
    }
};

class Solution2
{
public:
    string minRemoveToMakeValid(string s)
    {
        stack<int> Stack;
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == '(')
            {
                Stack.push(i);
            }
            else if (s[i] == ')')
            {
                if (Stack.empty())
                    s[i] = ' ';
                else
                    Stack.pop();
            }
        }
        while (!Stack.empty())
        {
            s[Stack.top()] = ' ';
            Stack.pop();
        }
        string t;
        for (auto ch : s)
            if (ch != ' ')
                t.push_back(ch);

        return t;
    }
};

/*
Approach 1: Hua Hua
Time Complexity:
Space Complexity:

Approach 2: Every Day
Time Complexity:
Space Complexity:
*/

int main()
{

    return 0;
}