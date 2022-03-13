/*
https://leetcode.com/problems/3sum/
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// The solution class
class Solution
{
public:
    vector<vector<int>> threeSum(vector<int> &nums)
    {
        // step 1: initialize
        vector<vector<int>> res;

        // step 2: return empty if the vector is empty
        if (nums.size() == 0)
            return res;
        auto length = nums.size();

        // step 3: sort the list in ascending order
        // ex: [-1, 0, 1, 2, -1, -4] --> [-4, -1, -1, 0, 1, 2]
        sort(nums.begin(), nums.end());

        // step 4: work with two sliding windows from left and right
        for (auto i = 0; i < length - 1; ++i) // ex: 6-2 = 4
        {
            // we take care of duplication here
            if (i > 0 and nums[i] == nums[i - 1])
                continue;            // ex: at i = 2
            auto left = i + 1;       // ex: left=1(@i=0), left=2(@i=1), ...
            auto right = length - 1; // ex: right=5

            while (left < right) // ex: 1 < 5
            {
                // compute the total, ex: nums[0] + nums[1] + nums[5] = -3
                auto total = nums[i] + nums[left] + nums[right];
                if (total < 0)
                {
                    // increase left, ex: left = 2
                    left++;
                }
                else if (total > 0)
                {
                    // decrease right
                    right--;
                }
                else
                {
                    // otherwise it is a solution
                    res.push_back({nums[i], nums[left], nums[right]});
                        // check if nums[left] == nums[left + 1]
                        while (left < right && nums[left] == nums[left + 1])
                    {
                        // increase left
                        left++;
                    }
                    // check if nums[right] == nums[right - 1]
                    while (left < right && nums[right] == nums[right - 1])
                    {
                        // decrease right
                        right--;
                    }
                    // otherwise increase left and decrease right
                    left++;
                    right--;
                }
            }
        }

        // return results
        return res;
    }
};

int main()
{
    // class object
    Solution sol;

    // test cases
    vector<vector<int>> nums{{-1, 0, 1, 2, -1, -4},
                             {},
                             {0}};
    // loop over number of test cases
    for (auto i = 0; i < nums.size(); ++i)
    {
        auto res = sol.threeSum(nums[i]);
        if (res.size() != 0)
        {
            cout << "res: [" << endl;
            for (auto j = 0; j < res.size(); ++j)
            {
                cout << "[" << res[j][0] << ", " << res[j][1] << ", " << res[j][2] << "]" << endl;
            }
            cout << "]" << endl;
        }
        else
        {
            cout << "[]" << endl;
        }
    }
    return 0;
}