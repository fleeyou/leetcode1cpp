/*************************************************************************
	> File Name: 5.cpp
	> Author: Alan
	> Mail: fleeyou@outlook.com
	> Created Time: Mon 09 Nov 2015 08:03:56 PM CST
    > Problem Name: Longest Palindromic Substring My Submissions Question
    > Difficulty: Medium
    > Description:
        Given a string S, find the longest palindromic substring in S. You may assume that the maximum 
        length of S is 1000, and there exists one unique longest palindromic substring.
 ************************************************************************/

#include<iostream>
#include<cstring>

using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        const int len=s.size();
        bool p[len][len];
        memset(p,false,len*len);
        int max_len=1, start=0;
        for(int j = 0; j<len;j++){
            p[j][j]=true;
            for(int i = 0; i<j;i++){
                p[i][j]=(s[i]==s[j]&&(j-i<2||p[i+1][j-1]));
                if(p[i][j]&&max_len<(j-i+1)){
                    max_len=j-i+1;
                    start=i;
                }
            }
        }
        return s.substr(start, max_len);
    }
};

int main(){
    string s{
        "abcbacd"
    };
    Solution sol = Solution();
    cout<<"The longest palindromic substring in the string is: "<<sol.longestPalindrome(s)<<endl;
}
