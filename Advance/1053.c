#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <iostream>
#include <map>
#include <cmath>
using namespace std;

#define maxn 105

struct Node{
	int val;
	vector<int> child;
}node[maxn];

int n,m,s;
int path[maxn];

bool cmp(int a,int b){
	return node[a].val > node[b].val;
}

void dfs(int index,int nodeSum,int sum){
	if(sum > s)
		return ;
	if(sum == s){
		if(node[index].child.size() == 0){
			for(int i = 0;i<nodeSum	;++i){
				printf("%d",node[path[i]].val);
				if(i < nodeSum-1)
					printf(" ");
				else printf("\n");
			}
		}
		return ;
	}
	for(int i = 0;i<node[index].child.size();++i){
		int child = node[index].child[i];
		path[nodeSum] = child;
		dfs(child,nodeSum+1,sum+node[child].val);
	}
}

int main(int argc, char *argv[])
{
	scanf("%d %d %d",&n,&m,&s);
	for(int i = 0;i<n;++i)
		scanf("%d",&node[i].val);
	int child,sId,k;
	for(int i = 0;i<m;++i){
		scanf("%d %d",&sId,&k);
		for(int j = 0;j<k;++j){
			scanf("%d",&child);
			node[sId].child.push_back(child);
		}
		sort(node[sId].child.begin(),node[sId].child.end(),cmp);
	}
	path[0] = 0;
	dfs(0,1,node[0].val);
	return 0;
}