#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

struct ListNode{
    int val;
    ListNode *next;
    ListNode(int x):val(x),next(NULL){}
};

struct Node{
    int val;
    int num;
    Node(int x,int y):val(x),num(y){}
};

bool cmp(Node a , Node b){
    return a.val > b.val;
};

class Solution{
    public:
        ListNode* mergeKLists(vector<ListNode*> lists){
            vector<Node> V;
            for(int i = 0;i<lists.size();i++){
                if(lists[i]==NULL) continue;
                V.push_back(Node(lists[i]->val,i));
            }
            if(V.size()==0) return NULL;
            make_heap(V.begin(),V.end(),cmp);
            ListNode *root = new ListNode(1);
            ListNode *temp = root;
            int cnt = V.size();
            while(cnt){
                pop_heap(V.begin(),V.end(),cmp);
                Node p = *(V.end()-1);
                temp->next = new ListNode(1);
                temp = temp->next;
                temp->val = p.val;
                if(lists[p.num]->next == NULL)
                {
                    V.erase(V.end()-1,V.end());
                    cnt--;
                }
                else
                {
                    lists[p.num] = lists[p.num]->next;
                    V[V.size()-1] = Node(lists[p.num]->val,p.num);
                    push_heap(V.begin(),V.end(),cmp);
                }
            }
            return root->next;
        }
};

int main(){

    return 0;
}
