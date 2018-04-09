#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <iostream>
#include <map>
#include <cmath>
using namespace std;

#define maxn 1005

char str[maxn];
int dp[maxn][maxn];

int main(int argc, char *argv[])
{
	gets(str);
	int len = strlen(str),ans=1;
	for(int i = 0;i<len;++i){
		dp[i][i] = 1;
		if(i < len-1){
			if(str[i] == str[i+1]){
				dp[i][i+1] = 1;
				ans = 2;
			}
		}
	}
	for(int L = 3;L<=len;++L){
		for(int i = 0;i+L-1 < len;++i){
			int j = i+L-1;
			if(str[i] == str[j] && dp[i+1][j-1] == 1){
				ans = L;
				dp[i][j] = 1;
			}
		}
	}
	printf("%d\n",ans);
	return 0;
}