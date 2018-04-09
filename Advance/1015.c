#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <iostream>
#include <map>
#include <cmath>
using namespace std;

#define maxn 1000005

bool isPrime(int x){
	if(x <= 1)
		return false;
	int sqr = (int) sqrt(x);
	for(int i = 2;i<=sqr;++i){
		if(x % i == 0)
			return false;
	}
	return true;
}

int main(int argc, char *argv[])
{
	int n,radix,cnt;
	int num[maxn];
	while(scanf("%d",&n) && n > 0){
		scanf("%d",&radix);
		cnt = 0;
		if(!isPrime(n)){
			printf("No\n");
		}
		else{
			do{
				num[cnt++] = n%radix;
				n /= radix;
			}while(n);
			for(int i = 0;i<cnt;++i){
				n = radix * n + num[i];
			}
			if(isPrime(n))
				printf("Yes\n");
			else printf("No\n");
		}
	}
	return 0;
}