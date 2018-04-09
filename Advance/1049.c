#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <iostream>
#include <map>
#include <cmath>
using namespace std;

int main(int argc, char *argv[])
{
	int n,a=1,sum=0;
	int left,now,right;
	scanf("%d",&n);
	while(n/a){
		left = n/(a*10);
		now = n/a %10;
		right = n%a;
		if(now == 0){
			sum += left * a;
		}
		else if(now == 1){
			sum += left*a+right+1;
		}
		else sum += (left+1)*a;
		a *= 10;
	}
	printf("%d\n",sum);
	return 0;
}