1.给前序遍历 中序遍历 构建二叉树。
struct BTN{
	int value;
	BTN* left;
	BTN* right;
};

BTN* build(int* a,int* b,int n){
	if(a==NULL||b==NULL||n<=0)
		return NULL;
	BTN* root = new BTN;
	root->value = a[0];
	root->left = NULL;
	root->right = NULL;
	
	int pos = -100;
	for(int i = 0 ; i < n ; ++i){
		if(b[i] == root->value){
			pos = i;
			break;
		}
	}
	
	if(-100 == pos)
		return NULL;
	int n_left = pos;
	int* a_left = a + 1;
	int* b_left = b;
	root->left = build(a_left,b_left,n_left);
	
	int n_right = n-pos-1;
	int* a_right = a+1+n_left;
	int* b_right = b+n_left+1;
	root->right = build(a_right,b_right,n_right);
	
	return root;
}




2  二叉树从根节点到叶子节点是否存在一条路径，使得路径上的值的和等于给定的值。
bool  pathExist(BIN * root, int target, int &num){

	if(NULL==root)
		return false;
	num+=root->value;
	if(num==target&&root->left==NULL&&root->right==NULL){
		return true;
	}
	flag  = pathExist(root->left,target,num);
	if (flag) {
		return flag;
	}
	//num-=root->left->value;
	flag  = pathExist(root->right,target,num);
	num-=root->value;
	return flag;
}