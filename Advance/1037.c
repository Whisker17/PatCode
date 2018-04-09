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
	int nc,np,tmp;
	vector<int> numNc,numNp;
	scanf("%d",&nc);
	for(int i = 0;i<nc;++i){
		scanf("%d",&tmp);
		numNc.push_back(tmp);
	} 
	scanf("%d",&np);
	for(int i = 0;i<np;++i){
		scanf("%d",&tmp);
		numNp.push_back(tmp);
	}
	int ans=0;
	sort(numNp.begin(),numNp.end());
	sort(numNc.begin(),numNc.end());
	for(int i = 0;i<nc && i<np;++i){
		if(numNp[i] < 0 && numNc[i] < 0)
			ans += numNp[i]*numNc[i];
		else break;
	}
	int i,j;
	for(i = nc-1,j = np-1;i>=0,j>=0;--i,--j){
		if(numNp[i] > 0 && numNc[i] > 0)
			ans += numNp[i]*numNc[i];
		else break;
	}
	printf("%d\n",ans);
	return 0;
}