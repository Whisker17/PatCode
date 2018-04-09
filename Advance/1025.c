#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <iostream>
#include <map>
#include <cmath>
using namespace std;

struct Stu{
	int pos,grade;
	int posRank;
	char id[15];
}stu[100005];

bool cmp(Stu a,Stu b){
	if(a.grade != b.grade)
		return a.grade > b.grade;
	else return strcmp(a.id,b.id)<0;	
}

int main(int argc, char *argv[])
{
	int n,m,cnt=0;
	scanf("%d",&n);
	for(int i = 1;i<=n;++i){
		scanf("%d",&m);
		for(int j = cnt;j<cnt+m;++j){
			scanf("%s %d",stu[j].id,&stu[j].grade);
			stu[j].pos = i;
		}
		sort(stu+cnt,stu+m+cnt,cmp);
		stu[cnt].posRank = 1;
		for(int j = cnt+1;j<m+cnt;++j){
			if(stu[j].grade == stu[j-1].grade)
				stu[j].posRank = stu[j-1].posRank;
			else stu[j].posRank = j-cnt+1;
		}
		cnt += m;
	}
	printf("%d\n",cnt);
	int r = 1;
	sort(stu,stu+cnt,cmp);
	for(int i = 0;i<cnt;++i){
		if(i > 0 && stu[i].grade != stu[i-1].grade)
			r = i+1;
		printf("%s %d %d %d\n",stu[i].id,r,stu[i].pos,stu[i].posRank);
	}
	return 0;
}