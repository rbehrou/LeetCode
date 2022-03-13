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

# call the solution class                
sol = Solution()

# test case
nums = [2, 7, 11, 15]
target = 9

# print response
res = sol.twoSum(nums,target)
print(res)

