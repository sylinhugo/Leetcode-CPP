#include <vector>
#include <unordered_set>

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

int main()
{

    return 0;
}