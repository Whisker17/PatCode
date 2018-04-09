#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <iostream>
#include <map>
#include <cmath>
using namespace std;
#define maxn 1005
int main(int argc, char *argv[])
{
	double res[maxn]={0.0};
	int n,m,a1,a2,cnt=0;
	double e1,e2;
	scanf("%d",&n);
	for(int i = 0;i<n;++i){
		scanf("%d %lf",&a1,&e1);
		res[a1] = e1;
	}
	scanf("%d",&m);
	for(int i = 0;i<m;++i){
		scanf("%d %lf",&a2,&e2);
		res[a2] += e2;
	}
	for(int i = 0;i<maxn;++i){
		if(res[i] != 0)
			++cnt;
	}
	printf("%d",cnt);
	for(int i = maxn-1;i>=0;--i){
		if(res[i] != 0.0)
			printf(" %d %.1f",i,res[i]);
	}
	return 0;
}