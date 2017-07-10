#include <iostream>
#include <algorithm>
#include <stack>
using namespace std;

struct ListNode{
	int data;
	ListNode *next;
};

//1.求单链表中结点个数
unsigned int getListLength(ListNode *head){
	if(head==NULL)
		return 0;
	unsigned int length = 0;
	ListNode *p = head;
	while(p!=NULL){
		p = p->next;
		length++;
	}
	return length;
}


//2.将单链表翻转
ListNode* reverseList(ListNode *head){
	if(head==NULL || head->next==NULL)
		return head;
	ListNode *reverseHead = NULL;
	ListNode *currnet = head;
	while(currnet != NULL){
		ListNode *temp = currnet;
		currnet = currnet->next;
		temp->next = reverseHead;
		reverseHead = temp;
	}
	cout<<reverseHead->data<<" "<<reverseHead->next->data<<" "<<reverseHead->next->next->data<<endl;
	return reverseHead;
}

//3.查找单链表中倒数第ｋ哥结点(k>0)

ListNode* getRkthNode(ListNode *head,int k){
	if(k<=0||head==NULL)
		return NULL;
	ListNode *a = head;
	ListNode *b = head;
	while(k>1 && a!=NULL){
		a = a->next;
		k--;
	}
	if(k>1||a==NULL)
		return NULL;
	while(a->next!=NULL){
		b = b->next;
		a = a->next;
	}
	//cout<<b->data<<endl;
	return b;
}

//4.快排单链表

ListNode* getPartion(ListNode * begin, ListNode *end){
	if(begin==NULL || begin->next==NULL)
		return begin;
	int key = begin->data;
	ListNode* p = begin;
	ListNode* q = begin->next;
	while(q!=end){
		if(q->data<key){
			p = p->next;
			swap(p->data,q->data);
		}
		q=q->next;
	}
	swap(begin->data,p->data);
	return p;
}


void QuickSort(ListNode *begin,ListNode* end){
	if(begin!=end){
		ListNode * partion = getPartion(begin,end);
		QuickSort(begin,partion);
		QuickSort(partion->next,end);
	}
}


//5.查找单链表中间结点
ListNode* getMiddleNode(ListNode* head){
	if(head==NULL||head->next==NULL)
		return head;
	ListNode *a = head;
	ListNode *b = head;
	while(a->next!=NULL){
		b=b->next;
		a=a->next;
		if(a->next!=NULL)
			a=a->next;
	}
	return b;
}

//6.从尾到头打印单链表(栈)
void reversePrint1(ListNode *head){
	stack<ListNode*> S;
	ListNode *temp = head;
	while(temp!=NULL){
		S.push(temp);
		temp = temp->next;
	}
	while(!S.empty()){
		temp = S.top();
		S.pop();
		cout<<temp->data<<" ";
	}
	cout<<endl;
}

//6.从尾到头打印单链表(递归)
void reversePrint2(ListNode *head){
	if(head==NULL){return;}
	else{
		reversePrint2(head->next);
		cout<<head->data<<" ";
	}
}

//7.已知两个单链表各自有序，合并成一个仍然有序的链表

ListNode* mergeSortList(ListNode* h1,ListNode* h2){
	if(h1==NULL) return h2;
	if(h2==NULL) return h1;
	ListNode *newhead = NULL;
	if(h1->data<h2->data){
		newhead = h1;
		 h1=h1->next;
		newhead->next=NULL;
	}else{
		newhead = h2;
		h2=h2->next;
		newhead->next = NULL;
	}
	ListNode *tmp = newhead;
	while(h1!=NULL&&h2!=NULL){
		if(h1->data<h2->data){
			tmp->next = h1;
			h1=h1->next;
			tmp=tmp->next;
			tmp->next=NULL;
		}else{
			tmp->next=h2;
			h2=h2->next;
			tmp=tmp->next;
			tmp->next = NULL;
		}
	}
	if(h1!=NULL)
		tmp->next = h1;
	else
		tmp->next = h2;
	return newhead;
}

//7.已知两个单链表各自有序，合并成一个仍然有序的链表(递归)

ListNode* mergeSortList2(ListNode *h1,ListNode *h2){
	if(h1==NULL) return h2;
	if(h2==NULL) return h1;
	ListNode *newhead = NULL;
	if(h1->data<h2->data){
		newhead = h1;
		newhead->next = mergeSortList2(h1->next,h2);
	}else{
		newhead = h2;
		newhead->next = mergeSortList2(h1,h2->next);
	}
	return newhead;
}

//8.判断单链表是否有环

bool hasCricle(ListNode *head){
	ListNode *fast = head;
	ListNode *slow = head;
	while(fast!=NULL && fast->next!=NULL){
		fast = fast->next->next;
		slow = slow->next;
		if(fast==slow)
			return true;
	}
	return false;
}

//9.判断两个链表是否相交

