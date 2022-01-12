
#include <vector>
#include <iostream>
#include <unordered_map>

using std::unordered_map;
using std::vector;

class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        std::unordered_map<int, int> record;
        std::vector<int> res;

        for (int i = 0, size = nums.size(); i != size; ++i)
        {
            auto tmp = target - nums[i];
            if (record.find(tmp) != record.end())
            {
                // std::cout << "record[tmp] is: " << record[tmp] << std::endl;
                res.emplace_back(record[tmp]);
                res.emplace_back(i);
                return res;
            }
            record[nums[i]] = i;
        }
        return res;
    }
};

class Solution0001
{
public:
    // Since C++20, use std::span<T> when passing containers
    // std::vector<int> twoSum(std::span<int> nums, int target) {
    std::vector<int> twoSum(std::vector<int> &nums, int target)
    {
        // Currently, clang does not support polymorphic memory resource library which is in C++17
        // std::array<std::byte, 2048> stack_buffer;
        // std::pmr::monotonic_buffer_resource pool { std::data(stack_buffer), std::size(stack_buffer) };
        // std::pmr::unordered_map<int, int> hash_map { &pool };

        std::unordered_map<int, int> hash_map;

        // Since C++20, we can initialize in range-based for loop
        for (int index = 0; auto num : nums)
        {
            // Since C++20, use contains() instead of find() for searching key
            // But contains() is not yet implemented in clang
            // if (hash_map.contains(target - num))
            //     return { hash_map.at(target - num), index };

            // For now, use init-statement in if statement (C++17)
            if (auto search = hash_map.find(target - num); search != hash_map.end())
                return {search->second, index};

            // Since C++17, we can use try_emplace instead of emplace
            // If a key already exists in the container, does nothing
            hash_map.try_emplace(num, index++);
        }

        return {};
    }
};

int main()
{
    Solution sol;
    std::vector<int> input = {2, 7, 11, 5};

    std::vector<int> res = sol.twoSum(input, 9);

    for (auto i = 0; i != res.size(); ++i)
    {
        std::cout << res[i];
    }
    std::cout << std::endl;

    std::cout << "The output is: " << res[0] << ", " << res[1] << std::endl;

    return 0;
}