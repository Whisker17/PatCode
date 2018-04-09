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
	char str[10][7]={"zero","one","two","three","four","five","six","seven","eight","nine"};
	int n,sum=0;
	vector<int> ans;
	scanf("%d",&n);
	do{
		sum += n%10;
		n /= 10;
	}while(n!=0);
	do{
		ans.push_back(sum%10);
		sum /= 10;
	}while(sum!=0);
	int len = ans.size();
	for(int i = len-1;i>=0;--i){
		printf("%s",str[ans[i]]);
		if(i != 0)
			printf(" ");
	}
	return 0;
}