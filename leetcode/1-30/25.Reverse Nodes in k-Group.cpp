#include<iostream>
using namespace std;

struct ListNode{
    int val;
    ListNode *next;
    ListNode(int x):val(x),next(NULL){}
};

class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head == NULL) return head;
        ListNode *p = head;
        ListNode *list_size = head;
        int size = 0;
        while(list_size!=NULL){
            size+=1;
            list_size = list_size->next;
        }
        int cnt = size/k;
        int temp = 0;
        int n = k;
        int m = 0;
        int mm = k;
        ListNode *pp;
        while(cnt--){
            cout<<"cnt = "<<cnt<<endl;
            while(n>=2){
                m = n;
                pp = p;
                cout<<"m = "<<m<<"  n="<<n<<endl;
                while(m>=2){
                    temp = pp->val;
                    pp->val = pp->next->val;
                    pp = pp->next;
                    pp->val = temp;
                    m--;
                }
                n--;
            }
            n = k;
            while(mm--){
                p = p->next;
            }
            mm=k;
        }
        return head;
    }
};

int main()
{
    Solution S;
    ListNode p(1);
    ListNode q(2);
    ListNode w(3);
    ListNode e(4);
    p.next = &q;
    q.next = &w;
    w.next = &e;
    S.reverseKGroup(&p,2);
    return 0;
}
