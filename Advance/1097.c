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
	int order;
	Node():order(2*maxn){
		
	}
}node[maxn];

bool isExist[maxn];

bool cmp(Node a,Node b){
	return a.order < b.order;
}

int main(int argc, char *argv[])
{
	int start,n,add;
	memset(isExist,false,sizeof(isExist));
	scanf("%d %d",&start,&n);
	for(int i = 0;i<n;++i){
		scanf("%d",&add);
		node[add].address = add;
		scanf("%d %d",&node[add].val,&node[add].next);
	}
	int now = start,countValid=0,countDel=0;
	while(now != -1){
		if(!isExist[abs(node[now].val)]){
			isExist[abs(node[now].val)] = true;
			node[now].order = countValid++;
		}
		else{
			node[now].order = maxn + countDel++;
		}
		now = node[now].next;
	}
	sort(node,node+maxn,cmp);
	int cnt = countValid + countDel;
	for(int i = 0;i<cnt;++i){
		if(i != countValid - 1 && i != cnt - 1)
			printf("%05d %d %05d\n",node[i].address,node[i].val,node[i+1].address);
		else printf("%05d %d -1\n",node[i].address,node[i].val);
	}
	return 0;
}