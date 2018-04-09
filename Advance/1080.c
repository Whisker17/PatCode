#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <iostream>
#include <map>
#include <cmath>
using namespace std;

#define maxn 100005

struct Stu{
	int GE,GI,sum;
	int sRank,sId;
	int school[6];
}stu[maxn];

struct Sch{
	int num;
	int now;
	int id[maxn];
	int lastAdmit;
}sch[105];

bool cmp1(Stu a,Stu b){
	if(a.sum != b.sum)
		return a.sum > b.sum;
	else if(a.GE != b.GE)
		return a.GE > b.GE;
	else return a.sId < b.sId;
}

bool cmp2(int a,int b){
	return stu[a].sId < stu[b].sId;
}

int main(int argc, char *argv[])
{
	int n,m,k;
	scanf("%d %d %d",&n,&m,&k);
	for(int i = 0;i<m;++i){
		scanf("%d",&sch[i].num);
		sch[i].now = 0;
		sch[i].lastAdmit = -1;
	}
	for(int i = 0;i<n;++i){
		stu[i].sId = i;
		scanf("%d %d",&stu[i].GE,&stu[i].GI);
		stu[i].sum = stu[i].GE + stu[i].GI;
		for(int j = 0;j<k;++j){
			scanf("%d",&stu[i].school[j]);
		}
	}
	sort(stu,stu+n,cmp1);
	for(int i = 0;i<n;++i){
		if(i > 0 && stu[i].sum == stu[i-1].sum && stu[i].GE == stu[i-1].GE)
			stu[i].sRank = stu[i-1].sRank;
		else stu[i].sRank = i; 	 
	}
	for(int i = 0;i<n;++i){
		for(int j = 0;j<k;++j){
			int choice = stu[i].school[j];
			int tmp = sch[choice].now;
			int last = sch[choice].lastAdmit;
			if(tmp < sch[choice].num || (last != -1 && stu[last].sRank == stu[i].sRank)){
				sch[choice].id[tmp] = i;
				sch[choice].lastAdmit = i;
				++sch[choice].now;
				break;
			}
		}
	}
	for(int i = 0;i<m;++i){
		if(sch[i].now > 0){
			sort(sch[i].id,sch[i].id+sch[i].now,cmp2);
			for(int j = 0;j<sch[i].now;++j){
				printf("%d",stu[sch[i].id[j]].sId);
				if(j < sch[i].now - 1)
					printf(" ");
			}
		}
		printf("\n");
	}
	return 0;
}