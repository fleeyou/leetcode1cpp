/*************************************************************************
	> File Name: 8.cpp
	> Author: Alan
	> Mail: fleeyou@outlook.com
	> Created Time: Wed 11 Nov 2015 08:59:51 AM CST
    > Problem Name: String to Integer (atoi)
    > Difficulty: Easy
    > Description:
        Implement atoi to convert a string to an integer.

        Hint: Carefully consider all possible input cases. If you want a
        challenge, please do not see below and ask yourself what are the
        possible input cases.

        Notes: It is intended for this problem to be specified vaguely (ie,
        no given input specs). You are responsible to gather all the input
        requirements up front.
    > Requirements for atoi:
        The function first discards as many whitespace characters as
        necessary until the first non-whitespace character is found. Then,
        starting from this character, takes an optional initial plus or
        minus sign followed by as many numerical digits as possible, and
        interprets them as a numerical value.

        The string can contain additional characters after those that form
        the integral number, which are ignored and have no effect on the
        behavior of this function.

        If the first sequence of non-whitespace characters in str is not a
        valid integral number, or if no such sequence exists because either
        str is empty or it contains only whitespace characters, no
        conversion is performed.

        If no valid conversion could be performed, a zero value is
        returned. If the correct value is out of the range of representable
        values, INT_MAX (2147483647) or INT_MIN (-2147483648) is returned.
 ************************************************************************/

#include<iostream>
#include<string>
#include<climits>

using namespace std;

class Solution
{
public:
    int myAtoi(string str)
    {
        int len = str.size(), sign = 1, i = 0, num = 0;
        bool flag = false;
        while(str[i] == ' ')
        {
            i++;
        }
        while(str[i] == '+' || str[i] == '-')
        {
            if(flag)
            {
                return 0;
            }
            else
            {
                flag = true;
                if(str[i] == '-')
                {
                    sign = -1;
                }
                i++;
            }
        }
        for(; i < len; i++)
        {
            if(str[i] < '0' || str[i] > '9')
            {
                break;
            }
            if(num > INT_MAX / 10 || (num == INT_MAX / 10 && (str[i] - '0') > INT_MAX % 10))
            {
                return sign == -1 ? INT_MIN : INT_MAX;
            }
            num = num * 10 + str[i] - '0';
        }
        return num * sign;
    }
};

int main()
{
    Solution sol = Solution();
    string str = "    +1468ab345";
    cout << "Convert \"" << str << "\" To integer, the result is: " << sol.myAtoi(str) << endl;
}
