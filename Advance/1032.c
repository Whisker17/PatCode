#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <iostream>
#include <map>
#include <cmath>
using namespace std;

#define maxn 100005

struct Node{
	int address,next;
	char val;
	bool flag;
	Node():flag(false){
		
	}
}node[maxn];

int main(int argc, char *argv[])
{
	int start1,start2,n,add;
	scanf("%d%d%d",&start1,&start2,&n);
	for(int i = 0;i<n;++i){
		scanf("%d ",&add);
		node[add].address = add;
		scanf("%c %d",&node[add].val,&node[add].next);
	}
	int now=start1;
	while(now != -1){
		node[now].flag = true;
		now = node[now].next;
	}
	now = start2;
	while(now != -1){
		if(node[now].flag)
			break;
		now = node[now].next;
	}
	if(now == -1)
		printf("-1\n");
	else{
		printf("%05d\n",now);
	}
	return 0;
}