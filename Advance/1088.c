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
	return b == 0 ? a : gcd(b,a%b);
}
	

Fraction reduction(Fraction a){
	if(a.down < 0){
		a.up = -a.up;
		a.down = -a.down;
	}
	if(a.up == 0)
		a.down = 1;
	else{
		ll tmp = gcd(abs(a.up),abs(a.down));
		a.up /= tmp;
		a.down /= tmp;	
	}
	return a;
}

Fraction add(Fraction a,Fraction b){
	Fraction sum;
	sum.up = a.up*b.down + a.down*b.up;
	sum.down = a.down*b.down;
	return reduction(sum);
}

Fraction minu(Fraction a,Fraction b){
	Fraction res;
	res.up = a.up*b.down - a.down*b.up;
	res.down = a.down*b.down;
	return reduction(res);
}

Fraction multi(Fraction a,Fraction b){
	Fraction res;
	res.up = a.up*b.up;
	res.down = a.down*b.down;
	return reduction(res);
}

Fraction divide(Fraction a,Fraction b){
	Fraction res;
	res.up = a.up*b.down;
	res.down = a.down*b.up;
	return reduction(res);
}

void showFraction(Fraction a){
	a = reduction(a);
	if(a.up < 0)
		printf("(");
	if(a.down == 1)
		printf("%lld",a.up);
	else if(abs(a.up) > a.down){
		printf("%lld %lld/%lld",a.up/a.down,abs(a.up)%a.down,a.down);
	}
	else{
		printf("%lld/%lld",a.up,a.down);
	}
	if(a.up < 0)
		printf(")");
}

int main(int argc, char *argv[])
{
	Fraction a,b;
	scanf("%lld/%lld %lld/%lld",&a.up,&a.down,&b.up,&b.down);
	showFraction(a);
	printf(" + ");
	showFraction(b);
	printf(" = ");
	showFraction(add(a,b));
	printf("\n");
	
	showFraction(a);
	printf(" - ");
	showFraction(b);
	printf(" = ");
	showFraction(minu(a,b));
	printf("\n");
	
	showFraction(a);
	printf(" * ");
	showFraction(b);
	printf(" = ");
	showFraction(multi(a,b));
	printf("\n");
	
	showFraction(a);
	printf(" / ");
	showFraction(b);
	printf(" = ");
	if(b.up == 0)
		printf("Inf");
	else 
		showFraction(divide(a,b));
	printf("\n");
	return 0;
}