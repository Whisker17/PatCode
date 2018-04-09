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
	int pre,val,next;
	int order;
	Node():order(maxn){
		
	}
}node[maxn];

bool cmp(Node a,Node b){
	return a.order < b.order;
}

int main(int argc, char *argv[])
{
	int start,n,k,add;
	Node tmp;
	scanf("%d %d %d",&start,&n,&k);
	for(int i = 0;i<n;++i){
		scanf("%d",&add);
		node[add].pre = add;
		scanf("%d %d",&node[add].val,&node[add].next);
	}
	int now = start,cnt=0;
	while(now != -1){
		node[now].order = cnt++;
		now = node[now].next;
	}
	sort(node,node+maxn,cmp);
	n = cnt;
	for(int i = 0;i<n/k;++i){
		for(int j = (i+1)*k-1;j>i*k;--j){
			printf("%05d %d %05d\n",node[j].pre,node[j].val,node[j-1].pre);
		}
		printf("%05d %d ",node[i*k].pre,node[i*k].val);
		if(i < n/k-1)
			printf("%05d\n",node[(i+2)*k-1].pre);
		else{
			if(n%k == 0)
				printf("-1\n");
			else{
				printf("%05d\n",node[(i+1)*k].pre);
				for(int q = n/k*k;q<n;++q){
					if(q != n-1)
						printf("%05d %d %05d\n",node[q].pre,node[q].val,node[q].next);
					else printf("%05d %d -1\n",node[q].pre,node[q].val);
				}
				
			}
		}
	}
	return 0;
}