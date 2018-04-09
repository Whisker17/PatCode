#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <iostream>
#include <map>
#include <queue>
#include <cmath>
using namespace std;

#define maxn 1005

struct Node{
	int id,layer;
};

vector<Node> Adj[maxn];
bool vis[maxn];

int bfs(int st,int L){
	queue<Node> q;
	int numForward=0;
	Node start;
	start.id = st;
	start.layer = 0;
	vis[start.id] = true;
	q.push(start);
	while(!q.empty()){
		Node now = q.front();
		q.pop();
		int temp = now.id;
		for(int i = 0;i<Adj[temp].size();++i){
			Node next = Adj[temp][i];
			next.layer = now.layer+1;
			if(!vis[next.id] && next.layer <= L){
				q.push(next);
				vis[next.id] = true;
				++numForward;
			}
		}
	}
	return numForward;
}

int main(int argc, char *argv[])
{
	int n,L,numFollow,idFollow;
	Node user;
	scanf("%d %d",&n,&L);
	for(int i = 1;i<=n;++i){
		user.id = i;
		scanf("%d",&numFollow);
		for(int j = 0;j<numFollow;++j){
			scanf("%d",&idFollow);
			Adj[idFollow].push_back(user);
		}
	}
	int t,s;
	scanf("%d",&t);
	for(int i = 0;i<t;++i){
		memset(vis,false,sizeof(vis));
		scanf("%d",&s);
		int numForward = bfs(s,L);
		printf("%d\n",numForward);
	}
	return 0;
}