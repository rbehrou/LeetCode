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
    int romanToInt(string s)
    {
        // create dictionary from Roman symbols
        map<char, int> map_table;
        map_table['I'] = 1;
        map_table['V'] = 5;
        map_table['X'] = 10;
        map_table['L'] = 50;
        map_table['C'] = 100;
        map_table['D'] = 500;
        map_table['M'] = 1000;

        // initialize the result
        auto res = 0;
        // loop over number of elements in the string
        for (auto i = 0; i < s.size(); i++)
        {
            // subtract the smaller one when the smaller symbol is before the larger symbol
            if ((i + 1 < s.size()) && (map_table[s[i]] < map_table[s[i + 1]]))
            {
                res -= map_table[s[i]];
            }
            else
            // add the larger one, otherwise
            {
                res += map_table[s[i]];
            }
        }
        return res;
    }
};

int main()
{
    // class object
    Solution sol;

    // test cases
    vector<string> nums{"III", "LVIII", "MCMXCIV"};
    vector<int> target{3, 58, 1994};

    // loop over number of test cases
    for (auto i = 0; i < nums.size(); ++i)
    {
        auto res = sol.romanToInt(nums[i]);
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