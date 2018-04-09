#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <iostream>
#include <map>
#include <cmath>
using namespace std;

#define maxn 100005

struct Node{
	double val;
	vector<int> child;
}node[maxn];

int n;
double ans=0.0,p,r;
void dfs(int index,int depth){
	if(node[index].child.size() == 0){
		ans += node[index].val*pow(1+r,depth);
		return ;
	}
	for(int i = 0;i<node[index].child.size();++i){
		dfs(node[index].child[i],depth+1);
	}
}

int main(int argc, char *argv[])
{
	int k,child,m;
	scanf("%d%lf%lf",&n,&p,&r);
	r /= 100;
	for(int i = 0;i<n;++i){
		scanf("%d",&m);
		if(m == 0){
			scanf("%lf",&node[i].val);
		}
		else{
			for(int j = 0;j<m;++j){
				scanf("%d",&child);
				node[i].child.push_back(child);
			}
		}
		
	}
	dfs(0,0);
	printf("%.1f\n",p*ans);
	return 0;
}