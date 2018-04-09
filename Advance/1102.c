#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <iostream>
#include <map>
#include <queue>
#include <cmath>
using namespace std;

#define maxn 105

struct Node{
	int left,right;
}node[maxn];

int num = 0;
int n;
bool notRoot[maxn];
void inOrder(int root){
	if(root == -1)
		return ;
	inOrder(node[root].left);
	++num;
	printf("%d",root);
	if(num < n)
		printf(" ");
	else printf("\n");
	inOrder(node[root].right);
}

void bfs(int root){
	queue<int> q;
	q.push(root);
	while(!q.empty()){
		int now = q.front();
		q.pop();
		++num;
		printf("%d",now);
		if(num<n)
			printf(" ");
		else printf("\n");
		if(node[now].left != -1)
			q.push(node[now].left);
		if(node[now].right != -1)
			q.push(node[now].right);
	}
}

void postOrder(int root){
	if(root == -1)
		return ;
	postOrder(node[root].left);
	postOrder(node[root].right);
	swap(node[root].left,node[root].right);
}

int strToNum(char c){
	if(c == '-')
		return -1;
	else{
		notRoot[c-'0'] = true;
		return c-'0';
	}
}

int findRoot(){
	for(int i = 0;i<n;++i){
		if(!notRoot[i])
			return i;
	}
}

int main(int argc, char *argv[])
{
	char l,r;
	scanf("%d",&n);
	memset(notRoot,false,sizeof(notRoot));
	for(int i = 0;i<n;++i){
		scanf("%*c%c %c",&l,&r);
		node[i].left = strToNum(l);
		node[i].right = strToNum(r);
	}
	int root = findRoot();
	postOrder(root);
	bfs(root);
	num = 0;
	inOrder(root);
	return 0;
}