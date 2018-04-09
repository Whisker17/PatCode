#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <iostream>
#include <map>
#include <cmath>
using namespace std;

#define maxn 100005
#define MOD 1000000007

int main(int argc, char *argv[])
{
	int left[maxn]={0},right[maxn]={0};
	char str[maxn];
	vector<int> num;
	int ans = 0;
	scanf("%s",str);
	int len = strlen(str);
	if(str[0] == 'P')
		left[0] = 1;
	if(str[len-1] == 'T')
		right[len-1] = 1;
	for(int i = 1;i<len-1;++i){
		left[i] = left[i-1];
		if(str[i] == 'A')
			num.push_back(i);
		else if(str[i] == 'P')
			left[i] = left[i-1]+1;
	}
	for(int i = len-2;i>0;--i){
		right[i] = right[i+1];
		if(str[i] == 'T')
			right[i] = right[i+1]+1;
	}
	int len2 = num.size();
	/*for(int i = 0;i<len;++i)
		printf("%d ",left[i]);
	cout<<endl;
	for(int i = 0;i<len;++i)
		printf("%d ",right[i]);
	cout<<endl;*/
	for(int i = 0;i<len2;++i){
		ans = (ans + left[num[i]-1] * right[num[i]+1])%MOD;
	}
	printf("%d\n",ans);
	return 0;
}