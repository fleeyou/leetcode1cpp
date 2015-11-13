/*************************************************************************
	> File Name: 14.cpp
	> Author: Alan
	> Mail: fleeyou@outlook.com
	> Created Time: Fri 13 Nov 2015 12:25:44 PM CST
    > Problem Name: Longest Common Prefix My Submissions Question
    > Difficulty: Easy
    > Description:
        Write a function to find the longest common prefix string amongst
        an array of strings.
 ************************************************************************/

#include<iostream>
#include<vector>

using namespace std;

class Solution
{
public:
    string longestCommonPrefix(vector<string>& strs)
    {
        if(strs.empty())
        {
            return string();
        }
        for(int i = 0; i < strs[0].size(); i++)
        {
            for(int j = 1; j < strs.size(); j++)
            {
                if(strs[0][i] != strs[j][i])
                {
                    return strs[0].substr(0, i);
                }
            }
        }
        return strs[0];
    }
};

int main()
{
    Solution sol = Solution();
    vector<string> ivec =
    {
        "hello", "hely", "helco", "helquw"
    };
    cout << "The result is: " << sol.longestCommonPrefix(ivec) << endl;
}
