"""
https://leetcode.com/problems/integer-to-roman/
"""

from typing import List

class Solution:
    def intToRoman(self, num: int) -> str:
        # create dictionary from Roman symbols
        map_table = [["I", 1],
                     ["IV", 4],
                     ["V", 5],
                     ["IX", 9],
                     ["X", 10],
                     ["XL", 40],
                     ["L", 50],
                     ["XC", 90],
                     ["C", 100],
                     ["CD", 400],
                     ["D", 500],
                     ["CM", 900],
                     ["M", 1000]]
        
        # initialize
        res = ""
        # loop over number of keys and val in the reversed dictionary
        # reason: going from the highest to smallest
        for key, val in reversed(map_table):
            # floor division (if it is not zero)
            if num // val:
                # get the count
                count = num // val
                # then mutiply key by the count and add to the residual
                res += key * count
                # update number (divide and store the reminder for the next step)
                num = num % val
        
        # return result
        return res

def main():
    # call the solution class                
    sol = Solution()
    # test cases
    nums = [3, 58, 1994]
    target = ["III", "LVIII", "MCMXCIV"]

    # loop over number of test cases
    for i in range(len(nums)):
        # print the solution
        res = sol.intToRoman(nums[i])
        if (res == target[i]):
            print("The output is:", res, "that matches the target value:", target[i])
        else:
            print("Error in matching the output to the target value!")

if __name__ == '__main__':
    main()