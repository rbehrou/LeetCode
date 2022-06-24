/*
https://leetcode.com/problems/counting-bits/
*/
#include <iostream>
#include <vector>
#include <map>

using namespace std;

// The solution class
class Solution
{
private:
    int countBitsRecursive(int n)
    {
        // base case
        if (n / 2 == 0)
            return n;

        // initialize
        auto rem = n % 2;
        // get the reminder
        rem += countBitsRecursive(n / 2);
        // return final number of 1's
        return rem;
    }

public:
    vector<int> countBits(int n)
    {
        // base case
        if (n == 0)
            return {0};

        // intialize
        vector<int> res(n + 1);
        for (auto i = 0; i <= n; ++i)
        {
            res[i] = countBitsRecursive(i);
        }

        // return final vector
        return res;
    }

    vector<int> countBitsDPBottomUp(int n)
    {
        // intialize
        vector<int> res(n + 1, 0);
        for (auto i = 0; i <= n; ++i)
        {
            auto val = i;
            while (val != 0)
            {
                res[i] += val % 2;
                val /= 2;
            }
        }

        // return final vector
        return res;
    }
};

int main()
{
    // class object
    Solution sol;

    auto res_rcr = sol.countBits(100);
    auto res_dp = sol.countBitsDPBottomUp(100);

    if (res_rcr == res_dp)
    {
        std::cout << "PASS: The results of two implementation match. " << std::endl;
    }
    else
    {
        std::cout << "ERROR: The results of two implementation don't match. " << std::endl;
    }

    // return
    return 0;
}