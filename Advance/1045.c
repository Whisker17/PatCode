#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <iostream>
#include <map>
#include <cmath>
using namespace std;

#define maxc 205
#define maxn 10005

int hashTable[maxc];
int a[maxn],dp[maxn];

int main(int argc, char *argv[])
{
	int n,m,x;
	scanf("%d%d",&n,&m);
	memset(hashTable,-1,sizeof(hashTable));
	for(int i = 0;i<m;++i){
		scanf("%d",&x);
		hashTable[x] = i;
	}
	int L,num=0;
	scanf("%d",&L);
	for(int i = 0;i<L;++i){
		scanf("%d",&x);
		if(hashTable[x] >= 0)
			a[num++] = hashTable[x];
	}
	int ans = -1;
	for(int i = 0;i<num;++i){
		dp[i] = 1;
		for(int j = 0;j<i;++j){
			if(a[j] <= a[i] && dp[i] < dp[j]+1)
				dp[i] = dp[j]+1;
		}
		ans = max(ans,dp[i]);
	}
	printf("%d\n",ans);
	return 0;
}