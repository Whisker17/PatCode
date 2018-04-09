#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <iostream>
#include <map>
#include <cmath>
using namespace std;

struct Moon{
	double price,num;
	double avg;
}moon[1000005];

bool cmp(Moon a,Moon b){
	return a.avg > b.avg;
}

int main(int argc, char *argv[])
{
	int n;
	double ans=0.00,d;
	scanf("%d %lf",&n,&d);
	for(int i = 0;i<n;++i){
		scanf("%lf",&moon[i].num);
	}
	for(int i = 0;i<n;++i){
		scanf("%lf",&moon[i].price);
		moon[i].avg = moon[i].price/moon[i].num;
	}
	sort(moon,moon+n,cmp);
	for(int i = 0;i<n;++i){
		if(d >= moon[i].num){
			ans += moon[i].price;
			d -= moon[i].num;
		}
		else{
			ans += d*moon[i].avg;
			break;
		}
	}
	printf("%.2f\n",ans);
	return 0;
}