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
	char str[105];
	gets(str);
	int len = strlen(str);
	int n1 = (len+2)/3,n2 = len+2-2*n1,n3 = n1;
	for(int i = 0;i<n1-1;++i){
		printf("%c",str[i]);
		for(int j = 0;j<n2-2;++j){
			printf(" ");
		}
		printf("%c\n",str[len-i-1]);
	} 
	for(int i = 0;i<n2;++i)
		printf("%c",str[n1+i-1]);
	return 0;
}