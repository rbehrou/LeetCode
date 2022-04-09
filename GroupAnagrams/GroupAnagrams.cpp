/*
https://leetcode.com/problems/group-anagrams/
*/
#include <iostream>
#include <vector>
#include <map>
using namespace std;

// The solution class
class Solution
{
public:
    string intToRoman(int num)
    {
        // create vectors of numbers and symbols
        vector<string> map_str{"I", "IV", "V", "IX", "X", "XL", "L", "XC", "C", "CD", "D", "CM", "M"};
        vector<int> map_int{1, 4, 5, 9, 10, 40, 50, 90, 100, 400, 500, 900, 1000};

        // initialize
        string res;
        // loop over number of keys and val in the reversed dictionary
        // reason: going from the highest to smallest
        for (int i = map_int.size() - 1; i >= 0; i--)
        {
            // floor division (if it is not zero)
            if (num / map_int[i])
            {
                // get the count
                auto count = num / map_int[i];
                // then mutiply key by the count and add to the residual
                for (int j = 0; j < count; j++)
                {
                    res += map_str[i];
                }
                // update number (divide and store the reminder for the next step)
                num = num % map_int[i];
            }
        }
        // return result
        return res;
    }
};

int main()
{
    // class object
    Solution sol;

    // test cases
    vector<int> nums{3, 58, 1994};
    vector<string> target{"III", "LVIII", "MCMXCIV"};

    // loop over number of test cases
    for (auto i = 0; i < nums.size(); ++i)
    {
        auto res = sol.intToRoman(nums[i]);
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