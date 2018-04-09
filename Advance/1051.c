#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <iostream>
#include <map>
#include <cmath>
#include <stack>
using namespace std;

#define maxn 100005

stack<int> st;

int main(int argc, char *argv[])
{
	int m,n,k,cnt;
	int num[maxn];
	scanf("%d %d %d",&m,&n,&k);
	while(k--){
		while(!st.empty()){
			st.pop();
		}
		cnt=1;
		for(int i = 1;i<=n;++i){
			scanf("%d",&num[i]);
		}
		bool flag = true;
		for(int i = 1;i<=n;++i){
			st.push(i);
			if(st.size() > m){
				flag = false;
				break;
			}
			while(!st.empty() && st.top() == num[cnt]){
				st.pop();
				++cnt;
			}
		}
		if(st.empty() && flag)
			printf("YES\n");
		else printf("NO\n");
	} 
	return 0;
}