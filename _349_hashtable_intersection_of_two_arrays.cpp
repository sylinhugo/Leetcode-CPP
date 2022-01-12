#include <vector>
#include <unordered_set>
#include <iostream>

using namespace std;

class Solution
{
public:
    vector<int> intersection(vector<int> &nums1, vector<int> &nums2)
    {
        unordered_set<int> m(nums1.begin(), nums1.end());
        vector<int> ans;
        for (int num : nums2)
        {
            if (!m.count(num))
                continue;
            ans.push_back(num);
            m.erase(num);
        }
        return ans;
    }
};

/*
Time Complexity: O(n)
Space Complexity: O(n)
*/

int main()
{
    Solution sol;
    vector<int> nums1 = {1, 2, 2, 1};
    vector<int> nums2 = {2, 2};

    auto res1 = sol.intersection(nums1, nums2);
    for_each(res1.begin(), res1.end(), [&](const auto &e)
             { cout << e << " "; });
    cout << endl;

    nums1 = {4, 9, 5};
    nums2 = {9, 4, 9, 8, 4};
    res1 = sol.intersection(nums1, nums2);
    for_each(res1.begin(), res1.end(), [&](const auto &e)
             { cout << e << " "; });

    return 0;
}