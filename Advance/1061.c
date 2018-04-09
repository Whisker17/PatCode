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
	char str1[105],str2[105],str3[105],str4[105];
	char ans[7][4]={"MON","TUE","WED","THU","FRI","SAT","SUN"};
	gets(str1);
	gets(str2);
	gets(str3);
	gets(str4);
	int len1 = strlen(str1);
	int len2 = strlen(str2);
	int len3 = strlen(str3);
	int len4 = strlen(str4);
	int i;
	for(i = 0;i<len1 && i<len2;++i){
		if(str1[i] == str2[i] && str1[i] >= 'A' && str1[i] <= 'G'){
			printf("%s ",ans[str1[i]-'A']);
			break;
		}
	}
	for(i++;i<len1 && i<len2;++i){
		if(str1[i] == str2[i]){
			if(str1[i] >= 'A' && str1[i] <= 'Z'){
				printf("%02d:",str1[i]-'A'+10);
				break;
			}
			else if(str1[i] >= '0' && str1[i] <= '9'){
				printf("%02d:",str1[i]-'0');
				break;
			}
		}
	}
	for(i = 0;i<len3 && i<len4;++i){
		if(str3[i] == str4[i] && (str3[i] >= 'A' && str3[i] <= 'Z' || str3[i] >= 'a' && str3[i] <= 'z')){
			printf("%02d\n",i);
			break;
		}
	}
	return 0;
}