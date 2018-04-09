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

int n,m,st,nMap[maxn][maxn],weight[maxn];
int d[maxn],numPath=0,maxW=0;
double maxAvg=0;
bool vis[maxn];
vector<int> pre[maxn];
vector<int> temp,path;
map<string,int> cityToIndex;
map<int,string> indexToCity;

void Dijkstra(int s) {
    fill(d, d + maxn, INF);
    for(int i = 0; i < n; i++) {
        pre[i].push_back(i);
    }
    d[s] = 0;
    for(int i = 0; i < n; i++) {
        int u = -1, MIN = INF;
        for(int j = 0; j < n; j++) {
            if(vis[j] == false && d[j] < MIN) {
                u = j;
                MIN = d[j];
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

void dfs(int v) {
    if(v == st) {
        temp.push_back(v);
        numPath++;
        int tempW = 0;
        for(int i = temp.size() - 2; i >= 0; i--) {
            int id = temp[i];
            tempW += weight[id];
        }
        double tempAvg = 1.0 * tempW / (temp.size() - 1);
        if(tempW > maxW) {
            maxW = tempW;
            maxAvg = tempAvg;
            path = temp;
        } else if(tempW == maxW && tempAvg > maxAvg) {
            maxAvg = tempAvg;
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

int main(int argc, char *argv[])
{
	string start, city1, city2;
    cin >> n >> m >> start;
    cityToIndex[start] = 0;
    indexToCity[0] = start;
    for(int i = 1; i <= n - 1; i++) {
        cin >> city1 >> weight[i];
        cityToIndex[city1] = i;
        indexToCity[i] = city1;
    }
    fill(nMap[0], nMap[0] + maxn * maxn, INF);
    for(int i = 0; i < m; i++) {
        cin >> city1 >> city2;
        int c1 = cityToIndex[city1], c2 = cityToIndex[city2];
        cin >> nMap[c1][c2];
        nMap[c2][c1] = nMap[c1][c2];
    }
	Dijkstra(0);
    int rom = cityToIndex["ROM"];
    dfs(rom);
    printf("%d %d %d %d\n", numPath, d[rom], maxW, (int)maxAvg);
    for(int i = path.size() - 1; i >= 0; i--) {
        cout << indexToCity[path[i]];
        if(i > 0) cout << "->";
    }
	return 0;
}