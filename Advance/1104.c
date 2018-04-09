#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <iostream>
#include <map>
#include <cmath>
using namespace std;

#define maxn 10005

int main(int argc, char *argv[])
{
	int n;
	double num,ans=0;
	scanf("%d",&n);
	for(int i = 1;i<=n;++i){
		scanf("%lf",&num);
		ans += num*i*(n+1-i);
	}
	printf("%.2f\n",ans);
	return 0;
}