/*************************************************************************
	> File Name: 1.cpp
	> Author: Alan
	> Mail: fleeyou@outlook.com
	> Created Time: Sat 07 Nov 2015 10:19:04 PM PST
    > Problem Name: Two Sum
    > Description:
        Given an array of integers, find two numbers such that they add up to a specific target number.

        The function twoSum should return indices of the two numbers such that they add up to the
        target, where index1 must be less than index2. Please note that your returned answers (both
        index1 and index2) are not zero-based.

        You may assume that each input would have exactly one solution.

        Input: numbers={2, 7, 11, 15}, target=9
        Output: index1=1, index2=2
 ************************************************************************/

#include<iostream>
#include<vector>
#include<unordered_map>

using namespace std;

class Solution
{
public:
    vector<int> twoSum(vector<int>& nums, int target)
    {
        unordered_map<int,int> mapping;
        vector<int> result;
        int i;
        for(i = 0; i < nums.size(); i++)
        {
            mapping[nums[i]] = i;
        }
        for(i = 0; i < nums.size(); i++)
        {
            const int gap = target - nums[i];
            if(mapping.find(gap) != mapping.end()
                    && i != mapping[gap])
            {
                result.push_back(i + 1);
                result.push_back(mapping[gap] + 1);
                break;
            }
        }
        return result;
    }
};

int main()
{
    Solution test = Solution();
    vector<int> ivec
    {
        3, 2, 4
    };
    for(auto i : test.twoSum(ivec,6))
    {
        cout << i << "  ";
    }
    cout << endl;
}
