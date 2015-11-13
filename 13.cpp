/*************************************************************************
	> File Name: 13.cpp
	> Author: Alan
	> Mail: fleeyou@outlook.com
	> Created Time: Fri 13 Nov 2015 10:28:26 AM CST
    > Problem Name: Roman to Integer My Submissions Question
    > Difficulty: Easy
    > Description:
        Given a roman numeral, convert it to an integer.

        Input is guaranteed to be within the range from 1 to 3999.
 ************************************************************************/

#include<iostream>
using namespace std;

class Solution
{
public:
    int romanToInt(string s)
    {
        int num[256] = { 0 };
        int result = 0;
        num['I'] = 1;
        num['V'] = 5;
        num['X'] = 10;
        num['L'] = 50;
        num['C'] = 100;
        num['D'] = 500;
        num['M'] = 1000;
        int i = 0;
        while (i < s.size())
        {
            if (num[s[i]] < num[s[i + 1]])
                result -= num[s[i]];
            else
                result += num[s[i]];
            i++;
        }
        return result;
    }
};

int main()
{
    string str = "DCXL";
    Solution sol = Solution();
    cout << "The value of " << str << " is " << sol.romanToInt(str) << endl;
}
