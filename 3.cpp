/*************************************************************************
	> File Name: 3.cpp
	> Author: Alan
	> Mail: fleeyou@outlook.com
	> Created Time: Sun 08 Nov 2015 04:07:44 AM PST
    > Problem Name: Longest Substring Without Repeating Characters
    > Difficulty: Medium
    > Description: 
        Given a string, find the length of the longest substring without repeating characters. For 
        example, the longest substring without repeating letters for "abcabcbb" is "abc", which the 
        length is 3. For "bbbbb" the longest substring is "b", with the length of 1.

        Subscribe to see which companies asked this question
 ************************************************************************/

#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        /* 
        //Solution1: 140ms
        auto len=s.size();
        int i,j,maxx=0;
        set<int> exam;
        for(i=0,j=0;j<s.size();j++){
            while(exam.find(s[j])!=exam.end()){
                exam.erase(s[i]);
                i++;
            }
            exam.insert(s[j]);
            maxx=max(maxx,j-i+1);
        }
        return maxx;
        */
        
        vector<int> index(300,-1);
        int len=s.size(),tmp=1,maxx=1;
        if(len==0) 
            return 0;
        index[s[0]]=0;
        for(int i=1;i<len;i++)
        {
            int lastApp=index[s[i]];
            if(lastApp==-1) 
                tmp++;
            else 
                tmp=min(tmp+1,i-lastApp);
            index[s[i]]=i;
            maxx=max(maxx,tmp);
        }
        return maxx;
   }
};

int main(){
    string str("abcabcbb");
    Solution sol=Solution();
    int len=sol.lengthOfLongestSubstring(str);
    cout<<"The max length of substring without repeating characters is: "<<len<<endl;
}
