/*************************************************************************
	> File Name: 11.cpp
	> Author: Alan
	> Mail: fleeyou@outlook.com
	> Created Time: Wed 11 Nov 2015 04:00:46 PM CST
    > Container With Most Water
    > Difficulty: Medium
    > Description:
        Given n non-negative integers a1, a2, ..., an, where each represents a point at coordinate (i,
        ai). n vertical lines are drawn such that the two endpoints of line i is at (i, ai) and (i, 0).
        Find two lines, which together with x-axis forms a container, such that the container contains
        the most water.

    > Note: You may not slant the container.
 ************************************************************************/

#include<iostream>
#include<vector>

using namespace std;

class Solution
{
public:
    int maxArea(vector<int>& height)
    {
        int water = 0, i = 0, j = height.size() - 1, h;
        while (i < j)
        {
            h = min(height[i], height[j]);
            water = max(water, (j - i) * h);
            while (height[i] <= h && i < j) i++;
            while (height[j] <= h && i < j) j--;
        }
        return water;
    }
};

int main()
{
    Solution sol = Solution();
    vector<int> ivec =
    {
        2, 8, 3, 5, 1, 8
    };
    cout << "The result is: " << sol.maxArea(ivec) << endl;
}
