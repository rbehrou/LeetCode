/*
https://leetcode.com/problems/two-sum-iii-data-structure-design/
*/
#include <iostream>
#include <vector>
#include <map>
using namespace std;

class TwoSum
{
private:
    // create the map and iterator
    map<long, int> compDict;
    map<long, int>::iterator it;

public:
    // default constructor
    TwoSum()
    {
        // do nothing here
    }

    void add(int number)
    {
        // check if the map contains the current number as a key
        it = compDict.find(number);
        // if the key is in the map then update the indices by +1
        if (it != compDict.end())
        {
            compDict[number]++;
        }
        // otherwise store the key and the new value in the map
        else
        {
            compDict[number] = 1;
        }
    }

    bool find(int value)
    {
        // loop over number of elements in the map
        for (auto item : compDict)
        {
            // compute the difference between the current value and the key in item
            auto diff = value - item.first;
            // construct iterator and find the difference in the map
            it = compDict.find(diff);
            // if the diff is not the same as the key in the item
            if (diff != item.first)
            {
                // if the diff is in the map then return true
                if (it != compDict.end())
                {
                    return true;
                }
            }
            // also if the value is greater than one then then value is in the map
            else if (item.second > 1)
            {
                return true;
            }
        }

        // otherwise return false
        return false;
    }
};

/**
 * Your TwoSum object will be instantiated and called as such:
 * TwoSum* obj = new TwoSum();
 * obj->add(number);
 * bool param_2 = obj->find(value);
 */

int main()
{
    // class object
    TwoSum two_sum;

    // test cases
    // Add [1],[3],[5]
    two_sum.add(1);
    two_sum.add(3);
    two_sum.add(5);

    // find [4] and [7]
    auto res1 = two_sum.find(4);
    cout << "result 1: " << res1 << endl; // should return true
    auto res2 = two_sum.find(7);
    cout << "result 2: " << res2 << endl; // should return false

    return 0;
}