/*************************************************************************
	> File Name: 6.cpp
	> Author: Alan
	> Mail: fleeyou@outlook.com
	> Created Time: Tue 10 Nov 2015 10:28:03 AM CST
    > Problem Name: ZigZag Conversion My Submissions Question
    > Difficulty: Easy
    > Description:
        The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this:
        (you may want to display this pattern in a fixed font for better legibility)

        P   A   H   N
        A P L S I I G
        Y   I   R

        And then read line by line: "PAHNAPLSIIGYIR"
        Write the code that will take a string and make this conversion given a number of rows:

        string convert(string text, int nRows);
        convert("PAYPALISHIRING", 3) should return "PAHNAPLSIIGYIR".
 ************************************************************************/

#include<iostream>
#include<string>

using namespace std;

class Solution
{
public:
    string convert(string s, int numRows)
    {
        auto iter = s.begin();
        string res[numRows];
        int gap = numRows - 2;
        while(iter != s.end())
        {
            for(int i = 0; i < numRows && iter != s.end(); i++)
            {
                res[i] += *iter++;
            }
            for(int i = gap; i > 0 && iter != s.end(); i--)
            {
                res[i] += *iter++;
            }
        }
        string result = "";
        for(auto v : res)
        {
            result += v;
        }
        return result;
    }
};

int main()
{
    Solution sol = Solution();
    string str = "PAYPALISHIRING";
    cout << "The zigzag format of the input string is: " << sol.convert(str, 3) << endl;
}
