/*************************************************************************
	> File Name: 2.cpp
	> Author: Alan
	> Mail: fleeyou@outlook.com
	> Created Time: Sun 08 Nov 2015 01:42:23 AM PST
    > Problem Name: Add Two Numbers
    > Description:
        You are given two linked lists representing two non-negative numbers. The digits are stored in 
        reverse order and each of their nodes contain a single digit. Add the two numbers and return it 
        as a linked list.

        Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
        Output: 7 -> 0 -> 8
 ************************************************************************/

#include<iostream>
using namespace std;

struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
};
 
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode head(-1);
        ListNode* prev = &head, * p1, * p2;
        int carry = 0, value;
        for(p1=l1,p2=l2;p1||p2;p1=p1?p1->next:nullptr,p2=p2?p2->next:nullptr,prev=prev->next){
            const int num1=p1?p1->val:0;
            const int num2=p2?p2->val:0;
            value = (num1+ num2 + carry)%10;
            carry = (num1+num2+carry)/10;
            prev->next = new ListNode(value);
        }
        if(carry>0){
            prev->next=new ListNode(carry);
        }
        return head.next;
    }
};

int main(){
    Solution sol = Solution();
    ListNode l1(2),l11(4),l12(3),l2(5),l21(6),l22(4);
    l1.next=&l11;
    l11.next=&l12;
    l2.next=&l21;
    l21.next=&l22;
    ListNode * result=sol.addTwoNumbers(&l1,&l2);
    while(result){
        cout<<result->val;
        if(result->next){
            cout<<"->";
        }
        result=result->next;
    }
    cout<<endl;
}
