#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <iostream>
#include <map>
#include <cmath>
using namespace std;

#define maxn 55

char mp[5]={'S','H','C','D','J'};

int main(int argc, char *argv[])
{
	int n;
	int start[maxn],next[maxn],end[maxn];
	scanf("%d",&n);
	for(int i = 1;i<=54;++i)
		start[i] = i;
	for(int i = 1;i<=54;++i){
		scanf("%d",&next[i]);
	}
	while(n--){
		for(int i = 1;i<=54;++i)
			end[next[i]] = start[i];
		for(int i = 1;i<=54;++i)
			start[i] = end[i];
	}
	for(int i = 1;i<=54;++i){
		start[i]--;
		printf("%c%d",mp[start[i]/13],start[i]%13+1);
		if(i < 54)
			printf(" "); 
	}
	return 0;
}