/*
https://leetcode.com/problems/two-sum/
*/
#include <iostream>
#include <vector>
#include <map>
using namespace std;

// The solution class
class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        // create a map and initialize indices
        map<int, int> compDict;
        map<int, int>::iterator it;

        // loop over number of elements in the nums
        for (auto i = 0; i < nums.size(); ++i)
        {
            // get the difference between the current element and target value
            auto x = target - nums[i];
            // check if the map contains the current element as a key
            it = compDict.find(nums[i]);
            // if the key is in the map then update the indices
            if (it != compDict.end())
            {
                return {compDict[nums[i]], i};
            }
            // otherwise store the key and value in the map
            else
            {
                compDict[x] = i;
            }
        }
    }
};

int main()
{
    // class object
    Solution sol;

    // test cases
    vector<vector<int>> nums{{2, 7, 11, 15},
                             {3, 2, 4},
                             {3, 3}};
    vector<int> target{9, 6, 6};

    // loop over number of test cases
    for (auto i = 0; i < nums.size(); ++i)
    {
        auto res = sol.twoSum(nums[i], target[i]);
        cout << "res: [" << res[0] << ", " << res[1] << "]" << endl;
    }
    return 0;
}