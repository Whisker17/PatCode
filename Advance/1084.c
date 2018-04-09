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
	bool hashTable[128]={false};
	gets(str1);
	gets(str2);
	int len1 = strlen(str1);
	int len2 = strlen(str2);
	for(int i = 0;i<len1;++i){
		char c1,c2;
		int j;
		for(j = 0;j<len2;++j){
			c1 = str1[i];
			c2 = str2[j];
			if(c1 >= 'a' && c1 <= 'z') 
				c1 -= 32;
			if(c2 >= 'a' && c2 <= 'z') 
				c2 -= 32;
			if(c1 == c2)
				break;
		}
		if(j == len2 && !hashTable[c1]){
			printf("%c",c1);
			hashTable[c1] = true;
		}
	}
	return 0;
}