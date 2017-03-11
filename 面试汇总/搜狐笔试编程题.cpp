#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

//1.给升序数组 给s 问>=s的数有几个
int morethansnum(vector<int> V,int left,int right, int s){
	if(left<0||right<0||left>right||V.size()==0||V[V.size()-1]<s){
		return 0;
	}
	if(V[left]>=s)
		return V.size()-left;
	int mid = (left+right)/2;
	if(V[mid]<s&&V[mid+1]>=s)
		return V.size() - mid - 1;
	if(V[mid]>=s)
		return morethansnum(V,left,mid-1,s);
	else
		return morethansnum(V,mid+1,right,s);
} 

//2.给个链表L0,L1,L2......Ln-1,Ln -> L0,Ln,L1,Ln-1,L2,Ln-2,...... 要求空间复杂度o(1)
struct ListNode{
	int data;
	ListNode *next;
};

ListNode* changeList(ListNode* head){
	if(head==NULL||head->next==NULL)
		return head;
	ListNode* p = head;
	ListNode* q = head;
	ListNode* temp = head;
	while (temp->next->next!=NULL) {
		temp = temp->next;
	}
	q = temp->next;
	while(p->next!=q && p!=q){
		temp->next = NULL;
		ListNode* t = p->next;
		p->next = q;
		q->next = t;
		p = p->next->next;
		q = temp = head;
		while (temp->next->next!=NULL) {
			temp = temp->next;
		}
		q = temp->next;
	}
	return head;
}

//3.分层输出二叉树节点值 每层之间带回车
struct BTN{
	int value;
	BTN *left;
	BTN *right;
};
void printTree(BTN* root){
	if(root==NULL)
		return;
	queue<pair<BTN*,int> > Q;
	int flag = 0;
	Q.push(make_pair(root, flag));
	while (!Q.empty()) {
		while (Q.front().second==flag) {
			cout<<Q.front().first->value<<" ";
			BTN* temp = Q.front().first;
			Q.pop();
			if(temp->left!=NULL)
				Q.push(make_pair(temp->left, flag+1));
			if(temp->right!=NULL)
				Q.push(make_pair(temp->right, flag+1));
		}
		flag++;
		cout<<endl;
	}
}


int main(int argc, char *argv[]) {
	vector<int> V;
	//1,2,3,4,5,6,7,8,9,10
	for(int i = 1 ; i <= 10 ; ++i)
		V.push_back(i);
	for(int s = 0 ; s<=11 ;s++)
		cout<<morethansnum(V,0,9,s)<<" ";
	cout<<endl;
	
	
	ListNode* n1 = new ListNode;
	ListNode* n2 = new ListNode;
	ListNode* n3 = new ListNode;
	ListNode* n4 = new ListNode;
	ListNode* n5 = new ListNode;
	ListNode* n6 = new ListNode;
	ListNode* n7 = new ListNode;
	n1->data = 1;
	n2->data = 2;
	n3->data = 3;
	n4->data = 4;
	n5->data = 5;
	n6->data = 6;
	n7->data = 7;
	n1->next = n2;
	n2->next = n3;
	n3->next = n4;
	n4->next = n5;
	n5->next = n6;
	n6->next = n7;
	n7->next = NULL;
	//1 2 3 4 5 6  -> 1 6 2 5 3 4
	//1 2 3 4 5 6 7 ->1 7 2 6 3 5 4
	ListNode* head = changeList(n1);
	while(head!=NULL){
		cout<<head->data<<" ";
		head = head->next;
	}
	cout<<endl;
	
	BTN* nn1 = new BTN;
	BTN* nn2 = new BTN;
	BTN* nn3 = new BTN;
	BTN* nn4 = new BTN;
	BTN* nn5 = new BTN;
	BTN* nn6 = new BTN;
	BTN* nn7 = new BTN;
	nn1->value = 1;
	nn2->value = 2;
	nn3->value = 3;
	nn4->value = 4;
	nn5->value = 5;
	nn6->value = 6;
	nn7->value = 7;
	nn1->left = nn2;
	nn1->right = nn3;
	nn2->left = nn4;
	nn2->right = nn5;
	nn3->left = nn6;
	nn3->right = nn7;
	nn4->left=nn4->right=nn5->left=nn5->right=nn6->left=nn6->right=nn7->left=nn7->right=NULL;
	printTree(nn1);
	return 0;
}