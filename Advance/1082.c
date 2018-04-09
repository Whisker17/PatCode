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
	char wei[5][5]={"Shi","Bai","Qian","Wan","Yi"};
	char num[10][5]={"ling","yi","er","san","si","wu","liu","qi","ba","jiu"};
	char input[15];
	gets(input);
	int len = strlen(input);
	int left = 0,right = len-1;
	if(input[0] == '-'){
		printf("Fu");
		++left;
	}
	while(left+4 <= right)
		right -= 4;
	while(left < len){
		bool flag = false;
		bool isPrint = false;
		while(left <= right){
			if(left > 0 && input[left] == '0')
				flag = true;
			else{
				if(flag){
					printf(" ling");
					flag = false;
				}
				if(left > 0)
					printf(" ");
				printf("%s",num[input[left]-'0']);
				isPrint = true;
				if(left != right)
					printf(" %s",wei[right-left-1]);
			}
			++left;
		}
		if(isPrint && right != len-1){
			printf(" %s",wei[(len-1-right)/4+2]);
		}
		right += 4;
	}
	return 0;
}