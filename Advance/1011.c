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
	char str[3]={'W','T','L'};
	double a,res=1.0,mNum=0.0;
	int sId;
	vector<int> ans;
	for(int i = 0;i<3;++i){
		mNum = 0.0;
		for(int j = 0;j<3;++j){
			scanf("%lf",&a);
			if(a > mNum){
				mNum = a;
				sId = j;
			}
		}
		printf("%c ",str[sId]);
		res *= mNum;
	}
	res = (res*0.65-1)*2;
	printf("%.2f",res);
	return 0;
}