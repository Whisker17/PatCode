#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <iostream>
#include <map>
#include <cmath>
using namespace std;

#define maxn 505
#define INF 10000005

int n,m,cMax,sp,numPath=0,nMap[maxn][maxn],weight[maxn];
int d[maxn],minNeed=INF,minRemain=INF;
bool vis[maxn]={false};
vector<int> pre[maxn];
vector<int> temp,path;

void Dijkstra(int s){
	fill(d,d+maxn,INF);
	d[s] = 0;
	for(int i = 0;i<=n;++i){
		int u = -1,nMin=INF;
		for(int j = 0;j<=n;++j){
			if(!vis[j] && d[j] < nMin){
				nMin = d[j];
				u = j;
			}
		}
		if(u == -1)
			return ;
		vis[u] = true;
		for(int v = 0;v<=n;++v){
			if(!vis[v] && nMap[u][v] != INF){
				if(d[v] > d[u]+nMap[u][v]){
					d[v] = d[u]+nMap[u][v];
					pre[v].clear();
					pre[v].push_back(u);
				}
				else if(d[v] == d[u]+nMap[u][v])
					pre[v].push_back(u);
			}
		}
	}
}

void dfs(int v) {
    if(v == 0) {
        temp.push_back(v);
        int need = 0, remain = 0;
        for(int i = temp.size() - 1; i >= 0; i--) {
            int id = temp[i];
            if(weight[id] > 0) {
                remain += weight[id];
            } else {
                if(remain > abs(weight[id])) {
                    remain -= abs(weight[id]);
                } else {
                    need += abs(weight[id]) - remain;
                    remain = 0;
                }
            }
        }
        if(need < minNeed) {
            minNeed = need;
            minRemain = remain;
            path = temp;
        } else if(need == minNeed && remain < minRemain) {
            minRemain = remain;
            path = temp;
        }
        temp.pop_back();
        return;
    }
    temp.push_back(v);
    for(int i = 0; i < pre[v].size(); i++) {
        dfs(pre[v][i]);
    }
    temp.pop_back();
}

int main() {
    scanf("%d%d%d%d", &cMax, &n, &sp, & m);
    int u, v;
    fill(nMap[0], nMap[0] + maxn * maxn, INF);
    for(int i = 1; i <= n; i++) {
        scanf("%d", &weight[i]);
        weight[i] -= cMax / 2;
    }
    for(int i = 0; i < m; i++) {
        scanf("%d%d", &u, &v);
        scanf("%d", &nMap[u][v]);
        nMap[v][u] = nMap[u][v];
    }
    Dijkstra(0);
	dfs(sp);
	printf("%d ",minNeed);
	for(int i = path.size()-1;i>=0;--i){
		printf("%d",path[i]);
		if(i > 0)
			printf("->");
	}
	printf(" %d\n",minRemain);
	return 0;
}