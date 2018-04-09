#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <iostream>
#include <map>
#include <cmath>
using namespace std;

struct Stu{
	int id;
	int grade[4];
}stu[2005];

int now;
char course[4]={'A','C','M','E'};
int sRank[10000005][4]={0};

bool cmp(Stu a,Stu b){
	return a.grade[now] > b.grade[now];
}

int main(int argc, char *argv[])
{
	int n,index,num;
	scanf("%d %d",&n,&index);
	for(int i = 0;i<n;++i){
		scanf("%d %d %d %d",&stu[i].id,&stu[i].grade[1],&stu[i].grade[2],&stu[i].grade[3]);
		stu[i].grade[0] = (stu[i].grade[1] + stu[i].grade[2] + stu[i].grade[3])/3;
	}
	for(now = 0;now<4;++now){
		sort(stu,stu+n,cmp);
		sRank[stu[0].id][now] = 1;
		for(int i = 1;i<n;++i){
			if(stu[i].grade[now] == stu[i-1].grade[now])
				sRank[stu[i].id][now] = sRank[stu[i-1].id][now];
			else sRank[stu[i].id][now] = i+1;
		}
	}
	for(int i = 0;i<index;++i){
		scanf("%d",&num);
		if(sRank[num][0] == 0){
			printf("N/A\n");
		} 
		else {
			int k=0;
			for(int j = 0;j<4;++j){
				if(sRank[num][j] < sRank[num][k])
					k = j;
			}
			printf("%d %c\n",sRank[num][k],course[k]);
		}
	}	
	return 0;
}