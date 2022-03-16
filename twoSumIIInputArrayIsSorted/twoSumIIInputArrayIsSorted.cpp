/*
https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/
*/
#include <iostream>
#include <vector>
#include <map>
using namespace std;

// The solution class
class Solution
{
public:
    vector<int> twoSum(vector<int> &numbers, int target)
    {
        // create a map and initialize indices
        map<int, int> compDict;
        map<int, int>::iterator it;
        vector<int> res{-1, -1};

        // loop over number of elements in the nums
        for (auto i = 0; i < numbers.size(); ++i)
        {
            // get the difference between the current element and target value
            auto x = target - numbers[i];
            // check if the map contains the current element as a key
            it = compDict.find(numbers[i]);
            // if the key is in the map then update the indices
            if (it != compDict.end())
            {
                res[0] = compDict[numbers[i]] + 1;
                res[1] = i + 1;
            }
            // otherwise store the key and value in the map
            else
            {
                compDict[x] = i;
            }
        }

        // return indices
        return res;
    }
};

int main()
{
    // class object
    Solution sol;

    // test cases
    vector<vector<int>> nums{{2, 7, 11, 15},
                             {2, 3, 4},
                             {-1, 0}};
    vector<int> target{9, 6, -1};

    // loop over number of test cases
    for (auto i = 0; i < nums.size(); ++i)
    {
        auto res = sol.twoSum(nums[i], target[i]);
        cout << "res: [" << res[0] << ", " << res[1] << "]" << endl;
    }
    return 0;
}