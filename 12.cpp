/*************************************************************************
	> File Name: 12.cpp
	> Author: Alan
	> Mail: fleeyou@outlook.com
	> Created Time: Fri 13 Nov 2015 09:48:25 AM CST
    > Problem Name: Integer to Roman My Submissions Question
    > Difficulty: Medium
    > Description:
        Given an integer, convert it to a roman numeral.

        Input is guaranteed to be within the range from 1 to 3999.
 ************************************************************************/

#include<iostream>
#include<string>

using namespace std;

class Solution
{
public:
    string intToRoman(int num)
    {
        string res;
        for(; num / 1000; num -= 1000)
        {
            res += "M";
        }
        if(num >= 900)
        {
            res += "CM";
            num -= 900;
        }
        if(num >= 500)
        {
            res += "D";
            num -= 500;
        }
        if(num >= 400)
        {
            res += "CD";
            num -= 400;
        }
        for(; num / 100; num -= 100)
        {
            res += "C";
        }
        if(num >= 90)
        {
            res += "XC";
            num -= 90;
        }
        if(num >= 50)
        {
            res += "L";
            num -= 50;
        }
        if(num >= 40)
        {
            res += "XL";
            num -= 40;
        }
        for(; num / 10; num -= 10)
        {
            res += "X";
        }
        if(num == 9)
        {
            res += "IX";
            num -= 9;
        }
        if(num >= 5)
        {
            res += "V";
            num -= 5;
        }
        if(num >= 4)
        {
            res += "IV";
            num -= 4;
        }
        for(; num; num--)
        {
            res += "I";
        }
        return res;
    }
};

int main()
{
    Solution sol = Solution();
    int num = 3898;
    cout << "The Roman format of " << num << " is " << sol.intToRoman(num) << endl;
}
