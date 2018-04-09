#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <iostream>
#include <map>
#include <cmath>
using namespace std;

int main(int argc, char *argv[])
{
	int n,tmp;
	int hashTable[10001]={0};
	vector<int> num;
	bool flag = false;
	scanf("%d",&n);
	for(int i = 0;i<n;++i){
		scanf("%d",&tmp);
		num.push_back(tmp);
		++hashTable[tmp];
	}
	for(int i = 0;i<n;++i){
		if(hashTable[num[i]] == 1){
			flag = true;
			printf("%d\n",num[i]);
			return 0;
		}
	}
	if(!flag)
		printf("None\n");
	return 0;
}