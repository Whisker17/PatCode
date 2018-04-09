#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <iostream>
#include <map>
#include <cmath>
using namespace std;

struct Car{
	char sId[25];
	int time;
	int status;
}car[100005],res[100005];

map<string,int> parkTime;

bool cmp(Car a,Car b){
	if(strcmp(a.sId,b.sId) != 0)
		return strcmp(a.sId,b.sId)<0;
	else return a.time < b.time;
}

bool cmp2(Car a, Car b){
	return a.time < b.time;
}

int main(int argc, char *argv[])
{
	int n,k;
	int hh,mm,ss,num=0;
	char sta[5];
	vector<int> maxCar;
	scanf("%d %d",&n,&k);
	for(int i = 0;i<n;++i){
		scanf("%s %d:%d:%d %s",car[i].sId,&hh,&mm,&ss,sta);
		if(strcmp(sta,"in") == 0)
			car[i].status = 1;
		else car[i].status = 0;
		car[i].time = ss+mm*60+hh*3600;
	}
	sort(car,car+n,cmp);
	int maxTime = -1;
	for(int i = 0;i<n-1;++i){
		if(!strcmp(car[i].sId,car[i+1].sId) && (car[i].status && !car[i+1].status)){
			res[num++] = car[i];
			res[num++] = car[i+1];
			int sTime = car[i+1].time - car[i].time;
			if(parkTime[car[i].sId] == 0)
				parkTime[car[i].sId] = 0;
			parkTime[car[i].sId] += sTime;
			if(sTime > maxTime)
				maxTime = sTime;
		}
	}
	sort(res,res+num,cmp2);
	for(int i = 0;i<k;++i){
		scanf("%d:%d:%d",&hh,&mm,&ss);
		int sTime = hh*3600+mm*60+ss;
		int cnt=0;
		int ans=0;
		while(cnt < num && res[cnt].time <= sTime){
			if(res[cnt].status) 
				++ans;
			else --ans;
			++cnt;
		}
		printf("%d\n",ans);
	}
	map<string,int>::iterator iter;
	for(iter = parkTime.begin();iter != parkTime.end();++iter){
		if(iter->second == maxTime)
			printf("%s ",iter->first.c_str());
	}
	printf("%02d:%02d:%02d\n",maxTime/3600,maxTime%3600/60,maxTime%60);
	return 0;
}