#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <iostream>
#include <map>
#include <cmath>
using namespace std;

#define maxn 10005

int main(int argc, char *argv[])
{
	int n,m,tmp;
	vector<int> num;
	int hashTable[maxn]={0};
	bool flag = false;
	scanf("%d %d",&n,&m);
	for(int i = 0;i<n;++i){
		scanf("%d",&tmp);
		num.push_back(tmp);
		hashTable[tmp]++;
	}
	sort(num.begin(),num.end());
	for(int i = 0;i<n;++i){
		if(hashTable[num[i]] && hashTable[m-num[i]]){
			if(num[i] == m-num[i] && hashTable[num[i]] < 2)
				continue;
			flag = true;
			printf("%d %d\n",num[i],m-num[i]);
			return 0;
		}
	}
	if(!flag)
		printf("No Solution\n");
	return 0;
}