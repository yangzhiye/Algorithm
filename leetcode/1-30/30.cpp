#include<iostream>
#include<string>
#include<map>
#include<vector>
using namespace std;

class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        int list_size = words.size();
        if(list_size==0) return vector<int>();
        int word_size = words[0].size();
        map<string,int> word_count;
        string word;
        vector<int> ans;
        map<string,int> counting;
        int j;
        for(int i = 0 ; i < list_size ; ++i) ++word_count[words[i]];
        for(int i =0 ; i <= s.size()-(list_size*word_size) ; ++i){
            counting.clear();
            for(j = 0 ; j < list_size ; ++j){
                word = s.substr(i+j*word_size,3);
                if(word_count.find(word)!=word_count.end()){
                    ++counting[word];
                    if(counting[word]>word_count[word])
                        break;
                }
                else{
                    break;
                }
            }
            if(j==list_size)
                ans.push_back(i);
        }
    }
};

int main(){

    return 0;
}

