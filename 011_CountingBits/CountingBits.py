"""
https://leetcode.com/problems/counting-bits/
"""

from typing import List

class Solution:
    def countBits(self, n: int) -> List[int]:

        def countBitsRecursive(n):
            # base case (quotient)
            if (n // 2 == 0):
                return n

            # get the reminder
            rem = n % 2
            
            # recursion over the reminder
            rem += countBitsRecursive(n // 2)
            
            # return final number of 1's
            return rem
    
        # intialize
        res = [0] * (n+1)
        
        # loop over number of n
        for i in range(n+1):
            res[i] = countBitsRecursive(i)

        # return final vector
        return res

    def countBitsDPBottomUp(self, n: int) -> List[int]:
        # intialize
        res = [0] * (n + 1)

        # loop over n
        for i in range(n+1):
            val = i
            while (val != 0):
                res[i] += val % 2
                val //= 2

        # return the final vector
        return res

def main():
    # call the solution class                
    sol = Solution()

    res_rcr = sol.countBits(100)
    res_dp = sol.countBitsDPBottomUp(100)

    if (res_rcr == res_dp):
        print("PASS: The results of two implementation match.")
    else:
        print("ERROR: The results of two implementation don't match.")

if __name__ == '__main__':
    main()