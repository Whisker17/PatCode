#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <iostream>
#include <map>
#include <cmath>
using namespace std;

#define ll long long

struct Fraction{
	ll up,down;
};

ll gcd(ll a,ll b){
	if(b == 0)
		return a;
	return gcd(b,a%b);
}

Fraction reduction(Fraction a){
	if(a.down < 0){
		a.down = -a.down;
		a.up = -a.up;
	}
	if(a.up == 0){
		a.down = 1;
	}
	else{
		int tmp = gcd(a.up,a.down);
		a.up /= tmp;
		a.down /= tmp;
	}
	return a;
}

Fraction add(Fraction a,Fraction b){
	Fraction tmp;
	tmp.up = a.up*b.down + b.up*a.down;
	tmp.down = a.down*b.down;
	tmp = reduction(tmp);
	return tmp;
}

void showFraction(Fraction a){
	reduction(a);
	if(a.down == 1){
		printf("%lld\n",a.up);
	}
	else if(abs(a.up) > a.down){
		printf("%lld %lld/%lld\n",a.up/a.down,abs(a.up)%a.down,a.down);
	}
	else printf("%lld/%lld\n",a.up,a.down);
}

int main(int argc, char *argv[])
{
	int n;
	scanf("%d",&n);
	Fraction sum,temp;
	sum.up = 0,sum.down = 1;
	for(int i = 0;i<n;++i){
		scanf("%lld/%lld",&temp.up,&temp.down);
		sum = add(sum,temp);
	}	
	showFraction(sum);
	return 0;
}