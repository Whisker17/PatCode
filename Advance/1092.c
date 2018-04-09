#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <iostream>
#include <map>
#include <cmath>
using namespace std;

#define maxn 100005

int change(char c){
	if(c >= 'A' && c <= 'Z')
		return c-'A'+36;
	else if(c >= 'a' && c <= 'z')
		return c-'a'+10;
	else if(c >= '0' && c <= '9')
		return c-'0';
}

int main(int argc, char *argv[])
{
	char str1[maxn],str2[maxn];
	bool flag = true;
	gets(str1);
	gets(str2);
	int len1 = strlen(str1);
	int len2 = strlen(str2);
	int hashTable[256]={0};
	int ans = 0;
	for(int i = 0;i<len1;++i){
		++hashTable[change(str1[i])];
	}
	for(int i = 0;i<len2;++i){
		--hashTable[change(str2[i])];
		if(hashTable[change(str2[i])] < 0){
			++ans;
			flag = false;
			continue;
		}
		--len1;
	}
	if(flag)
		printf("Yes %d\n",len1);
	else printf("No %d\n",ans);
	return 0;
}