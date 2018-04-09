#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <iostream>
#include <map>
#include <cmath>
using namespace std;
vector<int> node[105];
int hashTable[105]={0};

void dfs(int index,int level){
	++hashTable[level];
	for(int i = 0;i<node[index].size();++i){
		dfs(node[index][i],level+1);
	}
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
	int maxLevel=-1,nMax=0;
	for(int i = 1;i<105;++i){
		if(hashTable[i] > nMax){
			nMax = hashTable[i];
			maxLevel = i;
		}
	}
	printf("%d %d\n",nMax,maxLevel);
	return 0;
}