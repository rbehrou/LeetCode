/*
https://leetcode.com/problems/palindrome-number/
*/
#include <iostream>
#include <vector>
#include <map>
using namespace std;

// The solution class
class Solution
{
public:
    int trap(vector<int> &height)
    {
        // get the size fo the array
        auto size = height.size();

        // sort the array from left based on the max values
        // [0,1,0,2,1,0,1,3,2,1,2,1] -> [0,1,1,2,2,2,2,3,3,3,3,3]
        vector<int> max_left(size, 0);
        max_left[0] = height[0];
        for (auto i = 1; i < size; ++i) // from 1 to size-1
        {
            max_left[i] = max(height[i], max_left[i - 1]);
        }

        // sort the array from right based on the max values
        // [0,1,0,2,1,0,1,3,2,1,2,1] -> [3,3,3,3,3,3,3,3,2,2,2,1]
        vector<int> max_right(size, 0);
        max_right[size - 1] = height[size - 1];
        for (int i = size - 2; i >= 0; i--)
        {
            max_right[i] = max(height[i], max_right[i + 1]);
        }

        // max_left:      [0,1,1,2,2,2,2,3,3,3,3,3]
        // max_right:     [3,3,3,3,3,3,3,3,2,2,2,1]
        // min_lr:        [0,1,1,2,2,2,2,3,2,2,2,1]
        // height:        [0,1,0,2,1,0,1,3,2,1,2,1]
        // min_lr-height: [0,0,1,0,1,2,1,0,0,1,0,0]
        // sum(min_lr-height) = 6
        auto ans = 0;
        for (auto i = 1; i < size; ++i)
        {
            ans += min(max_left[i], max_right[i]) - height[i];
        }

        // return the result
        return ans;
    }
};

int main()
{
    // class object
    Solution sol;

    // test cases
    vector<vector<int>> nums = {{0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1},
                                {4, 2, 0, 3, 2, 5}};
    vector<int> target{6, 9};

    // loop over number of test cases
    for (auto i = 0; i < nums.size(); ++i)
    {
        auto res = sol.trap(nums[i]);
        if (res == target[i])
        {
            cout << "The output is: " << res << " that matches the target value: " << target[i] << endl;
        }
        else
        {
            cout << "Error in matching the output to the target value!" << endl;
        }
    }
    return 0;
}