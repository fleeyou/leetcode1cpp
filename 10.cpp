/*************************************************************************
	> File Name: 10.cpp
	> Author: Alan
	> Mail: fleeyou@outlook.com
	> Created Time: Wed 11 Nov 2015 11:57:06 AM CST
    > Problem Name: Regular Expression Matching My Submissions Question
    > Difficulty: Hard
    > Description:
        Implement regular expression matching with support for '.' and '*'.

        '.' Matches any single character.
        '*' Matches zero or more of the preceding element.

        The matching should cover the entire input string (not partial).

        The function prototype should be:
        bool isMatch(const char *s, const char *p)

        Some examples:
        isMatch("aa","a") → false
        isMatch("aa","aa") → true
        isMatch("aaa","aa") → false
        isMatch("aa", "a*") → true
        isMatch("aa", ".*") → true
        isMatch("ab", ".*") → true
        isMatch("aab", "c*a*b") → true
 ************************************************************************/

#include<iostream>
#include<string>

using namespace std;

class Solution
{
public:
    bool isMatch(string s, string p)
    {
        int slen = s.size(), plen = p.size(), i, j;
        bool flag[slen + 1][plen + 1];
        for(i = 2, flag[0][0] = true, flag[0][1] = false; i <= plen; i++)
        {
            flag[0][i] = (p[i - 1] == '*' ? flag[0][i - 2] : false);
        }
        for(i = 1; i <= slen; i++)
        {
            for(j = 1, flag[i][0] = false; j <= plen; j++)
            {
                if(p[j - 1] == '*')
                {
                    flag[i][j] = (j > 1) && (flag[i][j - 2] || (flag[i - 1][j] && (s[i - 1] == p[j - 2] || p[j - 2] == '.')));
                }
                else
                {
                    flag[i][j] = flag[i - 1][j - 1] && (s[i - 1] == p[j - 1] || p[j - 1] == '.');
                }
            }
        }
        return flag[slen][plen];
    }
};

int main()
{
    Solution sol = Solution();
    string str1 = "aab", str2 = "c*a*b";
    cout << sol.isMatch(str1, str2) << endl;
}
