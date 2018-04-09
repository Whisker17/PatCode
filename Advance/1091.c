#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <iostream>
#include <map>
#include <queue>
#include <cmath>
using namespace std;

struct Node{
	int x,y,z;
}node;

int num[1290][130][60];
bool visit[1290][130][60];

int m,n,l,t;
int X[6]={0,0,0,0,1,-1};
int Y[6]={0,0,1,-1,0,0};
int Z[6]={1,-1,0,0,0,0};

bool judge(int x,int y,int z){
	if(x >= m || x < 0 || y >= n || y < 0 || z >= l || z < 0)
		return false;
	if(num[x][y][z] == 0 || visit[x][y][z])
		return false;
	return true;
}

int bfs(int x,int y,int z){
	int res=0;
	queue<Node> q;	
	node.x = x,node.y = y,node.z = z;
	q.push(node);
	visit[x][y][z] = true;
	while(!q.empty()){
		Node top = q.front();
		q.pop();
		++res;
		for(int i = 0;i<6;++i){
			int nowX = node.x + X[i];
			int nowY = node.y + Y[i];
			int nowZ = node.z + Z[i];
			if(judge(nowX,nowY,nowZ)){
				node.x = nowX;
				node.y = nowY;
				node.z = nowZ;
				q.push(node);
				visit[nowX][nowY][nowZ] = true;
			}
		}
	}
	if(res >= t)
		return res;
	else return 0;
}

int main(int argc, char *argv[])
{
	int ans = 0;
	scanf("%d%d%d%d",&m,&n,&l,&t);
	for(int i = 0;i<l;++i){
		for(int j = 0;j<m;++j){
			for(int k = 0;k<n;++k)
				scanf("%d",&num[j][k][i]);
		}
	}
	for(int i = 0;i<l;++i){
		for(int j = 0;j<m;++j){
			for(int k = 0;k<n;++k){
				if(num[j][k][i] == 1 && !visit[j][k][i])
					ans += bfs(j,k,i);
			}
		}
	}
	printf("%d\n",ans);
	return 0;
}