#include<iostream>
using namespace std;

struct ListNode{
    int val;
    ListNode *next;
    ListNode(int x):val(x),next(NULL){}
};

class Solution{
public:
    ListNode *swapPairs(ListNode* head){
        if(head == NULL) return head;
        ListNode *p = head;
        int temp = 0;
        while(p->next!=NULL){
            temp = p->val;
            p->val = p->next->val;
            p = p->next;
            p->val = temp;
            if(p->next!=NULL)
                p = p->next;
        }
        return head;
    }
};

int main()
{
    Solution S;
    ListNode p(1);
    ListNode q(2);
    p.next = &q;
    S.swapPairs(&p);
    return 0;
}
