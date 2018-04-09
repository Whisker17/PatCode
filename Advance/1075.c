#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <iostream>
#include <map>
#include <cmath>
using namespace std;

struct Stu{
	int grade[6];
	int perfect;
	int id;
	int sum;
	bool set;
}stu[100005];

int perfectGrade[6]={0};
int n,m,nIndex,sId,sNo,sGrade;

void init(){
	for(int i = 1;i<=n;++i){
		memset(stu[i].grade,-1,sizeof(stu[i].grade));
		stu[i].sum = 0;
		stu[i].perfect = 0;
		stu[i].set = false;
		stu[i].id = i;
	}
}

bool cmp(Stu a,Stu b){
	if(a.sum != b.sum)
		return a.sum > b.sum;
	else if(a.perfect != b.perfect)
		return a.perfect > b.perfect;
	else return a.id <b.id;
}

int main(int argc, char *argv[])
{
	scanf("%d %d %d",&n,&m,&nIndex);
	init();
	for(int i = 1;i<=m;++i)
		scanf("%d",&perfectGrade[i]);
	for(int i = 0;i<nIndex;++i){
		scanf("%d %d %d",&sId,&sNo,&sGrade);
		if(sGrade != -1)
			stu[sId].set = true;
		if(sGrade == -1 && stu[sId].grade[sNo] == -1){
			sGrade = 0;
		}
		if(sGrade > stu[sId].grade[sNo]){
			stu[sId].grade[sNo] = sGrade;
			if(sGrade == perfectGrade[sNo])
				++stu[sId].perfect;
		}
		/*if(sGrade == perfectGrade[sNo] && stu[sId].grade[sNo] < perfectGrade[sNo])
				++stu[sId].perfect;*/
		
	}
		for(int i = 1;i<=n;++i){
			for(int j = 1;j<=m;++j){
				if(stu[i].grade[j] != -1)
					stu[i].sum += stu[i].grade[j];
			}
		}
	sort(stu+1,stu+n+1,cmp);
	int r = 1;
	for(int i = 1;i<=n;++i){
		if(stu[i].set){
			if(i>1 && stu[i].sum != stu[i-1].sum)
				r = i;
			printf("%d %05d %d",r,stu[i].id,stu[i].sum);
			for(int j = 1;j<=m;++j){
				if(stu[i].grade[j] == -1)
					printf(" -");
				else printf(" %d",stu[i].grade[j]);
			}
			printf("\n");
		}
	}
	return 0;
}