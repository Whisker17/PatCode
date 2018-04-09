#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <iostream>
#include <map>
#include <cmath>
using namespace std;

#define maxn 505
#define INF 10000000

int n,m,d[maxn],st,en,minCost=INF;
int nMap[maxn][maxn],cost[maxn][maxn];
bool vis[maxn];
vector<int> pre[maxn];
vector<int> path,temp;

void Dijkstra(int s){
	fill(d,d+maxn,INF);
	for(int i = 0; i < n; i++) {
        pre[i].push_back(i);
    }
	d[s] = 0;
	for(int i = 0;i<n;++i){
		int u = -1,nMin = INF;
		for(int j = 0;j<n;++j){
			if(!vis[j] && d[j] < nMin){
				u = j;
				nMin = d[j];
			}
		}
		if(u == -1) return;
        vis[u] = true;
        for(int v = 0; v < n; v++) {
            if(vis[v] == false && nMap[u][v] != INF) {
                if(d[u] + nMap[u][v] < d[v]) {
                    d[v] = d[u] + nMap[u][v];
                    pre[v].clear();
                    pre[v].push_back(u);
                } else if(d[u] + nMap[u][v] == d[v]) {
                    pre[v].push_back(u);
                }
            }
        }
	}
}

void dfs(int v){
	if(v == st){
		int tempCost = 0;
		temp.push_back(v);
		for(int i = temp.size()-1;i>0;--i){
			int sId = temp[i],nPre = temp[i-1];
			tempCost += cost[sId][nPre];
		}
		if(tempCost < minCost){
			minCost = tempCost;
			path = temp;
		}
		temp.pop_back();
		return ;
	}
	temp.push_back(v);
	for(int i = 0;i<pre[v].size();++i){
		dfs(pre[v][i]);
	}
	temp.pop_back();
}

int main(int argc, char *argv[])
{
	int a,b;
	scanf("%d %d %d %d",&n,&m,&st,&en);
	fill(nMap[0],nMap[0]+maxn*maxn,INF);
	fill(cost[0],cost[0]+maxn*maxn,INF);
	for(int i = 0;i<m;++i){
		scanf("%d %d",&a,&b);
		scanf("%d %d",&nMap[a][b],&cost[a][b]);
		nMap[b][a] = nMap[a][b],cost[b][a] = cost[a][b];
	}
	Dijkstra(st);
	dfs(en);
	for(int i = path.size()-1;i>=0;--i)
		printf("%d ",path[i]);
	printf("%d %d\n",d[en],minCost);
	return 0;
}