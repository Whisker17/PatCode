#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <iostream>
#include <map>
#include <cmath>
using namespace std;

const int maxn = 26*26*26*10+1;
	
vector<int> res[maxn];

int getId(char str[]){
	int res=0;
	for(int i = 0;i<3;++i){
		res = res*26 + (str[i]-'A'); 
	}
	res = res*10 + str[3]-'0';
	return res;
}

int main(int argc, char *argv[])
{
	int n,k,index,ni;
	char str[5];
	scanf("%d %d",&n,&k);
	for(int i = 0;i<k;++i){
		scanf("%d %d",&index,&ni);
		for(int j = 0;j<ni;++j){
			scanf("%s",str);
			res[getId(str)].push_back(index);
		}
	}
	for(int i = 0;i<n;++i){
		scanf("%s",str);
		int sId = getId(str);
		sort(res[sId].begin(),res[sId].end());
		int len = res[sId].size();
			printf("%s %d",str,len);
		for(int j = 0;j<len;++j){
			printf(" %d",res[sId][j]);
		}
		printf("\n");
	}
	return 0;
}