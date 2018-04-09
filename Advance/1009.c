#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <iostream>
#include <map>
#include <cmath>
using namespace std;
struct node{
	int exp;
	double cor;
}poly[2005];
#define maxn 2005
int main(int argc, char *argv[])
{
	int n,m,a,cnt=0;
	double e,res[maxn]={0.0};
	scanf("%d",&m);
	for(int i = 0;i<m;++i){
		scanf("%d %lf",&poly[i].exp,&poly[i].cor);
	}	
	scanf("%d",&n);
	for(int i = 0;i<n;++i){
		scanf("%d %lf",&a,&e);
		for(int j = 0;j<m;++j){
			res[a + poly[j].exp] += poly[j].cor * e;
		}
	}
	for(int i = 0;i<maxn;++i){
		if(res[i] != 0.0)
			++cnt;
	}
	printf("%d",cnt);
	for(int i = maxn-1;i>=0;--i){
		if(res[i] != 0.0)
			printf(" %d %.1f",i,res[i]);
	}
	return 0;
}