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
	int n,ans=0,now=0,sAim;
	scanf("%d",&n);
	for(int i = 0;i<n;++i){
		scanf("%d",&sAim);
		if(sAim > now){
			ans += ((sAim-now)*6);
		}
		else{
			ans += ((now-sAim)*4);
		}
		ans += 5;
		now = sAim;
	}
	printf("%d\n",ans);
	return 0;
}