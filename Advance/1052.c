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
	int address,val,next;
	bool flag;
	Node():flag(false){
		
	}
}node[maxn];

bool cmp(Node a,Node b){
	if(a.flag == false || b.flag == false)
		return a.flag > b.flag;
	else
		return a.val < b.val;
}

int main(int argc, char *argv[])
{
	int n,start,add,cnt=0;
	scanf("%d %d",&n,&start);
	for(int i = 0;i<n;++i){
		scanf("%d ",&add);
		node[add].address = add;
		scanf("%d %d",&node[add].val,&node[add].next);
	}
	int now = start;
	while(now != -1){
		node[now].flag = true;
		now = node[now].next;
		++cnt;
	}
	if(!cnt){
		printf("0 -1\n");
		return 0;
	}
	sort(node,node+maxn,cmp);
	now = node[0].address;
	printf("%d %05d\n",cnt,node[0].address);
	for(int i = 0;i<cnt;++i){
		if(i != cnt-1)
			printf("%05d %d %05d\n",node[i].address,node[i].val,node[i+1].address);
		else printf("%05d %d -1\n",node[i].address,node[i].val);			
	}
	return 0;
}