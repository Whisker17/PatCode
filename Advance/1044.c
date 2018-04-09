#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <iostream>
#include <map>
#include <cmath>
using namespace std;

#define maxn 100005

int dp[maxn]={0};

int binarySearch(int low,int high,int x){
	int mid;
	while(low < high){
		mid = (low + high)/2;
		if(x >= dp[mid])
			low = mid + 1;
		else high = mid;
	}
	return low;
}

int main(int argc, char *argv[])
{
	int n,m,nearS=maxn;
	scanf("%d %d",&n,&m);
	for(int i = 1;i<=n;++i){
		scanf("%d",&dp[i]);
		dp[i] += dp[i-1];
	}
	for(int i = 1;i<=n;++i){
		int j = binarySearch(i,n+1,dp[i-1]+m);
		if(dp[j-1] - dp[i-1] == m){
			nearS = m;
			break;
		}
		else {
			if(j <= n && dp[j] - dp[i-1] < nearS)
				nearS = dp[j] - dp[i-1];
		}
	}
	for(int i = 1;i<=n;++i){
		int j = binarySearch(i,n+1,dp[i-1]+nearS);
		if(dp[j-1] - dp[i-1] == nearS)
			printf("%d-%d\n",i,j-1);
	}
	return 0;
}