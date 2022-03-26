/*
https://leetcode.com/problems/palindrome-number/
*/
#include <iostream>
#include <vector>
#include <map>
#include <climits>
using namespace std;

// The solution class
class Solution
{
public:
    bool isPalindrome(int x)
    {
        // return false if the input is negative
        if (x < 0)
            return false;

        // initialize to zero (it has to unsigned long integer)
        unsigned long int rev_x{0};
        // save the input
        auto x_new = x;
        while (x_new != 0)
        {
            // get the reminder
            auto rem = x_new % 10;
            // update the reversed x
            rev_x = rev_x * 10 + rem;
            // update x_new by dividing by 10
            x_new /= 10;
        }
        // check if the reveresed x is the same as the input
        if (x == rev_x)
            return true;
        // otherwise return false
        return false;
    }
};

int main()
{
    // class object
    Solution sol;

    // test cases
    vector<int> nums{121, -121, 10, 44, 898, 0, INT_MIN, INT_MAX};

    // loop over number of test cases
    for (auto i = 0; i < nums.size(); ++i)
    {
        auto res = sol.isPalindrome(nums[i]);
        cout << "The output is: " << res << endl;
    }
    return 0;
}