#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <iostream>
#include <map>
#include <cmath>
using namespace std;
const int maxn = 100005;

vector<int> res[maxn];
char str[maxn][5];

bool cmp(int a,int b){
	return strcmp(str[a],str[b])<0;
}

int main(int argc, char *argv[])
{
	int n,k,ni,index;
	scanf("%d %d",&n,&k);
	for(int i = 0;i<n;++i){
		scanf("%s %d",str[i],&ni);
		for(int j = 0;j<ni;++j){
			scanf("%d",&index);
			res[index].push_back(i);
		}
	}
	for(int i = 1;i<=k;++i){
		printf("%d %d\n",i,res[i].size());
		sort(res[i].begin(),res[i].end(),cmp);
		for(int j = 0;j<res[i].size();++j){
			printf("%s\n",str[res[i][j]]);
		}
	}
	return 0;
}