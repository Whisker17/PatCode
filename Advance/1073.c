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
	char str[10005];
	int e;
	gets(str);
	int len = strlen(str);
	int exp = 0;
	if(str[0] == '-'){
		printf("-");
	}
	for(int i = 0;i<len;++i){
		if(str[i] == 'E'){
			e = i;
			break;
		}
	}
	for(int i = e+2;i<len;++i){
		exp = (str[i]-'0')+exp*10;
	}
	if(exp == 0){
		for(int i = 1;i<e;++i)
			printf("%c",str[i]);
	}
	if(str[e+1] == '-'){
		printf("0.");
		for(int i = 0;i<exp-1;++i){
			printf("0");
		}
		printf("%c",str[1]);
		for(int i = 3;i<e;++i){
			printf("%c",str[i]);
		}
	}
	else{
		for(int i = 1;i<e;++i){
			if(str[i] == '.')
				continue;
			printf("%c",str[i]);
			if(i == exp +2 && e-3 !=exp)
				printf(".");
		}
		for(int i = 0;i<exp-(e-3);++i)
			printf("0");
	}
	return 0;
}