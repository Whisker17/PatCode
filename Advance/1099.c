#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <iostream>
#include <map>
#include <cmath>
#include <queue>
using namespace std;

#define maxn 10005

struct Node{
	int val;
	int left,right;
}node[maxn];

int n,num[maxn],cnt=0;

void inOrder(int root){
	if(root == -1)
		return ;
	inOrder(node[root].left);
	node[root].val = num[cnt++];
	inOrder(node[root].right);
}

void bfs(int root){
	queue<int> q;
	q.push(root);
	cnt=0;
	while(!q.empty()){
		int now = q.front();
		q.pop();
		++cnt;
		printf("%d",node[now].val);
		if(cnt < n)
			printf(" ");
		if(node[now].left != -1)
			q.push(node[now].left);
		if(node[now].right != -1)
			q.push(node[now].right);
	}
}

int main(int argc, char *argv[])
{
	int lchild,rchild;
	scanf("%d",&n);
	for(int i = 0;i<n;++i){
		scanf("%d %d",&lchild,&rchild);
		node[i].left = lchild;
		node[i].right = rchild;
	}
	for(int i = 0;i<n;++i)
		scanf("%d",&num[i]);
	sort(num,num+n);
	inOrder(0);
	bfs(0);
	return 0;
}