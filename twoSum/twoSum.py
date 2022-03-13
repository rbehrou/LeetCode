def twoSum(nums, target):
    # create a dictionary
    compDict = dict()
    res = []
    
    # loop over number of elements in list
    for i in range(len(nums)):
        # compute the difference between target and current element in list
        x = target - nums[i]
        # if current element is in table, then return index of current element from table and i
        if nums[i] in compDict:
            res.append(compDict[nums[i]])
            res.append(i)
        else:
            # otherwise store the difference in the dictionary
            compDict[x] = i
    # return the result
    return res

# test case
nums = [2, 7, 11, 15]
target = 9

# print response
res = twoSum(nums,target)
print(res)

