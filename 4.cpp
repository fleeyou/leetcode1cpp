/*************************************************************************
	> File Name: 4.cpp
	> Author: Alan
	> Mail: fleeyou@outlook.com
	> Created Time: Mon 09 Nov 2015 02:20:06 PM CST
    > Problem Name: Median of Two Sorted Arrays My Submissions Question
    > Difficulty: Hard
    > Description:
        There are two sorted arrays nums1 and nums2 of size m and n respectively. Find the
        median of the two sorted arrays. The overall run time complexity should be O(log (m+n)).
 ************************************************************************/

#include<iostream>
#include<vector>

using namespace std;

class Solution
{
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2)
    {
        int len1 = nums1.size(), len2 = nums2.size();
        int lenTotal = len1 + len2;
        if(lenTotal == 0)
        {
            return 0;
        }
        bool even = lenTotal % 2 == 1 ? false : true;
        int middle = lenTotal / 2, index1 = 0, index2 = 0, prev, next = 0;
        for(int i = 0; i <= middle; i++)
        {
            prev = next;
            if(index1 == len1 && index2 != len2)
            {
                next = nums2[index2++];
                continue;
            }
            if(index2 == len2 && index1 != len1)
            {
                next = nums1[index1++];
                continue;
            }
            if(nums1[index1] < nums2[index2])
            {
                next = nums1[index1++];
            }
            else
            {
                next = nums2[index2 ++];
            }
        }
        return even ? (prev + next) / 2.0 : next;
    }
};

int main()
{
    Solution sol = Solution();
    vector<int> ivec1
    {
        1, 3, 5
    };
    vector<int> ivec2
    {
        2, 4
    };
    cout << sol.findMedianSortedArrays(ivec1, ivec2) << endl;
}
