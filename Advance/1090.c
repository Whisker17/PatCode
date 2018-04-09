#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <iostream>
#include <map>
#include <cmath>
using namespace std;

#define maxn 100005

int n,maxDepth=0,num=0;
double p,r;
vector<int> child[maxn];

void dfs(int index,int depth){
	if(child[index].size() == 0){
		if(depth > maxDepth){
			maxDepth = depth;
			num = 1;
		}
		else if(depth == maxDepth)
			++num;
		return ;
	}
	for(int i = 0;i<child[index].size();++i)
		dfs(child[index][i],depth+1);
}

int main(int argc, char *argv[])
{
	int father,root;
	scanf("%d%lf%lf",&n,&p,&r);
	r /= 100;
	for(int i = 0;i<n;++i){
		scanf("%d",&father);
		if(father != -1)
			child[father].push_back(i);
		else root = i;
	}
	dfs(root,0);
	printf("%.2f %d\n",p*pow(1+r,maxDepth),num);
	return 0;
}