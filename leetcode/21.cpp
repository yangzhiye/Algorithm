#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
 };

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode *root,*p;
        root = new ListNode(-1);
        p = root;
        while(1){
            if(l1==NULL){p->next = l2;break;}
            if(l2==NULL){p->next = l1;break;}
            if(l1->val<l2->val){
                p->next = l1;
                l1 = l1->next;
            }else{
                p->next = l2;
                l2 = l2->next;
            }
            p = p->next;
        }
        ListNode *temp = root->next;
        delete(root);
        return temp;
    }
};

int main()
{

    return 0;
}
