#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <iostream>
#include <map>
#include <cmath>
using namespace std;

#define maxn 100005

bool cmp(string a,string b){
	return a+b < b+a;
}

int main(int argc, char *argv[])
{
	int n;
	string num[maxn];
	scanf("%d",&n);
	for(int i = 0;i<n;++i){
		cin>>num[i];
	}
	sort(num,num+n,cmp);
	string ans;
	for(int i = 0;i<n;++i){
		ans += num[i];
	}
	while(ans.size() && ans[0] == '0')
		ans.erase(ans.begin());
	if(ans.size() == 0)
		cout<<0;
	else cout<<ans;
	return 0;
}