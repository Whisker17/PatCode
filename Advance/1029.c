#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <iostream>
#include <map>
#include <cmath>
using namespace std;

#define maxn 1000005
#define INF 0x7fffffff

int main(int argc, char *argv[])
{
	int n,m;
	int num1[maxn],num2[maxn];
	scanf("%d",&n);
	for(int i = 0;i<n;++i)
		scanf("%d",&num1[i]); 
	scanf("%d",&m);
	for(int i = 0;i<m;++i)
		scanf("%d",&num2[i]);
	num1[n] = num2[m] = INF;
	int i=0,j=0;
	int sAim = (n+m-1)/2;
	/*while(i<=n && j<=m){
		if(num1[i] < num2[j]){
			++i;
			if(i+j == sAim){
				printf("%d\n",num1[i]);
				return 0;
			}
		}
		else{
			++j;
			if(i+j == sAim){
				printf("%d\n",num2[j]);
				return 0;
			}
		} 
	}*/
	int cnt = 0;
	while(cnt < sAim){
		if(num1[i] < num2[j])
			++i;
		else ++j;
		++cnt;
	}
	if(num1[i] < num2[j])
		printf("%d\n",num1[i]);
	else printf("%d\n",num2[j]);
	return 0;
}