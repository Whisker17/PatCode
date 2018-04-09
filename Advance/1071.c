#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <iostream>
#include <map>
#include <cmath>
using namespace std;

bool isChecked(char c){
	if(c>='0' && c<='9')
		return true;
	if(c>='a' && c<='z')
		return true;
	if(c>='A' && c<='Z')
		return true;
	return false;
}

int main(int argc, char *argv[])
{
	map<string,int> res;
	string str;
	getline(cin,str);
	int len = str.size();
	int index=0;
	while(index < len){
		string word;
		while(index<len && isChecked(str[index])){
			if(str[index]>='A' && str[index]<='Z')
				str[index] += 32;
			word += str[index];
			++index;
		}
		if(word != ""){
			if(res.find(word) != res.end())
				++res[word];
			else res[word] = 1;
		}
		while(index < len && !isChecked(str[index]))
			++index;
	}
	string ans;
	int nMax = 0;
	for(map<string,int>::iterator iter = res.begin();iter != res.end();++iter){
		if(iter->second > nMax){
			nMax = iter->second;
			ans = iter->first;
		}
	}
	cout<<ans<<" "<<nMax<<endl;
	return 0;
}