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
	char project[25];
	int grade;
}stu[100005];

bool cmp(Stu a,Stu b){
	if(a.grade != b.grade){
		return a.grade > b.grade; 
	}
}

int main(int argc, char *argv[])
{
	int n,minGrade,maxGrade;
	scanf("%d",&n);
	for(int i = 0;i<n;++i){
		scanf("%s %s %d",stu[i].name,stu[i].project,&stu[i].grade);
	}
	sort(stu,stu+n,cmp);
	scanf("%d %d",&minGrade,&maxGrade);
	bool flag = false;
	for(int i = 0;i<n;++i){
		if(stu[i].grade >= minGrade && stu[i].grade <=maxGrade){
			printf("%s %s\n",stu[i].name,stu[i].project);
			flag = true;
		}
	}
	if(!flag)
		printf("NONE\n");
	return 0;
}