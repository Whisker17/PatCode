#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <iostream>
#include <map>
#include <cmath>
using namespace std;

int n;

string change(string str,int &e){
	int cnt=0,tmp = 0;
	while(str[0] == '0' && str.size() > 0){
		str.erase(str.begin());
	}
	if(str[0] == '.'){
		str.erase(str.begin());
		while(str[0] == '0' && str.size() > 0){
			str.erase(str.begin());
			--e;
		}
	}
	else{
		while(cnt < str.size() && str[cnt] != '.'){
			++e;
			++cnt;
		} 
		if(str[cnt] == '.'){
			str.erase(str.begin()+cnt);
		}
	}
	if(str.size() == 0){
		e = 0;
	}
	cnt = 0;
	string res;
	while(tmp < n){
		if(cnt < str.size())
			res += str[cnt++];
		else res += '0';
		++tmp;
	}
	return res;
}

int main(int argc, char *argv[])
{
	string str1,str2,res1,res2;
	scanf("%d",&n);
	cin>>str1>>str2;
	int e1=0,e2=0;
	res1 = change(str1,e1);
	res2 = change(str2,e2);
	if(res1 == res2 && e1 == e2){
		printf("YES 0.");
		cout<<res1;
		printf("*10^%d\n",e1);
	}
	else{
		printf("NO 0.");
		cout<<res1;
		printf("*10^%d 0.",e1);
		cout<<res2;
		printf("*10^%d\n",e2);
	}
	return 0;
}