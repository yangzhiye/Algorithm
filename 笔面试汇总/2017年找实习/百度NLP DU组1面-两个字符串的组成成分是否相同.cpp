//给定str1="hello", str2="helol"两个单词，判断str2是str1是否是通过交换字母顺序得到的

bool check(string s1,string s2){
	if(s1.empty()&&s2.empty())
		return true;
	if(s1.empty()||s2.empty()||s1.size()!=s2.size())
		return false;
	map<char,int> MP1,MP2;
	for(int i = 0 ; i < s1.size() ; ++i){
		if(MP1.find(s1[i])==MP1.end()){
			MP1[s1[i]] = 1;
		}else{
			MP1[s1[i]]++;
		}
		if(MP2.find(s2[i])==MP2.end()){
			MP2[s2[i]] = 1;
		}else{
			MP2[s2[i]]++;
		}
	}
	auto it = MP1.begin();
	while (it!=MP1.end()) {
		if(MP2[it->first]!=it->second)
			return false;
	}
	if(it==MP1.end())
		return true;
}