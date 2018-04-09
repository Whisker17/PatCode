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
	ll num1,num2,res,a;
	scanf("%d",&n);
	for(int i = 1;i<=n;++i){
		scanf("%lld %lld %lld",&num1,&num2,&res);
		printf("Case #%d: ",i);
		a = num1 + num2;
		if((num1 < 0 && num2 < 0 && a >= 0))
			printf("false\n");
	 	else if(num1 > 0 && num2 > 0 && a <= 0)
	 		printf("true\n");
		else if(num1+num2 > res) 
			printf("true\n");
		else printf("false\n");
	}
	return 0;
}