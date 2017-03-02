/*
	实现一个数据结构，有set(index,value),get(index,value),setAll(value)三种操作
	使得get(index,value)时候能获得正确的结果并且setAll尽量快
*/

#include <iostream>
#define N 10
#define MAX 1000000
using namespace std;

int flag_all = 0;
int flag_max = 0;
double all_data = 0;
pair<double,int> data[N];

void init(){
	for(int i = 0 ; i< N;++i){
		data[i].first = 0.0;
		data[i].second = 0;
	}
}

void reset(){
	for(int i = 0 ; i < N ;++i){
		if(data[i].second<flag_all){
			data[i].first = all_data;
		}
		data[i].second = 0;
	}
	flag_all=0;
	all_data=0;
	flag_max=0;
}

void set(int index,double value){
	data[index].first = value;
	data[index].second = flag_all+1;
	if(flag_max<data[index].second){
		flag_max = data[index].second;
		if(flag_max==MAX)
			reset();
	}
}

void setAll(int value){
	all_data = value;
	flag_all = flag_max+1;
	flag_max++;
	if(flag_max==MAX)
		reset();
}

int get(int index){
	if(data[index].second>=flag_all){
		return data[index].first;
	}else{
		return all_data;
	}
}

void print(){
	for(int i = 0 ; i <N;++i){
		cout<<data[i].first<<" ";
	}
	cout<<endl;
}
int main(int argc, char *argv[]) {
	init();
	set(1,5);
	print();
	set(2,5);
	print();
	setAll(3);
	print();
	cout<<get(2)<<endl;
	return 0;
}