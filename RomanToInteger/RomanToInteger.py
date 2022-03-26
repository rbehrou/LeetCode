"""
https://leetcode.com/problems/roman-to-integer/
"""

from typing import List

class Solution:
    def romanToInt(self, s: str) -> int:
        # create dictionary from Roman symbols
        map_table = {}
        map_table["I"] = 1
        map_table["V"] = 5
        map_table["X"] = 10
        map_table["L"] = 50
        map_table["C"] = 100
        map_table["D"] = 500
        map_table["M"] = 1000
        
        # initialize the result
        res = 0
        # loop over number of elements in the string
        for i in range(len(s)):
            # subtract the smaller one when the smaller symbol is before the larger symbol
            if i + 1 < len(s) and map_table[s[i]] < map_table[s[i + 1]]:
                res -= map_table[s[i]]
            else:
                # add the larger one, otherwise
                res += map_table[s[i]]
        return res

def main():
    # call the solution class                
    sol = Solution()
    # test cases
    nums = ["III", "LVIII", "MCMXCIV"]
    target = [3, 58, 1994]

    # loop over number of test cases
    for i in range(len(nums)):
        # print the solution
        res = sol.romanToInt(nums[i])
        if (res == target[i]):
            print("The output is:", res, "that matches the target value:", target[i])
        else:
            print("Error in matching the output to the target value!")

if __name__ == '__main__':
    main()