#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <iostream>
#include <map>
#include <cmath>
using namespace std;

bool cmp(int a,int b){
	return a>b;
}

void numToStr(int n,int num[]){
	for(int i = 0;i<4;++i){
		num[i] = n%10;
		n /= 10;
	}
}

int strToNum(int num[]){
	int x=0;
	for(int i = 0;i<4;++i){
		x = x*10 + num[i];
	}
	return x;
}

int main(int argc, char *argv[])
{
	int n,nMin,nMax;
	scanf("%d",&n);
	int num[5];
	while(1){
		numToStr(n,num);
		sort(num,num+4);
		nMin = strToNum(num);
		sort(num,num+4,cmp);
		nMax = strToNum(num);
		n = nMax - nMin;
		printf("%04d - %04d = %04d\n",nMax,nMin,n);
		if(n == 0 || n == 6174)
			return 0;
	}
	return 0;
}