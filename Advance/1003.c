#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <iostream>
#include <map>
#include <cmath>
using namespace std;

#define maxn 505
#define INF 100000000

int n,m,st,en,nMap[maxn][maxn],weight[maxn];
int d[maxn],w[maxn],num[maxn];
bool vis[maxn]={false};

void Dijkstra(int s){
	fill(d,d+maxn,INF);
	memset(num,0,sizeof(num));
	memset(w,0,sizeof(w));
	d[s] = 0;
	w[s] = weight[s];
	num[s] = 1;
	for(int i = 0;i<n;++i){
		int u = -1,nMin = INF;
		for(int j = 0;j<n;++j){
			if(!vis[j] && d[j] < nMin){
				nMin = d[j];
				u = j;
			}
		}
		if(u == -1)
			return ;
		vis[u] = true;
		for(int v = 0;v<n;++v){
			if(!vis[v] && nMap[u][v] != INF){
				if(d[u]+nMap[u][v] < d[v]){
					d[v] = d[u]+nMap[u][v];
					w[v] = w[u]+weight[v];
					num[v] = num[u];
				}else if(d[u]+nMap[u][v] == d[v]){
					if(w[u]+weight[v] > w[v])
						w[v] = w[u]+weight[v];
					num[v] += num[u];
				}
			}
		}
	}
}

int main(int argc, char *argv[])
{
	scanf("%d%d%d%d",&n,&m,&st,&en);
	for(int i = 0;i<n;++i){
		scanf("%d",&weight[i]);
	}
	int u,v;
	fill(nMap[0],nMap[0]+maxn*maxn,INF);
	for(int i = 0;i<m;++i){
		scanf("%d%d",&u,&v);
		scanf("%d",&nMap[u][v]);
		nMap[v][u] = nMap[u][v];
	}
	Dijkstra(st);
	printf("%d %d\n",num[en],w[en]);
	return 0;
}