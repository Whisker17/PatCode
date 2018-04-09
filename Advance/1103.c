#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <iostream>
#include <map>
#include <cmath>
using namespace std;
	
int num,n,p,maxFacSum=-1;
vector<int> fac,ans,temp;

int power(int x){
	int res = 1;
	for(int i = 0;i<p;++i)
		res *= x;
	return res;
}

void init(){
	int temp=0;
	for(int i = 0;temp <= num;++i){
		temp = power(i);
		fac.push_back(temp);
	}
}

void dfs(int index,int now,int sum,int facSum){
	if(sum == num && now == n){
		if(facSum > maxFacSum){
			maxFacSum = facSum;
			ans = temp;
		}
	}
	if(sum > num || now > n)
		return ;
	if(index >= 1){
		temp.push_back(index);
		dfs(index,now+1,sum+fac[index],facSum+index);
		temp.pop_back();
		dfs(index-1,now,sum,facSum);
	}
}

int main(int argc, char *argv[])
{
	scanf("%d %d %d",&num,&n,&p);
	init();
	dfs(fac.size()-1,0,0,0);
	if(maxFacSum == -1)
		printf("Impossible\n");
	else{
		printf("%d = %d^%d",num,ans[0],p);
		for(int i = 1;i<ans.size();++i)
			printf(" + %d^%d",ans[i],p);
	}
	return 0;
}