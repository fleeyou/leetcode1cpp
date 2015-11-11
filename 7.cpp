/*************************************************************************
	> File Name: 7.cpp
	> Author: Alan
	> Mail: fleeyou@outlook.com
	> Created Time: Tue 10 Nov 2015 11:43:19 AM CST
    > Problem Name: Reverse Integer
    > Difficulty: Easy
    > Description:
        Reverse digits of an integer.

        Example1: x = 123, return 321
        Example2: x = -123, return -321
 ************************************************************************/

#include<iostream>
#include<climits>

using namespace std;

class Solution
{
public:
    int reverse(int x)
    {
        if(x == 0)
        {
            return 0;
        }
        int flag = x > 0 ? 1 : -1;
        long sum = 0;
        long tmp = abs((long)x);
        while(tmp)
        {
            sum = sum * 10 + tmp % 10;
            tmp /= 10;
        }
        return (sum > INT_MAX) ? 0 : sum * flag;
    }
};

int main()
{
    Solution sol = Solution();
    int num = 1234567;
    cout << "The reversed number is: " << sol.reverse(num) << endl;
}
