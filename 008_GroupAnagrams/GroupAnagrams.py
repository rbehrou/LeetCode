"""
https://leetcode.com/problems/group-anagrams/
"""

from typing import List
from collections import defaultdict

class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        
        # create a lookup dictionary
        lookup = defaultdict(list)
        
        # loop over the string in the list
        for s in strs:
            # sort and join letters for the current string in the list
            key = "".join(sorted(list(s))) 
            # store the the letter (string) with key
            lookup[key].append(s)
        
        # initialize the result list
        res = []
        # loop over the lookup table
        for i in lookup.values():
            res.append(i)
        
        # return the results
        return res

def main():
    # call the solution class                
    sol = Solution()
    # test cases
    nums = [["eat","tea","tan","ate","nat","bat"],[""],["a"]]
    target = [[["bat"],["nat","tan"],["ate","eat","tea"]],[[""]],[["a"]]]

    # loop over number of test cases
    for i in range(len(nums)):
        # print the solution
        res = sol.groupAnagrams(nums[i])
        if (res.sort() == target[i].sort()):
            print("The output is:", res, "that matches the target value:", target[i])
        else:
            print("Error in matching the output to the target value!")

if __name__ == '__main__':
    main()