#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <iostream>
#include <map>
#include <cmath>
#include <queue>
using namespace std;

#define maxn 100005

struct Mice{
	int index,val; 
}mice[maxn];

int main(int argc, char *argv[])
{
	int np,ng,order;
	scanf("%d %d",&np,&ng);
	for(int i = 0;i<np;++i){
		scanf("%d",&mice[i].val);
	}
	queue<int> q;
	for(int i = 0;i<np;++i){
		scanf("%d",&order);
		q.push(order);
	}
	int temp = np,group;
	while(q.size() != 1){
		if(temp%ng == 0)
			group = temp/ng;
		else group = temp/ng + 1;
		for(int i = 0;i<group;++i){
			int k = q.front();
			for(int j = 0;j<ng;++j){
				if(i*ng+j >= temp)
					break;
				int front = q.front();
				if(mice[front].val > mice[k].val){
					k = front;
				}
				mice[front].index = group+1;
				q.pop();
			}
			q.push(k);
		}
		temp = group;
	}	
	mice[q.front()].index = 1;
	for(int i = 0;i<np;++i){
		printf("%d",mice[i].index);
		if(i < np-1)
			printf(" ");
	}
	return 0;
}