#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <iostream>
#include <map>
#include <cmath>
using namespace std;

#define maxn 1000005

int main(int argc, char *argv[])
{
	int n,m,tmp,nMax;
	int cnt[maxn];
 	scanf("%d %d",&n,&m);
 	for(int i = 0;i<n;++i){
	 	for(int j = 0;j<m;++j){
	 		scanf("%d",&tmp);
	 		if(i == 0 && j == 0){
		 		nMax = tmp;
		 		++cnt[tmp];
		 		continue;
		 	}
		 	if(tmp == nMax)
	 			++cnt[tmp];
 			else{
			 	--cnt[nMax];
			 	if(cnt[nMax]<0){
	 				nMax = tmp;
	 				++cnt[nMax];
	 			}
			 }
	 	}
	 }
 	printf("%d",nMax);
	return 0;
}