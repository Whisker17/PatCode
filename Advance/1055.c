#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <iostream>
#include <map>
#include <cmath>
using namespace std;

struct Stu{
	int money,age;
	char name[25];
}stu[100005];

bool cmp(Stu a,Stu b){
	if(a.money != b.money)
		return a.money > b.money;
	else if (a.age != b.age)
		return a.age < b.age;
	else return strcmp(a.name,b.name)<0;
}

int main(int argc, char *argv[])
{
	int n,m,minAge,maxAge,num;
	scanf("%d %d",&n,&m);
	for(int i = 0;i<n;++i){
		scanf("%s %d %d",stu[i].name,&stu[i].age,&stu[i].money);
	}
	sort(stu,stu+n,cmp);
	for(int i = 0;i<m;++i){
		int cnt=1;
		scanf("%d %d %d",&num,&minAge,&maxAge);
		printf("Case #%d:\n",i+1);
		for(int j = 0;j<n;++j){
			if(stu[j].age >= minAge && stu[j].age <=maxAge){
				printf("%s %d %d\n",stu[j].name,stu[j].age,stu[j].money);
				++cnt;
			}
			if(cnt == num+1)
				break;
		}
		if(cnt == 1)
			printf("None\n");
	}
	return 0;
}