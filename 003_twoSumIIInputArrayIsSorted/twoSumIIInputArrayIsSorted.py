"""
https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/
"""
from typing import List

class Solution:
    def twoSum(self, numbers: List[int], target: int) -> List[int]:
        # create a dictionary
        compDict = dict()
        
        # loop over number of elements in list
        for i in range(len(numbers)):
            # compute the difference between target and current element in list
            x = target - numbers[i]
            # if current element is in table, then return index of current element from table and i
            if numbers[i] in compDict:
                return [compDict[numbers[i]] + 1, i + 1]
            else:
                # otherwise store the difference in the dictionary
                compDict[x] = i

def main():
    # call the solution class                
    sol = Solution()
    # test cases
    nums_test_cases = [
        [2, 7, 11, 15],
        [2, 3, 4],
        [-1, 0]
    ]
    target_test_cases = [9, 6, -1]
    # loop over number of test cases
    for i in range(len(nums_test_cases)):
        # print response
        print(sol.twoSum(nums_test_cases[i],target_test_cases[i]))

if __name__ == '__main__':
    main()