bool isIntersected(ListNode* h1,ListNode* h2){
	if(h1==NULL||h2==NULL)
		return false;
	ListNode* tail1 = h1;
	while(tail1->next!=NULL){
		tail1 = tail1->next;
	}
	ListNode* tail2 = h2;
	while(tail2->next!=NULL){
		tail2 = tail2->next;
	}
	return tail1==tail2;
}

//10.求两个单链表相交的第一个交点

ListNode* getFirstCommonNode(ListNode* h1,ListNode* h2){
	if(h1==NULL || h2==NULL)
		return NULL;
	int len1=1;
	int len2=1;
	ListNode* t1 = h1;
	while(t1!=NULL){
		len1++;
		t1=t1->next;
	}
	ListNode* t2 = h2;
	while(t2!=NULL){
		len2++;
		t2=t2->next;
	}
	if(t1!=t2)
		return NULL;
	ListNode* n1 = h1;
	ListNode* n2 = h2;
	if(len1>len2){
		int k = len1-len2;
		while(k--)
			n1=n1->next;
	}else{
		int k = len2-len1;
		while(k--)
			n2=n2->next;
	}
	while(n1!=n2){
		n1 = n1->next;
		n2 = n2->next;
	}
	return n1;
}

//11.已知一个单链表重存在环，求进入环中的第一个节点

ListNode*  getFirstNodeInCircle(ListNode* head){
	if(head==NULL||head->next==NULL)
		return NULL;
	ListNode *fast = head;
	ListNode *slow = head;
	while(fast->next!=NULL&&fast!=NULL){
		fast = fast->next->next;
		slow = slow->next;
		if(fast==slow)
			break;
	}
	if(fast==NULL||fast->next==NULL)
		return NULL;

	ListNode* assumeTail = slow;
	ListNode* h1 = head;
	ListNode* h2 = assumeTail->next;
	ListNode* n1 = h1;
	int len1 = 1;
	while(n1!=assumeTail){
		len1++;
		n1=n1->next;
	}
	ListNode* n2 = h2;
	int len2 = 1;
	while(n2!=assumeTail){
		len2++;
		n2=n2->next;
	}

	if(len1>len2){
		int k = len1-len2;
		while(k--){
			n1=n1->next;
		}
	}else{
		int k = len2-len1;
		while(k--){
			n2=n2->next;
		}
	}
	while(n1!=n2){
		n1=n1->next;
		n2=n2->next;
	}
	return n1;
}

//12.给出一单链表头指针和一节点指针，o(1)删除该节点
void Delete(ListNode* head,ListNode* todeleted){
	if(todeleted==NULL)
		return;
	if(todeleted->next!=NULL){
		todeleted->data = todeleted->next->data;
		ListNode* temp = todeleted->next;
		todeleted->next = todeleted->next->next;
		delete temp;
	}else{
		if(head==todeleted){
			head = NULL;
			delete todeleted;
		}else{
			ListNode* n = head;
			while (n->next!=todeleted) {
				n = n->next;
			}
			n->next = NULL;
			delete todeleted;
		}
	}
}


int main(int argc, char *argv[]) {

	ListNode *n1 = new ListNode;
	ListNode *n2 = new ListNode;
	ListNode *n3 = new ListNode;
	ListNode *n4 = new ListNode;
	ListNode *n5 = new ListNode;
	ListNode *n6 = new ListNode;

	n1->data = 1;
	n2->data = 2;
	n3->data = -2;
	n4->data = -1;
	n5->data = 0;
	n6->data = 3;

	n1->next = n2;
	n2->next = n3;
	n3->next = n4;
	n4->next = n5;
	n5->next = n6;
	n6->next = NULL;

	cout<<getListLength(n1)<<endl;
	//ListNode *newhead = reverseList(n1);
	//cout<<getRkthNode(newhead,2)->data<<endl;
	QuickSort(n1,NULL);
	ListNode *p = n1;

	while(p!=NULL){
		cout<<p->data<<" ";
		p = p->next;
	}
	cout<<endl;
	cout<<getMiddleNode(n1)->data<<endl;
	reversePrint1(n1);
	reversePrint2(n1);
	cout<<endl;

	ListNode *m1 = new ListNode;
	ListNode *m2 = new ListNode;
	m1->data = 2;
	m1->next = m2;
	m2->data = 4;
	m2->next = NULL;
	/*
	ListNode* mergehead = mergeSortList(n1,m1);
	while(mergehead!=NULL){
		cout<<mergehead->data<<" ";
		mergehead = mergehead->next;
	}
	cout<<endl;
	ListNode* mergehead2 = mergeSortList2(n1,m1);
	while(mergehead2!=NULL){
		cout<<mergehead2->data<<" ";
		mergehead2 = mergehead2->next;
	}
	cout<<endl;
	*/
	if(hasCricle(n1))
		cout<<"has"<<endl;
	else
		cout<<"no"<<endl;
	return 0;
}
