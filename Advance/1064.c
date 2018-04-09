#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <iostream>
#include <map>
#include <cmath>
using namespace std;

#define maxn 1005

int node[maxn],cnt=0,num[maxn],n;

void inOrder(int root){
	if(root > n)
		return ;
	inOrder(root*2);
	node[root] = num[cnt++];
	inOrder(root*2+1);
} 

int main(int argc, char *argv[])
{
	scanf("%d",&n);
	for(int i = 0;i<n;++i){
		scanf("%d",&num[i]);
	}
	sort(num,num+n);
	inOrder(1);
	for(int i = 1;i<=n;++i){
		printf("%d",node[i]);
		if(i != n)
			printf(" ");
	}
	return 0;
}