"""
https://leetcode.com/problems/palindrome-number/
"""

from typing import List

class Solution:
    def isPalindrome(self, x: int) -> bool:
        # a simple one line solution with converting integer to string
        # return (str(x)[::-1]) == str(x)
        
        # solution without converting the integer to a string
        # return false if the input is negative
        if (x < 0):
            return False

        # initialize to zero (it has to unsigned long integer)
        rev_x = 0
        # save the input
        x_new = x
        while (x_new != 0):
            # get the reminder
            rem = x_new % 10
            # update the reversed x
            rev_x = rev_x * 10 + rem
            # update x_new by dividing by 10
            x_new //= 10
        # check if the reveresed x is the same as the input
        if (x == rev_x):
            return True
        # otherwise return false
        return False

def main():
    # call the solution class                
    sol = Solution()
    # test cases
    nums = [121, -121, 10, 44, 898, 0, pow(-2,31), pow(2,31) - 1]

    # loop over number of test cases
    for i in nums:
        # print the solution
        print("The output is: ", sol.isPalindrome(i))

if __name__ == '__main__':
    main()