#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <iostream>
#include <map>
#include <cmath>
using namespace std;

#define maxn 100005

int main(int argc, char *argv[])
{
	char str1[maxn],str2[maxn];
	gets(str1);
	gets(str2);
	bool hashTable[256]={false};
	int len1 = strlen(str1);
	int len2 = strlen(str2);
	for(int i = 0;i<len2;++i){
		hashTable[str2[i]] = true;
	}
	for(int i = 0;i<len1;++i){
		if(hashTable[str1[i]])
			continue;
		printf("%c",str1[i]);
	}
	return 0;
}