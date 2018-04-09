#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <iostream>
#include <map>
#include <cmath>
using namespace std;

#define maxn 100005

int main(int argc, char *argv[])
{
	int left[maxn]={0},right[maxn]={0},num[maxn];
	int n,cnt=0;
	vector<int> ans;
	scanf("%d",&n);
	for(int i = 0;i<n;++i)
		scanf("%d",&num[i]);
	left[0] = num[0];
	right[n-1] = num[n-1];
	for(int i = 1;i<n;++i){
		left[i] = left[i-1];
		if(num[i] > left[i-1])
			left[i] = num[i];
	}
	for(int i = n-2;i>=0;--i){
		right[i] = right[i+1];
		if(num[i] < right[i+1])
			right[i] = num[i];
	}
	if(right[1] > num[0]){
		++cnt;
		ans.push_back(num[0]);
	}
	for(int i = 1;i<n-1;++i){
		if(num[i] > left[i-1] && num[i] < right[i+1]){
			++cnt;
			ans.push_back(num[i]);
		}
	}
	if(left[n-2] < num[n-1]){
		++cnt;
		ans.push_back(num[n-1]);
	}
	printf("%d\n",cnt);
	for(int i = 0;i<cnt;++i){
		if(i>0)
			printf(" ");
		printf("%d",ans[i]);
	}
	printf("\n"); 
	return 0;
}