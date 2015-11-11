/*************************************************************************
	> File Name: 9.cpp
	> Author: Alan
	> Mail: fleeyou@outlook.com
	> Created Time: Wed 11 Nov 2015 10:13:33 AM CST
    > Problem Name: Palindrome Number
    > Difficulty: Easy
    > Description:
        Determine whether an integer is a palindrome. Do this without extra space.
    > Some hints:
        Could negative integers be palindromes? (ie, -1)

        If you are thinking of converting the integer to string, note the restriction of using extra
        space.

        You could also try reversing an integer. However, if you have solved the problem "Reverse
        Integer", you know that the reversed integer might overflow. How would you handle such case?

        There is a more generic way of solving this problem.
 ************************************************************************/

#include<iostream>
using namespace std;

class Solution
{
public:
    bool isPalindrome(int x)
    {
        if(x < 0)
        {
            return false;
        }
        if(x < 10)
        {
            return true;
        }
        int tmp = x, res = 0;
        while(tmp > 0)
        {
            res = res * 10 + tmp % 10;
            tmp /= 10;
        }
        return res == x;
    }
};

int main()
{
    int num = 123454321;
    Solution sol = Solution();
    cout << num << " is ";
    if(!sol.isPalindrome(num))
    {
        cout << "not ";
    }
    cout << "a palindrome" << endl;
}
