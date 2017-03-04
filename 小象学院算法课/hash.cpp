#include<iostream>
#include<cstdio>
#include<cstdlib>
using namespace std;

class hash_node{
public:
	hash_node(){
		this->data = "";
		this->next = NULL;
	}
	~hash_node(){
		/* to do something */
	}
	void setData(std::string data){
		this->data = data;
	}
	std::string getData(){
		return this->data;
	}
	void setNext(hash_node *next){
		this->next = next;
	}
	hash_node *getNext(){
		return this->next;
	}
private:
	std::string data;
	hash_node *next;

};

class hash_table{
public:
	hash_table(int32_t hash_table_len,int32_t node_pool_len){
		this->hash_table_len = hash_table_len;
		this->node_pool_len = node_pool_len;
		this->node_pool_cnt = 0;
		try{
			this->hash_table_main = new hash_node*[this->hash_table_len];
			memset(this->hash_table_main,0,sizeof(hash_node *)*this->hash_table_len);
			this->hash_node_pool = new hash_node[this->node_pool_len];
		}catch(const bad_alloc & e){
			std::cerr << "there is no more place"<<endl;
		}
	}	
	~hash_table(){
		delete[] this->hash_table_main;
		delete[] this->hash_node_pool;
	}
	bool insert(std::string str,bool &is_uniq){
		if(true == this->search(str)){
			is_uniq = false;
			return true;
		}
		hash_node *p, *q = this->GetNewNode();
		if(NULL == q) return false;
		int32_t hash_index = this->GetHashIndex(str);
		p = this->hash_table_main[hash_index];
		q->setData(str);
		q->setNext(p);
		this->hash_table_main[hash_index] = q;
		is_uniq = true;
		return true;
	}

	bool search(std::string str){
		int32_t hash_index = this->GetHashIndex(str);
		hash_node *p = this-> hash_table_main[hash_index];
		while(p != NULL){
			if(p->getData() == str) return true;
			p = p->getNext();
		}
		return false;
	}

private:
	hash_node **hash_table_main;
	hash_node *hash_node_pool;

	int32_t hash_table_len,node_pool_len,node_pool_cnt;

	static int32_t BKDRHash(std::string str){
		int32_t hash = 0,seed = 131;
		for(int i = 0 ; i < str.length() ; i++){
			hash = hash * seed + str[i];
		}
		return (hash & 0x7fffffff);
	}


	int32_t GetHashIndex(std::string str){
		if(this->hash_table_len == 0) return 0;
		return (hash_table::BKDRHash(str) % hash_table_len);
	}

	hash_node *GetNewNode(){
		if(this->node_pool_cnt >= this->node_pool_len) return NULL;
		return &this->hash_node_pool[this->node_pool_cnt++];
	}
};

int main(){
	hash_table ht(100,1000);
	bool is_uniq,flag;
	ht.insert("AOA",is_uniq);
	std::cout << "insert AOA" << is_uniq <<endl;
	ht.insert("Huge",is_uniq);
	std::cout << "insert Huge" << is_uniq <<endl;
	flag = ht.search("AOA");
	std::cout << "search AOA" <<flag<<endl;
	ht.insert("AOA",is_uniq);
	std::cout << "insert AOA" << is_uniq <<endl;
	return 0;
}
