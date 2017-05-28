#include<iostream>

using namespace std;

int main() {

	int a,b;
	cin>>a>>b;
	int k = 1;
	while(a>=0 && b>=0) {
		a-=k++;
		b-=k++;
	}
	if(a<0) cout<<"Vladik";
	else cout<<"Valera";
	return 0;
}

