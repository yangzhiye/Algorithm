#include<iostream>
#include<stack>
using namespace std;

bool judge_matching(std::string seq)
{
	std::stack<char> stack_data;
	for(uint32_t i = 0 ; i < seq.length() ; i++)
	{
		if(seq[i] == '(') stack_data.push('(');
		else if (stack_data.empty()) return false;
		else stack_data.pop();
	}
	if(!stack_data.empty()) return false;
	return true;
}

int main()
{
	std::string str1 = "()()(())((()))";  // true
	std::string str2 = "((())))()(()()";  // false
	std::cout<<"str1 is"<<judge_matching(str1)<<endl;
	std::cout<<"str2 is"<<judge_matching(str2)<<endl;
	return 0;
}
