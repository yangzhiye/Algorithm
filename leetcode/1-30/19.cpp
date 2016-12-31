#include<iostream>
#include<algorithm>
using namespace std;
//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    int getListSize(ListNode* head){
        int ret = 1;
        while(head->next!=NULL){
            ret++;
            head = head->next;
        }
        return ret;
    }
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int len = getListSize(head);
        cout<<"len is        "<<len<<endl;
        if(n==len&&n==1) {
            //head->val = NULL;
            return NULL;
        }
        if(n==len) return head->next;
        ListNode *p = head;
        ListNode *q;
        int cha = len - n;
        while(cha--){
            cout<<"cha is       "<<cha<<endl;
            q=p;
            p = p->next;
        }
        if(n==1){
            q->next = NULL;
            return head;
        }
        q->next = p->next;
        return head;
    }
};

int main()
{
    ListNode p(1),q(2),w(3);
    p.next=&q;
    q.next=&w;
    Solution S;
    ListNode *head = S.removeNthFromEnd(&p,2);
    cout<<head->val<<" ";
    while(head->next!=NULL){
        head = head->next;
        cout<<head->val<<" ";
    }
    return 0;
}
