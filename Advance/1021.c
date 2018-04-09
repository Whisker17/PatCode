#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <iostream>
#include <map>
#include <cmath>
using namespace std;

#define maxn 100005

int n,father[maxn],maxH=0;
bool isRoot[maxn];
vector<int> nMap[maxn],temp,ans;

int findFather(int x){
	int a = x;
	while(x != father[x]){
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
	if(faA != faB){
		father[faA] = faB;
	}
}

void init(){
	for(int i = 1;i<=n;++i){
		father[i] = i;
	}
}

int calBlocks() {
    int Block = 0;
    for(int i = 1; i <= n; i++) {
        isRoot[findFather(i)] = true;
    }
    for(int i = 1; i <= n; i++) {
        Block += isRoot[i];
    }
    return Block;
}

void dfs(int index,int height,int pre){
	if(height > maxH){
		maxH = height;
		temp.clear();
		temp.push_back(index);
	}
	else	
		temp.push_back(index);
	for(int i = 0;i<nMap[index].size();++i){
		if(nMap[index][i] == pre)
			continue;
		dfs(nMap[index][i],height+1,index);
	}
}

int main(int argc, char *argv[])
{
	int st,en;
	scanf("%d",&n);
	init();
	for(int i = 1;i<n;++i){
		scanf("%d %d",&st,&en);
		nMap[st].push_back(en);
		nMap[en].push_back(st);
		Union(st,en);
	}	
	int blocks = calBlocks();
	if(blocks != 1){
		printf("Error: %d components\n",blocks);
		return 0;
	}
	dfs(1,1,-1);
	ans = temp;
	dfs(ans[0],1,-1);
	for(int i = 0;i<temp.size();++i)
		ans.push_back(temp[i]);
	sort(ans.begin(),ans.end());
	printf("%d\n",ans[0]);
	for(int i = 1;i<ans.size();++i){
		if(ans[i] != ans[i-1])
			printf("%d\n",ans[i]);
	}
	return 0;
}