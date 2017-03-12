#include <iostream>
#include <math.h>
#include <algorithm>
#include <queue>
#include <stack>
#include <list>
using namespace std;

struct BinaryTreeNode{
	int value;
	BinaryTreeNode *left;
	BinaryTreeNode *right;
};

//1.求二叉树中的节点个数
int getNodeNum(BinaryTreeNode* root){
	if(root==NULL)
		return 0;
	return getNodeNum(root->left)+getNodeNum(root->right)+1;
}

//2.求二叉树的深度
int getDepth(BinaryTreeNode* root){
	if(root==NULL)
		return 0;
	int depthleft = getDepth(root->left);
	int depthright = getDepth(root->right);
	return max(depthleft,depthright)+1;
}

//3.前序中序后序遍历二叉树
void visit(BinaryTreeNode* node){
	cout<<node->value<<" ";
}
void preOrderTraverse(BinaryTreeNode* root){
	if(root==NULL)
		return;
	visit(root);
	preOrderTraverse(root->left);
	preOrderTraverse(root->right);
}

void inOrderTraverse(BinaryTreeNode* root){
	if(root==NULL)
		return;
	inOrderTraverse(root->left);
	visit(root);
	inOrderTraverse(root->right);
}

void postOrderTraverse(BinaryTreeNode* root){
	if(root==NULL)
		return;
	postOrderTraverse(root->left);
	postOrderTraverse(root->right);
	visit(root);
}

//4.分层遍历二叉树

void levelTraverse(BinaryTreeNode* root){
	if(root==NULL)
		return;
	queue<BinaryTreeNode*> Q;
	Q.push(root);
	while(!Q.empty()){
		BinaryTreeNode* temp = Q.front();
		Q.pop();
		visit(temp);
		if(temp->left!=NULL)
			Q.push(temp->left);
		if(temp->right!=NULL)
			Q.push(temp->right);
	}
}

//5.将二叉查找树变为有序的双向链表
void convert(BinaryTreeNode* root,BinaryTreeNode* first,BinaryTreeNode* last){

	BinaryTreeNode* firstleft,*lastleft,*firstright,*lastright;
	if(root==NULL){
		first=NULL;
		last=NULL;
		return;
	}
	if(root->left==NULL){
		first = root;
	}else{
		convert(root->left,firstleft,lastleft);
		first = firstleft;
		root->left = lastleft;
		lastleft->right = root;
	}
	if(root->right==NULL){
		last = root;
	}else{
		convert(root->right,firstright,lastright);
		last = lastright;
		root->right = firstright;
		firstright->left = root;
	}
	return ;
}

//6.求二叉树第ｋ层的节点个数
int getKthNodeNum(BinaryTreeNode* root,int k){
	if(k<1||root==NULL)
		return 0;
	if(k==1)
		return 1;
	return getKthNodeNum(root->left,k-1)+getKthNodeNum(root->right,k-1);
}

//7.求二叉树中叶子节点的个数
int getLeafNodeNum(BinaryTreeNode* root){
	if(root==NULL)
		return 0;
	if(root->left==NULL&&root->right==NULL)
		return 1;
	return getLeafNodeNum(root->left)+getLeafNodeNum(root->right);
}

//8.判断两棵二叉树是否结构相同
bool structurecmp(BinaryTreeNode* root1,BinaryTreeNode* root2){
	if(root1==NULL && root2==NULL)
		return true;
	else if(root1==NULL || root2==NULL)
		return false;
	return structurecmp(root1->left,root2->left)&&structurecmp(root2->right,root2->right);
}

//9.判断二叉树是不是平衡二叉树并计算高度
bool isAVL(BinaryTreeNode* root1, int &height){
	if(root1==NULL){
		height = 0;
		return true;
	}
	int heightleft,heightright;
	bool resultleft = isAVL(root1->left,heightleft);
	bool resultright = isAVL(root1->right,heightright);
	if(resultleft&&resultright&&abs(heightleft-heightright)<=1){
		height = max(heightleft,heightright)+1;
		return true;
	}else{
		height = max(heightleft,heightright)+1;
		return false;
	}
}

//10.求二叉树的镜像
BinaryTreeNode* mirror(BinaryTreeNode* root){
	if(root==NULL)
		return NULL;
	BinaryTreeNode* left = mirror(root->left);
	BinaryTreeNode* right = mirror(root->right);
	root->left = right;
	root->right = left;
	return root;
}

//11.求二叉树中两个节点的最低公共祖先节点(递归)
bool findNode(BinaryTreeNode* root,BinaryTreeNode* node){
	if(root==NULL || node ==NULL)
		return false;
	if(root==node)
		return true;
	bool found = findNode(root->left,node);
	if(!found)
		found = findNode(root->right,node);
	return found;
}

BinaryTreeNode* getLastCommonParent(BinaryTreeNode* root,BinaryTreeNode* node1,BinaryTreeNode* node2){
	if(root==NULL||node1==NULL||node2==NULL||node1==node2)
		return NULL;
	if(findNode(root->left,node1)){
		if(findNode(root->right,node2))
			return root;
		else
			return getLastCommonParent(root->left,node1,node2);
	}else{
		if(findNode(root->left,node2))
			return root;
		else
			return getLastCommonParent(root->right,node1,node2);
	}
}

