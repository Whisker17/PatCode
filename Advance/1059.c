#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <iostream>
#include <map>
#include <cmath>
using namespace std;

#define maxn 100005

struct Num{
	int val,cnt;
}num[10];

int prime[maxn];

bool isPrime(int x){
	if(x <= 1)
		return false;
	int sqr = (int)sqrt(x);
	for(int i = 2;i<=sqr;++i){
		if(x % i == 0)
			return false;
	}
	return true;
}

int tmp = 0;

void findPrime(){
	for(int i = 1;i<maxn;++i){
		if(isPrime(i))
			prime[tmp++] = i;
	}
}

int main(int argc, char *argv[])
{
	findPrime();
	int n,count=0;
	scanf("%d",&n);
	if(n == 1){
		printf("1=1\n");
		return 0;
	}
	if(n == 0){
		printf("0=0\n");
		return 0;
	}
	printf("%d=",n);
	int sqr = (int)sqrt(n);
	for(int i = 0;i<tmp && prime[i] <= sqr;++i){
		if(n % prime[i] == 0){
			num[count].val = prime[i];
			num[count].cnt = 0;
			while(n % prime[i] == 0){
				++num[count].cnt;
				n /= prime[i];
			}
			++count;
		}
		if(n == 1)
			break;
	}
	if(n != 1){
		num[count].val = n;
		num[count++].cnt = 1;
	}
	for(int i = 0;i<count;++i){
		if(i>0)
			printf("*");
		printf("%d",num[i].val);
		if(num[i].cnt > 1)
			printf("^%d",num[i].cnt);
	}
	return 0;
}