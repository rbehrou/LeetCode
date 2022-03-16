"""
https://leetcode.com/problems/3sum/
"""
from typing import List

class Solution:
    def threeSum(self, nums: List[int]) -> List[List[int]]:
        # step 1: return empty if the list is empty
        if (len(nums) == 0): return []
        
        # step 2: sort the list in ascending order
        # ex: [-1, 0, 1, 2, -1, -4] --> [-4, -1, -1, 0, 1, 2]        
        nums.sort()
        
        # step 3: initialize
        length = len(nums)  # ex: length = 6
        res = []
        
        # step 4: work with two sliding windows from left and right
        for i in range(length - 2): # ex: 6-2 = 4
            # we take care of duplication here
            if i > 0 and nums[i] == nums[i - 1]:
                continue  # ex: at i = 2
            left = i + 1  # ex: left=1(@i=0), left=2(@i=1), ... 
            right = length - 1 # ex: right=5
            
            while left < right: # ex: 1 < 5
                # compute the total, ex: nums[0] + nums[1] + nums[5] = -3
                total = nums[i] + nums[left] + nums[right]
                if total < 0:
                    # increase left, ex: left = 2
                    left = left + 1
                elif total > 0:
                    # decrease right
                    right = right - 1
                else:
                    # otherwise it is a solution
                    res.append([nums[i], nums[left], nums[right]])
                    # check if nums[left] == nums[left + 1]
                    while left < right and nums[left] == nums[left + 1]:
                        # increase left
                        left = left + 1
                    # check if nums[right] == nums[right - 1]
                    while left < right and nums[right] == nums[right - 1]:
                        # decrease right
                        right = right - 1
                    
                    # otherwise increase left and decrease right
                    left  = left + 1
                    right = right - 1
        # return results            
        return res
                    
def main():
    # call the solution class                
    sol = Solution()
    # test cases
    nums_test_cases = [
        [-1,0,1,2,-1,-4],
        [],
        [0]
    ]
    # loop over number of test cases
    for i in range(len(nums_test_cases)):
        # print response
        print(sol.threeSum(nums_test_cases[i]))

if __name__ == '__main__':
    main()    