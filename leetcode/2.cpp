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
        ListNode *answer = new ListNode(0);
        ListNode *p1 = l1,*p2 = l2, *p = answer;
        int carry = 0;
        int x,y,sum;
        while(p1!=NULL || p2!=NULL){
            x = (p1!=NULL)? p1->val:0;
            y = (p2!=NULL)? p2->val:0;
            sum = x+y+carry;
            carry = sum/10;
            p->next = new ListNode(sum%10);
            p = p->next;
            if(p1!=NULL)
                p1 = p1->next;
            if(p2!=NULL)
                p2 = p2->next;
        }
        if(carry>0){
            p->next = new ListNode(carry);
        }
        return answer;
    }
};

int main()
{
    return 0;
}
