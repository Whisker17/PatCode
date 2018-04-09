#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <iostream>
#include <map>
#include <set>
#include <cmath>
using namespace std;

#define maxn 105

double compare(set<int> a,set<int> b){
	int len1 = a.size();
	int notSame = 0; 
	set<int>::iterator iter;
	for(iter = b.begin();iter != b.end();++iter){
		if(a.find(*iter) != a.end())
			++notSame;
		else ++len1;
	}
	return notSame*100.0/(len1);
}

int main(int argc, char *argv[])
{
	int n,ni,tmp,t,s1,s2;
	set<int> a[maxn];
	scanf("%d",&n);
	for(int i = 0;i<n;++i){
		scanf("%d",&ni);
		for(int j = 0;j<ni;++j){
			scanf("%d",&tmp);
			a[i].insert(tmp);
		}
	}
	scanf("%d",&t);
	for(int i = 0;i<t;++i){
		scanf("%d %d",&s1,&s2);
		printf("%.1lf%%\n",compare(a[s1-1],a[s2-1]));
	}
	return 0;
}