#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <iostream>
#include <map>
#include <cmath>
using namespace std;
struct Stu{
	char name[15];
	char sId[20];
	bool sex;
	int grade;
}stu[1005],tmp1,tmp2;
int main(int argc, char *argv[])
{
	int n;
	char nSex;
	bool flag1 = false,flag2 = false;
	scanf("%d",&n);
	tmp1.grade = 101,tmp2.grade = -1;
	for(int i = 0;i<n;++i){
		scanf("%s %c %s %d",stu[i].name,&nSex,stu[i].sId,&stu[i].grade);
		if(nSex == 'M')
			stu[i].sex = 1;
		else stu[i].sex = 0;
		if(stu[i].sex){
			flag1 = true;
			if(stu[i].grade < tmp1.grade)
				tmp1 = stu[i];
		}
		else {
			flag2 = true;
			if(stu[i].grade > tmp2.grade)
				tmp2 = stu[i];
		}
	}
	if(!flag2)
		printf("Absent\n");
	else{
		printf("%s %s\n",tmp2.name,tmp2.sId);
	}	
	if(!flag1)
		printf("Absent\n");
	else {
		printf("%s %s\n",tmp1.name,tmp1.sId);
	}
	if(flag1 && flag2)
		printf("%d\n",tmp2.grade-tmp1.grade);
	else printf("NA\n");
	return 0;
}