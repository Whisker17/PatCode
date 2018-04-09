#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <iostream>
#include <map>
#include <cmath>
using namespace std;

struct node{
	char name[20],password[20];
	bool isChanged;
}stu[1005];

void modify(node &stu,int &cnt){
	int len = strlen(stu.password);
	for(int i = 0;i<len;++i){
		if(stu.password[i] == '1'){
			stu.password[i] = '@';
			stu.isChanged = true;
		}
		else if(stu.password[i] == '0'){
			stu.password[i] = '%';
			stu.isChanged = true;
		}
		else if(stu.password[i] == 'l'){
			stu.password[i] = 'L';
			stu.isChanged = true;
		}
		else if(stu.password[i] == 'O'){
			stu.password[i] = 'o';
			stu.isChanged = true;
		}
	}
	if(stu.isChanged) 
		++cnt;
}

int main(int argc, char *argv[])
{
	int n,cnt=0;
	char str[1005];
	scanf("%d",&n);
	for(int i = 0;i<n;++i){
		scanf("%s %s",stu[i].name,stu[i].password);
		modify(stu[i],cnt);
	} 
	if(cnt == 0){
		if(n == 1){
			printf("There is 1 account and no account is modified\n");
		}
		else printf("There are %d accounts and no account is modified\n",n);
	}
	else{
		printf("%d\n",cnt);
		for(int i = 0;i<n;++i){
			if(stu[i].isChanged)
				printf("%s %s\n",stu[i].name,stu[i].password);
		}
	}
	return 0;
}