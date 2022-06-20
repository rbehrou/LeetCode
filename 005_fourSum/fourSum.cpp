/*
https://leetcode.com/problems/4sum/
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// The solution class
class Solution
{
public:
    vector<vector<int>> fourSum(vector<int> &nums, int target)
    {
        // sort the list
        sort(nums.begin(), nums.end());

        // call kSum function
        auto res = kSum(nums, target, 4, 0);

        // return the results
        return res;
    }

    // a helper slice vector
    vector<int> slice(vector<int> const &v, int m, int n)
    {
        auto first = v.cbegin() + m;
        auto last = v.cbegin() + n + 1;

        vector<int> vec(first, last);
        return vec;
    }

    // recursion on kSum function
    vector<vector<int>> kSum(vector<int> &nums, int target, int k, int start)
    {
        // initialize and get the length of the vector
        auto length = nums.size();
        vector<vector<int>> res;

        // if it is the last item
        if (start == length)
            return res;

        // return
        if (nums[start] > (target / k) || (target / k) > nums.back())
        {
            return res;
        }

        // call twoSum if k == 2
        if (k == 2)
        {
            return twoSum(nums, target, start);
        }

        // loop over number of elements in the list
        for (auto i = start; i < length; ++i)
        {
            // apply recursion
            if (i == start or nums[i] != nums[i - 1])
            {
                // slice vector
                vector<int> sub_vec = slice(nums, i + 1, length - 1);
                for (auto res_k : kSum(nums, target - nums[i], k - 1, i + 1))
                {
                    res.push_back({nums[i]});
                    res.back().insert(end(res.back()), begin(res_k), end(res_k));
                }
            }
        }

        // return the results
        return res;
    }

    // twoSum function with two pointers
    // ref: https://www.geeksforgeeks.org/two-pointers-technique/
    vector<vector<int>> twoSum(vector<int> &nums, int target, int start)
    {
        // initialize result
        vector<vector<int>> res;

        // initialize left and right pointer
        auto left = start;
        auto right = nums.size() - 1;

        // start with the two pointers
        while (left < right)
        {
            // compute the current value
            auto x = nums[left] + nums[right];
            // because it is sorted array, if x < target then move the left pointer
            if ((x < target) || (left > start && nums[left] == nums[left - 1]))
            {
                left++;
            }
            // because it is sorted array, if x > target then move the right pointer
            else if ((x > target) || (right < (nums.size() - 1) && nums[right] == nums[right + 1]))
            {
                right--;
            }
            else
            {
                // it is the solution and store the results
                res.push_back({nums[left], nums[right]});

                // update left and right pointer
                left++;
                right--;
            }
        }
        // return the solution
        return res;
    }
};

int main()
{
    // class object
    Solution sol;

    // test cases
    vector<vector<int>> nums{{1, 0, -1, 0, -2, 2},
                             {2, 2, 2, 2, 2}};
    vector<int> target{0, 8};
    // loop over number of test cases
    for (auto i = 0; i < nums.size(); ++i)
    {
        auto res = sol.fourSum(nums[i], target[i]);
        if (res.size() != 0)
        {
            cout << "res: [" << endl;
            for (auto j = 0; j < res.size(); ++j)
            {
                cout << "[" << res[j][0] << ", " << res[j][1] << ", " << res[j][2] << ", " << res[j][3] << "]" << endl;
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