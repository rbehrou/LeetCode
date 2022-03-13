#include <iostream>
#include <vector>
#include <map>
using namespace std;

// The solution class
class Solution
{
public:
    vector<int> twoSum(vector<int>& nums, int target) 
    {
        // create a map and initialize indices
        map<int, int> compDict;
        map<int, int>::iterator it;
        vector<int> res{-1, -1};
        
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
                res[0] = compDict[nums[i]];
                res[1] = i;
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
    
    // test case
    vector<int> nums{2,7,11,15};
    auto target = 9;
    
    auto res = sol.twoSum(nums, target);
    
    cout << "res: [" << res[0] << ", " << res[1] << "]" << endl; 

    return 0;
}