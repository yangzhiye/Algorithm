#include <iostream>

using namespace std;

//1.递归翻转链表
struct ListNode{
	int data;
	ListNode* next;
};
ListNode* reverseList(ListNode* root){
	if(root==NULL||root->next==NULL)
		return root;
	ListNode* head = reverseList(root->next);
	root->next->next = root;
	root->next = NULL;
	return head;
}

void printList(ListNode* head){
	if(head==NULL)
		return;
	while(head!=NULL){
		cout<<head->data<<" ";
		head = head->next;
	}
}

//2.判断跟节点到叶子结点带权最大值
struct BTN{
	int value;
	BTN* left;
	BTN* right;
};
int getMax(BTN* root){
	if(root==NULL)
		return 0;
	if(root->left==NULL&&root->right==NULL)
		return root->value;
	int max1,max2;
	max1=max2=0;
	if(root->left!=NULL)
		max1 = getMax(root->left)+root->value;
	if(root->right!=NULL)
		max2 = getMax(root->right)+root->value;
	return max(max1,max2);
}

//malloc和new的区别
//1.new返回指定类型的指针，并且可以自动计算所需要大小
//  malloc则必须要求我们计算字节数，并且在返回后强行转换为实际类型的指针
//2.malloc只管分配内存，不初始化。


int main(int argc, char *argv[]) {
	ListNode *n1 = new ListNode;
	ListNode *n2 = new ListNode;
	ListNode *n3 = new ListNode;
	ListNode *n4 = new ListNode;
	ListNode *n5 = new ListNode;
	n1->data = 1;
	n2->data = 2;
	n3->data = 3;
	n4->data = 4;
	n5->data = 5;
	n1->next = n2;
	n2->next = n3;
	n3->next = n4;
	n4->next = n5;
	n5->next = NULL;
	printList(reverseList(n1));
	cout<<endl;
	
	BTN *root = new BTN;
	BTN *nn1 = new BTN;
	BTN *nn2 = new BTN;
	BTN *nn3 = new BTN;
	BTN *nn4 = new BTN;
	BTN *nn5 = new BTN;
	root->value = 1;
	nn1->value = 2;
	nn2->value = 3;
	nn3->value = 4;
	nn4->value = 5;
	nn5->value = 6;
	root->left = nn1;
	nn1->left =NULL;
	nn1->right =NULL;
	root->right = nn2;
	nn2->left = nn3;
	nn3->left = nn5;
	nn3->right = NULL;
	nn2->right = nn4;
	nn4->left=NULL;
	nn4->right=NULL;
	cout<<getMax(root);
}