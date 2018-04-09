#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <iostream>
#include <map>
#include <cmath>
using namespace std;

#define maxn 100005

int main(int argc, char *argv[])
{
	int dp[maxn],n,num[maxn],st[maxn];
	bool flag = false;
	scanf("%d",&n);
	for(int i = 0;i<n;++i){
		scanf("%d",&num[i]);
		if(num[i]>=0)
			flag = true;
	}
	if(!flag){
		printf("0 %d %d\n",num[0],num[n-1]);
		return 0;
	}
	dp[0] = num[0];
	for(int i = 1;i<n;++i){
		if(num[i] < dp[i-1]+num[i]){
			dp[i] = num[i]+dp[i-1];
			st[i] = st[i-1];
		}
		else{
			dp[i] = num[i];
			st[i] = i;
		}
	}
	int k = 0;
	for(int i = 1;i<n;++i){
		if(dp[i] > dp[k]){
			k = i;
		}
	}
	printf("%d %d %d\n",dp[k],num[st[k]],num[k]);
	return 0;
}