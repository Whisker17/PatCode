#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <iostream>
#include <map>
#include <cmath>
using namespace std;

#define maxn 100005

int main(int argc, char *argv[])
{
	int n,ans=0,tmp;
	int pos[maxn];
	scanf("%d",&n);
	int left = n-1;
	for(int i = 0;i<n;++i){
		scanf("%d",&tmp);
		pos[tmp] = i;
		if(tmp == i && tmp != 0)
			--left;
	}
	int k = 1;
	while(left > 0){
		if(pos[0] == 0){
			while(k < n){
				if(pos[k] != k){
					swap(pos[0],pos[k]);
					++ans;
					break;
				}
				++k;
			}
		}
		while(pos[0] != 0){
			swap(pos[0],pos[pos[0]]);
			++ans;
			--left;
		}
	}
	printf("%d\n",ans);
	return 0;
}