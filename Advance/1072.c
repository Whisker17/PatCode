#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <iostream>
#include <map>
#include <cmath>
using namespace std;

#define maxn 1020
#define INF 100000000

int nMap[maxn][maxn],n,m,k,DS;
bool vis[maxn];
int d[maxn];

int getId(char str[]){
	int i=0,len = strlen(str);
	int sId=0;
	while(i < len){
		if(str[i] != 'G'){
			sId = sId*10 + (str[i]-'0');
		}
		++i;
	}
	if(str[0] == 'G')
		return n+sId;
	return sId;
}

void Dijkstra(int s){
	fill(d,d+maxn,INF);
	memset(vis,false,sizeof(vis));
	d[s] = 0;
	for(int i = 0;i<n+m;++i){
		int u = -1,nMin = INF;
		for(int j = 1;j<=n+m;++j){
			if(!vis[j] && d[j] < nMin){
				nMin = d[j];
				u = j;
			}
		}
		if(u == -1)
			return ;
		vis[u] = true;
		for(int v = 1;v<=n+m;++v){
			if(!vis[v] && nMap[u][v] != INF){
				if(d[v] > d[u]+nMap[u][v]){
					d[v] = d[u]+nMap[u][v];
				}
			}
		}
	}
}

int main() {
    scanf("%d%d%d%d", &n, &m, &k, &DS);
    int u, v, w;
    char city1[5], city2[5];
    fill(nMap[0], nMap[0] + maxn * maxn, INF);
    for(int i = 0; i < k; i++) {
        scanf("%s %s %d", city1, city2, &w);
        u = getId(city1);
        v = getId(city2);
        nMap[v][u] = nMap[u][v] = w;
    }
    double ansDis = -1, ansAvg = INF;
    int ansID = -1;
    for(int i = n + 1; i <= n + m; i++) {
        double minDis = INF, avg = 0;
        Dijkstra(i);
        for(int j = 1; j <= n; j++) {
            if(d[j] > DS) {
                minDis = -1;
                break;
            }
            if(d[j] < minDis) minDis = d[j];
            avg += 1.0 * d[j] / n;
        }
        if(minDis == -1) continue;
        if(minDis > ansDis) {
            ansID = i;
            ansDis = minDis;
            ansAvg = avg;
        } else if(minDis == ansDis && avg < ansAvg) {
            ansID = i;
            ansAvg = avg;
        }
    }
    if(ansID == -1) printf("No Solution\n");
    else {
        printf("G%d\n", ansID - n);
        printf("%.1f %.1f\n", ansDis, ansAvg);
    }
    return 0;
}