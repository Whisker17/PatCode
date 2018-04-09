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
	int n,minLen = 256,res = 0;
	char str[105][260];
	scanf("%d",&n);
	getchar();
	for(int i = 0;i<n;++i){
		gets(str[i]);
		int len = strlen(str[i]);
		if(minLen > len)
			minLen = len;
		for(int j = 0;j<len/2;++j){
			char tmp = str[i][j];
			str[i][j] = str[i][len-1-j];
			str[i][len-1-j] = tmp;
		}
	}
	for(int i = 0;i<minLen;++i){
		bool flag = true;
		for(int j = 1;j<n;++j){
			if(str[j][i] != str[j-1][i]){
				flag = false;
				break;
			}
		}
		if(flag){
			++res;
		}
		else break;
	}
	if(res){
		for(int i = res-1;i>=0;--i)
			printf("%c",str[0][i]);
	}
	else{
		printf("nai");
	}
	return 0;
}