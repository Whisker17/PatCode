#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <iostream>
#include <map>
#include <cmath>
using namespace std;

struct Stu{
	int id,grade;
	char name[25];
}stu[100005];

bool cmp1(Stu a,Stu b){
	return a.id < b.id;
}

bool cmp2(Stu a,Stu b){
	if(strcmp(a.name,b.name) != 0)
		return strcmp(a.name,b.name)<0;
	else return a.id < b.id;
}

bool cmp3(Stu a,Stu b){
	if(a.grade != b.grade)
		return a.grade < b.grade;
	else return a.id < b.id;
}

int main(int argc, char *argv[])
{
	int n,m;
	scanf("%d %d",&n,&m);
	for(int i = 0;i<n;++i){
		scanf("%d %s %d",&stu[i].id,stu[i].name,&stu[i].grade);
	}
	if(m == 1)
		sort(stu,stu+n,cmp1);
	else if(m == 2)
		sort(stu,stu+n,cmp2);
	else if(m == 3)
		sort(stu,stu+n,cmp3);
	for(int i = 0;i<n;++i){
		printf("%06d %s %d\n",stu[i].id,stu[i].name,stu[i].grade);
	}
	return 0;           
}