#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <iostream>
#include <map>
#include <cmath>
using namespace std;

#define maxn 10005

int father[maxn],isRoot[maxn]={0},course[maxn]={0};
int n,k,h;

int findFather(int x){
	int a = x;
	while(father[x] != x){
		x = father[x];
	}
	while(a != father[a]){
		int z = a;
		a = father[a];
		father[z] = x;
	}
	return x;
}

void Union(int a,int b){
	int faA = findFather(a);
	int faB = findFather(b);
	if(faA != faB)
		father[faA] = faB;
}

void init(){
	for(int i = 1;i<=n;++i){
		father[i] = i;
		isRoot[i] = false;
	}
}

bool cmp(int a,int b){
	return a>b;
}

int main(int argc, char *argv[])
{
	scanf("%d",&n);
	init();
	for(int i = 1;i<=n;++i){
		scanf("%d: ",&k);
		for(int j = 0;j<k;++j){
			scanf("%d",&h);
			if(course[h] == 0)
				course[h] = i;
			Union(i,findFather(course[h]));
		}
	} 	
	for(int i = 1;i<=n;++i)
		isRoot[findFather(i)]++;
	int ans = 0;
	for(int i = 1;i<=n;++i){
		if(isRoot[i] != 0)
			++ans;
	}
	printf("%d\n",ans);
	sort(isRoot+1,isRoot+1+n,cmp);
	for(int i = 1;i<=ans;++i){
		printf("%d",isRoot[i]);
		if(i<ans)
			printf(" ");
	}
	return 0;
}