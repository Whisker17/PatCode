#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <iostream>
#include <map>
#include <cmath>
using namespace std;

#define ll long long

int main(int argc, char *argv[])
{
	int n;
	scanf("%lld",&n);
	ll sqr = (ll)sqrt(n),ansStart = 1,maxLen = 0;
	for(ll i = 2;i<=sqr;++i){
		ll temp = 1,j = i;
		while(1){
			temp *= j;
			if(n%temp != 0)
				break;
			if(j+1-i > maxLen){
				maxLen = j+1-i;
				ansStart = i;
			}
			++j;
		}
	}
	if(maxLen == 0)
		printf("1\n%lld\n",n);
	else {
		printf("%lld\n",maxLen);
		ll tmp = maxLen;
		for(ll i = 0;i<maxLen;++i){
			printf("%lld",ansStart+i);
			if(i < maxLen-1)
				printf("*");
		}
	}
	return 0;
}