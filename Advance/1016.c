#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <iostream>
#include <map>
#include <cmath>
using namespace std;

struct Stu{
	char name[25];
	int month,dd,hh,mm;
	bool status;
}stu[1005],tmp;

int price[24];

bool cmp(Stu a,Stu b){
	if(strcmp(a.name,b.name) != 0)
		return strcmp(a.name,b.name)<0;
	else if(a.month != b.month){
		return a.month < b.month;
	}
	else if(a.dd != b.dd){
		return a.dd < b.dd;
	}
	else if(a.hh != b.hh){
		return a.hh < b.hh;
	}
	else return a.mm < b.mm;
}

void solve(int on,int off,int &time,int &sum){
	tmp = stu[on];
	while(tmp.dd < stu[off].dd || tmp.hh < stu[off].hh || tmp.mm < stu[off].mm){
		++time;
		++tmp.mm;
		sum += price[tmp.hh];
		if(tmp.mm > 59){
			tmp.mm = 0;
			++tmp.hh;
		}
		if(tmp.hh > 23){
			tmp.hh = 0;
			++tmp.dd;
		}
	}
}

int main(int argc, char *argv[])
{
	int n;
	char onoff[10];
	for(int i = 0;i<24;++i){
		scanf("%d",&price[i]);
	}
	scanf("%d",&n);
	for(int i = 0;i<n;++i){
		scanf("%s %d:%d:%d:%d %s",stu[i].name,&stu[i].month,&stu[i].dd,&stu[i].hh,&stu[i].mm,onoff);
		if(strcmp(onoff,"on-line") == 0)
			stu[i].status = true;
		else stu[i].status = false;
	}
	sort(stu,stu+n,cmp);
	int on=0,off,next;
	while(on < n){
		next = on;
		int needPrint=0;
		while(next < n && strcmp(stu[on].name,stu[next].name) == 0){
			if(stu[next].status && needPrint == 0){
				needPrint = 1;
			}
			else if(!stu[next].status && needPrint == 1){
				needPrint = 2;
			}
			++next;
		}
		if(needPrint < 2){
			on = next;
			continue;
		}
		int money = 0;
		printf("%s %02d\n",stu[on].name,stu[on].month);
		while(on < next){
			while(on < next-1 && !(stu[on].status == true && stu[on+1].status == false))
				++on;
			off = on+1;
			if(off == next){
				on = next;
				break;
			}
			printf("%02d:%02d:%02d %02d:%02d:%02d ",stu[on].dd,stu[on].hh,stu[on].mm,stu[off].dd,stu[off].hh,stu[off].mm);
			int sum=0,time=0;
			solve(on,on+1,time,sum);
			money += sum;
			printf("%d $%.2f\n",time,sum/100.0);
			on = off + 1;
		}
		printf("Total amount: $%.2f\n",money/100.0);
	}
	
	return 0;
}