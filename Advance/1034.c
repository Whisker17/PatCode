#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <iostream>
#include <map>
#include <cmath>
using namespace std;

#define maxn 2005

map<int,string> intTostring;
map<string,int> stringToInt;
map<string,int> Gang;
int nMap[maxn][maxn],weight[maxn]={0};
int n,k,numPerson=0;
bool vis[maxn];

int change(string str){
	if(stringToInt.find(str) != stringToInt.end())
		return stringToInt[str];
	else{
		stringToInt[str] = numPerson;
		intTostring[numPerson] = str;
		return numPerson++;
	}
} 

void dfs(int nowVisit,int &head,int &numMember,int &totalValue){
	++numMember;
	vis[nowVisit] = true;
	if(weight[nowVisit] > weight[head]){
		head = nowVisit;
	}
	for(int i = 0;i<numPerson;++i){
		if(nMap[nowVisit][i] > 0){
			totalValue += nMap[nowVisit][i];
			nMap[nowVisit][i] = nMap[i][nowVisit] = 0;
			if(!vis[i])
				dfs(i,head,numMember,totalValue);
		}
	}
}

void dfsTrave(){
	for(int i = 0;i<numPerson;++i){
		int head = i,numMember=0,totalValue=0;
		dfs(i,head,numMember,totalValue);
		if(numMember > 2 && totalValue > k)
			Gang[intTostring[head]] = numMember;
	}
}

int main(int argc, char *argv[])
{
	string str1,str2;
	int w;
	scanf("%d %d",&n,&k);
	for(int i = 0;i<n;++i){
		cin>>str1>>str2>>w;
		int id1 = change(str1);
		int id2 = change(str2);
		weight[id1] += w;
		weight[id2] += w;
		nMap[id1][id2] += w;
		nMap[id2][id1] += w;
	}
	dfsTrave();
	printf("%d\n",Gang.size());
	map<string,int>::iterator iter;
	for(iter = Gang.begin();iter != Gang.end();++iter){
		cout<<iter->first<<" "<<iter->second<<endl;
	}
	return 0;
}