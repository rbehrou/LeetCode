"""
https://leetcode.com/problems/two-sum-iii-data-structure-design/
"""
from typing import List

class TwoSum:

    def __init__(self):
        
        # create a dictionary
        self.compDict = {}
        
    def add(self, number: int) -> None:
        
        # if the key is in the map then update the indices by +1
        if number in self.compDict:
            self.compDict[number] += 1
        # otherwise store the key and the new value in the map
        else:
            self.compDict[number] = 1
            
    def find(self, value: int) -> bool:
        
        # loop over number of elements in the map
        for key, val in self.compDict.items():
            # compute the difference between the current value and the key in item
            diff = value - key
            # if the diff is not the same as the key in the item
            if (diff != key):
                # if the diff is in the map then return true
                if (diff in self.compDict):
                    return True
            # also if the value is greater than one then then value is in the map
            elif (val > 1):
                return True
            
        # otherwise
        return False
        

# Your TwoSum object will be instantiated and called as such:
# obj = TwoSum()
# obj.add(number)
# param_2 = obj.find(value)

def main():

    # call class object
    two_sum = TwoSum()

    # test cases
    # Add [1],[3],[5]
    two_sum.add(1)
    two_sum.add(3)
    two_sum.add(5)

    # find [4] and [7]
    res1 = two_sum.find(4)
    print("result 1: ", res1) # should return True
    res2 = two_sum.find(7)
    print("result 2: ", res2) # should return False

if __name__ == '__main__':
    main()