//11.求二叉树中两个节点的最低公共祖先节点(非递归)
bool getNodePath(BinaryTreeNode* root,BinaryTreeNode* node,list<BinaryTreeNode*> &path){
	if(root==node){
		path.push_back(root);
		return true;
	}
	if(root==NULL)
		return false;
	path.push_back(root);
	bool found = false;
	found = getNodePath(root->left,node,path);
	if(!found)
		found = getNodePath(root->right,node,path);
	if(!found)
		path.pop_back();
	return found;
}

BinaryTreeNode* getLastCommonParent2(BinaryTreeNode* root,BinaryTreeNode* node1,BinaryTreeNode* node2){
	if(root==NULL||node1==NULL||node2==NULL||node1==node2)
		return NULL;
	list<BinaryTreeNode*> path1,path2;
	bool result1 = getNodePath(root,node1,path1);
	bool result2 = getNodePath(root,node2,path2);
	if(!result1||!result2)
		return NULL;
	BinaryTreeNode* last = NULL;
	auto iter1 = path1.begin();
	auto iter2 = path2.begin();
	while(iter1!=path1.end()&&iter2!=path2.end()){
		if(*iter1==*iter2)
			last = *iter1;
		else
			break;
		iter1++;
		iter2++;
	}
	return last;
}

//12.求二叉树中节点的最大距离
int getMaxDistance(BinaryTreeNode* root,int &maxleft,int &maxright){
	if(root==NULL){
		maxleft = 0;
		maxright = 0;
		return 0;
	}
	int maxLL,maxLR,maxRL,maxRR;
	int maxDistleft,maxDistright;
	if(root->left!=NULL){
		maxDistleft =  getMaxDistance(root->left,maxLL,maxLR);
		maxleft = max(maxLL,maxLR)+1;
	}else{
		maxDistleft=0;
		maxleft=0;
	}
	if(root->right!=NULL){
		maxDistright = getMaxDistance(root->right,maxRL,maxRR);
		maxright = max(maxRL,maxRR)+1;
	}else{
		maxDistright=0;
		maxright=0;
	}
	return max(max(maxDistleft,maxDistright),maxleft+maxright);
}

//13.由前序遍历和中序遍历构建二叉树
BinaryTreeNode* reBuildBinaryTree(int* preorder,int* inorder,int nodeNum){
	if(preorder==NULL||inorder==NULL||nodeNum<=0)
		return NULL;
	BinaryTreeNode* root = new BinaryTreeNode;
	root->value = preorder[0];
	root->left = NULL;
	root->right = NULL;
	int rootPositionInOrder = -1;
	for(int i = 0 ; i < nodeNum ; ++i){
		if(inorder[i] == root->value){
			rootPositionInOrder = i;
			break;
		}
	}
	if(rootPositionInOrder==-1)
		return NULL;
	int nodeNumLeft = rootPositionInOrder;
	int *preorderLeft = preorder+1;
	int *inorderLeft = inorder;
	root->left = reBuildBinaryTree(preorderLeft,inorderLeft,nodeNumLeft);
	int nodeNumRight = nodeNum - rootPositionInOrder -1;
	int *preorderRight = preorder + nodeNumLeft +1;
	int *inorderRight = inorder+nodeNumLeft+1;
	root->right = reBuildBinaryTree(preorderRight,inorderRight,nodeNumRight);
	return root;
}

//14.判断二叉树是不是完全二叉树
bool isCompleteBInaryTree(BinaryTreeNode* root){
	if(root==NULL)
		return false;
	queue<BinaryTreeNode*> Q;
	Q.push(root);
	bool mustHaveNoChild = false;
	bool result = true;
	while(!Q.empty()){
		BinaryTreeNode* node = Q.front();
		Q.pop();
		if(mustHaveNoChild){
			if(node->left!=NULL || node->right!=NULL){
				result = false;
				break;
			}
		}else{
			if(node->left!=NULL && node->right!=NULL){
				Q.push(node->left);
				Q.push(node->right);
			}else if(node->left!=NULL && node->right==NULL){
				mustHaveNoChild = true;
				Q.push(node->left);
			}else if(node->left==NULL && node->right!=NULL){
				result = false;
				break;
			}else{
				mustHaveNoChild = true;
			}
		}
	}
	return result;
}

int main(){
	BinaryTreeNode *root = new BinaryTreeNode;
	BinaryTreeNode *n1 = new BinaryTreeNode;
	BinaryTreeNode *n2 = new BinaryTreeNode;
	BinaryTreeNode *n3 = new BinaryTreeNode;
	BinaryTreeNode *n4 = new BinaryTreeNode;
	BinaryTreeNode *n5 = new BinaryTreeNode;
	root->value = 2;
	n1->value = 1;
	n2->value = 5;
	n3->value = 4;
	n4->value = 3;
	n5->value = 6;
	root->left = n1;
	n1->left =NULL;
	n1->right =NULL;
	root->right = n2;
	n2->left = n3;
	n3->left = n5;
	n3->right = NULL;
	n2->right = n4;
	n4->left=NULL;
	n4->right=NULL;


	cout<<getNodeNum(root)<<endl;
	cout<<getDepth(root)<<endl;
	preOrderTraverse(root);
	cout<<endl;
	inOrderTraverse(root);
	cout<<endl;
	postOrderTraverse(root);
	cout<<endl;
	levelTraverse(root);
	cout<<endl;
	cout<<getKthNodeNum(root,3)<<endl;
	cout<<getLeafNodeNum(root)<<endl;
	int height;
	if(isAVL(root,height))
		cout<<"YES"<<height<<endl;
	else
		cout<<"NO"<<height<<endl;
	return 0;
}
