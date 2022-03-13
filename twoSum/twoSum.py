"""
https://leetcode.com/problems/two-sum/
"""

class Solution:
    def twoSum(self, nums, target):
        # create a dictionary
        compDict = dict()
        
        # loop over number of elements in list
        for i in range(len(nums)):
            # compute the difference between target and current element in list
            x = target - nums[i]
            # if current element is in table, then return index of current element from table and i
            if nums[i] in compDict:
                return [compDict[nums[i]], i]
            else:
                # otherwise store the difference in the dictionary
                compDict[x] = i

def main():
    # call the solution class                
    sol = Solution()
    # test cases
    nums_test_cases = [
        [2, 7, 11, 15],
        [3, 2, 4],
        [3, 3]
    ]
    target_test_cases = [9, 6, 6]
    # loop over number of test cases
    for i in range(len(nums_test_cases)):
        # print response
        print(sol.twoSum(nums_test_cases[i],target_test_cases[i]))

if __name__ == '__main__':
    main()