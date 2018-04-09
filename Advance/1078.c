#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <iostream>
#include <map>
#include <cmath>
using namespace std;

#define maxn 100005

bool isPrime(int a) {
    if(a == 1) return false;
    for(int i = 2; i * i <= a; i++)
        if(a % i == 0)
            return false;
    return true;
}

int main(int argc, char *argv[])
{
	int n,m,tmp;
	bool hashTable[maxn]={0};
	scanf("%d %d",&n,&m);
	while(!isPrime(n))
		++n;
	for(int i = 0;i<m;++i){
		scanf("%d",&tmp);
		int temp = tmp%n;
		if(!hashTable[temp]){
			hashTable[temp] = true;
			if(i == 0)
				printf("%d",temp);
			else printf(" %d",temp);
		}
		else{
			int cnt;
			for(cnt = 1;cnt < n;++cnt){
				int res = (tmp+cnt*cnt)%n;
				if(!hashTable[res]){
					hashTable[res] = true;
					if(i == 0)
						printf("%d",res);
					else printf(" %d",res);
					break;
				}
			}
			if(cnt >= n){
				if(i > 0)
					printf(" ");
				printf("-");
			}
		}
	}
	return 0;
}