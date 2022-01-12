#include <vector>
#include <iostream>

using namespace std;

class Solution
{
public:
    vector<vector<int>> threeSum(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        auto n = nums.size();
        vector<vector<int>> res;

        if (n < 3)
            return {};

        for (auto i = 0; i != n - 2; ++i)
        {
            if (i != 0 && nums[i] == nums[i - 1])
                continue;

            int left, right;
            left = i + 1;
            right = nums.size() - 1;

            while (left < right)
            {
                auto tmp = nums[i] + nums[left] + nums[right];
                if (tmp > 0)
                    right -= 1;
                else if (tmp < 0)
                    left += 1;
                else
                {
                    res.push_back({nums[i], nums[left], nums[right]});
                    while (left < right && nums[left] == nums[left + 1])
                    {
                        left += 1;
                    }
                    while (left < right and nums[right - 1] == nums[right])
                    {
                        right -= 1;
                    }
                    left += 1;
                    right -= 1;
                }
            }
        }
        return res;
    }
};

/*
Approach 1: Two pointer
Time Complexity: O(n^2)
Space Complexity: O(nlogn) or O(n), depends on the implementation of sort
*/

int main()
{
    Solution sol;
    vector<int> input1 = {-1, 0, 1, 2, -1, -4};
    vector<int> input2 = {};
    vector<int> input3 = {0};

    auto res1 = sol.threeSum(input1);
    auto res2 = sol.threeSum(input2);
    auto res3 = sol.threeSum(input3);

    for (auto const &row : res1)
    {
        for (auto const &col : row)
        {
            std::cout << col << ' ';
        }
        std::cout.put('\n');
    }

    return 0;
}