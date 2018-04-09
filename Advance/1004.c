#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <iostream>
#include <map>
#include <cmath>
using namespace std;

#define maxn 105

vector<int> node[maxn];
int leaf[maxn]={0},maxH=1;

void dfs(int index,int level){
	maxH = max(level,maxH);
	if(node[index].size() == 0){
		++leaf[level];
		return ;
	}
	for(int i = 0;i<node[index].size();++i)
		dfs(node[index][i],level+1);
}

int main(int argc, char *argv[])
{
	int n,m,parent,k,child;
	scanf("%d %d",&n,&m);
	for(int i = 0;i<m;++i){
		scanf("%d%d",&parent,&k);
		for(int j = 0;j<k;++j){
			scanf("%d",&child);
			node[parent].push_back(child);
		}
	}
	dfs(1,1);
	for(int i = 1;i<=maxH;++i){
		printf("%d",leaf[i]);
		if(i != maxH)
			printf(" ");
	}
	return 0;
}