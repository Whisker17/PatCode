#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <iostream>
#include <map>
#include <cmath>
using namespace std;

#define maxn 1005
#define ll long long

ll INF = (1ll << 63) - 1;

int cMap[256];

void init(){
	for(char c = '0';c<='9';++c)
		cMap[c] = c-'0';
	for(char c = 'a';c<='z';++c)
		cMap[c] = c-'a'+10;
}

ll convertTo10(char num[],ll index,ll t){
	int len = strlen(num);
	ll ans = 0;
	for(int i = 0;i<len;++i){
		ans = ans*index + cMap[num[i]];
		if(ans < 0 || ans > t)
			return -1;
	}	
	return ans;
}

int nCmp(char num[],ll index,ll t){
	int len = strlen(num);
	ll tmp = convertTo10(num,index,t);	
	if(tmp < 0)
		return 1;
	if(t > tmp)
		return -1;
	else if(tmp == t)
		return 0;
	else return 1;
}

ll binarySearch(char num[],ll low,ll high,ll t){
	ll mid;
	while(low <= high){
		mid = (low + high)/2;
		if(nCmp(num,mid,t) == 1)
			high = mid-1;
		else if(nCmp(num,mid,t) == -1)
			low = mid + 1;
		else if(nCmp(num,mid,t) == 0)
			return mid;
	}
	return -1;
}

int findMax(char num[]){
	int ans = -1;
	int len = strlen(num);
	for(int i = 0;i<len;++i){
		if(cMap[num[i]] > ans)
			ans = cMap[num[i]];
	} 
	return ans+1;
}

int main(int argc, char *argv[])
{
	int tag;
	int index;
	char n1[maxn],n2[maxn],temp[maxn];
	scanf("%s %s",n1,n2);
	scanf("%d %d",&tag,&index);
	init();
	if(tag == 2){
		strcpy(temp,n1);
		strcpy(n1,n2);
		strcpy(n2,temp);
	}
	ll t = convertTo10(n1,index,INF);
	ll low = findMax(n2);
	ll high = max(t,low)+1;
	ll ans = binarySearch(n2,low,high,t);
	if(ans == -1)
		printf("Impossible\n");
	else printf("%lld\n",ans);
	return 0;
}
