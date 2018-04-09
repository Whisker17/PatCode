#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <iostream>
#include <map>
#include <cmath>
using namespace std;
int main(int argc, char *argv[])
{
	int n,res,tmp,sum=0,st,end,m;
	int dis[100005];
	scanf("%d",&n);
	for(int i = 1;i<=n;++i){
		scanf("%d",&tmp);
		sum += tmp;
		dis[i] = sum;
	}
	scanf("%d",&m);
	for(int i = 1;i<=m;++i){
		scanf("%d %d",&st,&end);
		if(end < st) swap(st,end);
		int temp = dis[end-1]-dis[st-1];
		res = min(temp,sum-temp);
		printf("%d\n",res);
	}
	return 0;
}