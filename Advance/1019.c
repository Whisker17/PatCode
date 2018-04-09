#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <iostream>
#include <map>
#include <cmath>
using namespace std;

bool isPalindromic(vector<int> a){
	int len = a.size();
	for(int i = 0;i<=len/2;++i){
		if(a[i] != a[len-i-1])
			return false;
	}
	return true;
}

int main(int argc, char *argv[])
{
	int n,p;
	vector<int> ans;
	scanf("%d %d",&n,&p);
	do{
		ans.push_back(n%p);
		n /= p;
	}while(n);
	int len = ans.size();
	if(isPalindromic(ans))
		printf("Yes\n");
	else printf("No\n");
	for(int i = len-1;i>=0;--i){
		printf("%d",ans[i]);
		if(i != 0)
			printf(" ");
	}
	return 0;
}