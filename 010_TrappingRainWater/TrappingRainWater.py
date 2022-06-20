"""
https://leetcode.com/problems/trapping-rain-water/
"""

from typing import List

class Solution:
    def trap(self, height: List[int]) -> int:
        # get the size fo the array
        size = len(height)

        # sort the array from left based on the max values
        # [0,1,0,2,1,0,1,3,2,1,2,1] -> [0,1,1,2,2,2,2,3,3,3,3,3]
        max_left = [0] * size
        max_left[0] = height[0]
        for i in range(1, size): # from 1 to size-1
            max_left[i] = max(height[i], max_left[i - 1])
        
        # sort the array from right based on the max values
        # [0,1,0,2,1,0,1,3,2,1,2,1] -> [3,3,3,3,3,3,3,3,2,2,2,1]
        max_right = [0] * size
        max_right[size - 1] = height[size - 1]
        for i in range(size - 2, -1, -1): # from size - 2 to 0
            max_right[i] = max(height[i], max_right[i + 1])
            
        # max_left:      [0,1,1,2,2,2,2,3,3,3,3,3]
        # max_right:     [3,3,3,3,3,3,3,3,2,2,2,1]
        # min_lr:        [0,1,1,2,2,2,2,3,2,2,2,1]
        # height:        [0,1,0,2,1,0,1,3,2,1,2,1]
        # min_lr-height: [0,0,1,0,1,2,1,0,0,1,0,0] 
        # sum(min_lr-height) = 6
        ans = 0    
        for i in range(1, size-1):
            ans += min(max_left[i], max_right[i]) - height[i]
        
        # return the result
        return ans

def main():
    # call the solution class                
    sol = Solution()
    # test cases
    nums = [[0,1,0,2,1,0,1,3,2,1,2,1], [4,2,0,3,2,5]]
    target = [6, 9]

    # loop over number of test cases
    for i in range(len(nums)):
        # print the solution
        res = sol.trap(nums[i])
        if (res == target[i]):
            print("The output is:", res, "that matches the target value:", target[i])
        else:
            print("Error in matching the output to the target value!")

if __name__ == '__main__':
    main()