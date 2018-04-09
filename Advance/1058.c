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
	ll a1,a2,b1,b2,c1,c2;
	ll sum=0;
	scanf("%lld.%lld.%lld %lld.%lld.%lld",&a1,&b1,&c1,&a2,&b2,&c2);
	sum = c1+b1*29+a1*29*17+c2+b2*29+a2*29*17;
	a1 = sum/29/17;
	b1 = (sum%(17*29))/29;
	c1 = (sum%(17*29))%29; 
	printf("%lld.%lld.%lld",a1,b1,c1);
	return 0;
}