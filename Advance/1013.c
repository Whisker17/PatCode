#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <iostream>
#include <map>
#include <cmath>
using namespace std;

#define maxn 1005

bool vis[maxn];
vector<int> nMap[maxn];
int query;

void dfs(int index){
	if(index == query)
		return ;
	vis[index] = true;
	for(int i = 0;i<nMap[index].size();++i){
		if(!vis[nMap[index][i]])
			dfs(nMap[index][i]);
	}
}

int main(int argc, char *argv[])
{
	int n,m,k,st,en;
	scanf("%d %d %d",&n,&m,&k);
	for(int i = 0;i<m;++i){
		scanf("%d%d",&st,&en);
		nMap[st].push_back(en);
		nMap[en].push_back(st);
	}
	for(int i = 0;i<k;++i){
		scanf("%d",&query);
		memset(vis,false,sizeof(vis));
		int block=0;
		for(int j = 1;j<=n;++j){
			if(j != query && !vis[j]){
				dfs(j);
				++block;
			}
		}
		printf("%d\n",block-1);
	}
	return 0;
}