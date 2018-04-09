#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <iostream>
#include <map>
#include <cmath>
using namespace std;

#define INF 100000000

struct Sta{
	double money;
	double dis;
}sta[100005];

bool cmp(Sta a,Sta b){
	return a.dis < b.dis;
}

int main(int argc, char *argv[])
{
	double cMax,d,dAvg;
	int n;
	scanf("%lf%lf%lf%d",&cMax,&d,&dAvg,&n);
	for(int i = 0;i<n;++i){
		scanf("%lf %lf",&sta[i].money,&sta[i].dis);
	}
	sta[n].dis = d,sta[n].money = 0.00;
	sort(sta,sta+n+1,cmp);
	if(sta[0].dis != 0.00){
		printf("The maximum travel distance = 0.00\n");
		return 0;
	}
	int now=0;
	double AMax = cMax*dAvg,ans=0,nowTank=0;
	while(now < n){
		int minPrice = INF;
		int minSta = -1;
		for(int i = now+1;i<=n,sta[i].dis - sta[now].dis <= AMax;++i){
			if(sta[i].money < minPrice){
				minPrice = sta[i].money;
				minSta = i;
				if(sta[now].money > minPrice)
					break;
			}
		}
		if(minSta == -1)
			break;
		double need = (sta[minSta].dis-sta[now].dis)/dAvg;
		if(sta[now].money > minPrice){
			if(nowTank < need){
				ans += (need-nowTank)*sta[now].money;
				nowTank = 0;
			}
			else nowTank -= need;
		}
		else {
			ans += (cMax-nowTank)*sta[now].money;
			nowTank = cMax - need;
		}
		now = minSta;
	}
	if(now == n)
		printf("%.2f",ans);
	else printf("The maximum travel distance = %.2f\n",sta[now].dis+AMax);
	return 0;
}