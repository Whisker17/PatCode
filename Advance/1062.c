#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <iostream>
#include <map>
#include <cmath>
using namespace std;

struct Stu{
	char id[10];
	int dGrade,cGrade;
	int flag;
	int sum;
}stu[100005];

bool cmp(Stu a,Stu b){
	if(a.flag != b.flag)
		return a.flag < b.flag;
	else if(a.sum != b.sum)
		return a.sum > b.sum;
	else if(a.dGrade != b.dGrade)
		return a.dGrade > b.dGrade;
	else return strcmp(a.id,b.id)<0;
}

int main(int argc, char *argv[])
{
	int n,d,c;
	scanf("%d %d %d",&n,&d,&c);
	int m = n;
	for(int i = 0;i<n;++i){
		scanf("%s %d %d",stu[i].id,&stu[i].dGrade,&stu[i].cGrade);
		stu[i].sum = stu[i].dGrade + stu[i].cGrade;
		if(stu[i].dGrade < d || stu[i].cGrade < d){
			stu[i].flag = 5;
			--m;
		}
		else if(stu[i].dGrade >= c && stu[i].cGrade >= c)
			stu[i].flag = 1;
		else if(stu[i].dGrade >= c && stu[i].cGrade < c)
			stu[i].flag = 2;
		else if(stu[i].dGrade >= stu[i].cGrade)
			stu[i].flag = 3;
		else stu[i].flag = 4;
	}
	sort(stu,stu+n,cmp);
	printf("%d\n",m);
	for(int i = 0;i<m;++i){
		printf("%s %d %d\n",stu[i].id,stu[i].dGrade,stu[i].cGrade);
	}
	return 0;
}