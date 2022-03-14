"""
https://leetcode.com/problems/4sum/
"""
from typing import List

class Solution:
    def fourSum(self, nums: List[int], target: int) -> List[List[int]]:

        # recursion on kSum function
        def kSum(nums: List[int], target: int, k: int) -> List[List[int]]:
            
            # default return
            if not nums: return []
            
            # call twoSum if k == 2
            if k == 2:
                return twoSum(nums, target)
            
            # check for the smallest and largest value in the list (sorted list)
            if (target // k) < nums[0] or (target // k) > nums[-1]:
                return []
            
            # initialize
            res = []
            
            # loop over number of elements in the list
            for i in range(len(nums)):
                # recursion
                if (i == 0 or nums[i] != nums[i - 1]):
                    for x in kSum(nums[i + 1:], target - nums[i], k - 1):
                        res.append([nums[i]] + x)
            
            # return the results
            return res
        
        # call twoSum
        def twoSum(nums: List[int], target: int) -> List[int]:
            
            # default return
            if not nums: return []
            
            # initialize
            res = []
            left = 0
            right  = len(nums) - 1
            
            # start with the two pointers
            while left < right:
                x = nums[left] + nums[right]
                if (x < target) or (left > 0 and nums[left] == nums[left - 1]):
                    left  = left + 1
                elif (x > target) or (right < len(nums)-1 and nums[right] == nums[right + 1]):
                    right  = right - 1
                else:
                    res.append([nums[left], nums[right]])
                    # update left and right pointer
                    left  = left + 1
                    right = right - 1
                    
            return res
        
        # sort the list
        nums.sort()
        
        # call kSum function
        return kSum(nums, target, 4)
                    
def main():
    # call the solution class                
    sol = Solution()
    # test cases
    nums_test_cases = [
        [1,0,-1,0,-2,2],
        [2, 2, 2, 2, 2]
    ]
    target_test_cases = [0, 8]
    # loop over number of test cases
    for i in range(len(nums_test_cases)):
        # print response
        print(sol.fourSum(nums_test_cases[i], target_test_cases[i]))

if __name__ == '__main__':
    main()    