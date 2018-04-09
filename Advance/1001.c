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
	int a,b,sum;
	vector<int> ans;
	scanf("%d %d",&a,&b);
	sum = a + b;
	if(sum < 0){
		printf("-");
		sum = -sum;
	}
	do{
		ans.push_back(sum%10);
		sum /= 10;	
	}while(sum);
	int len = ans.size();
	for(int i = len-1;i>=0;--i){
		printf("%d",ans[i]);
		if(i>0 && i%3 == 0)
			printf(",");
	}
	return 0;
}