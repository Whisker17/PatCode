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
	int r,g,b;
	char col[13]={'0','1','2','3','4','5','6','7','8','9','A','B','C'};
	scanf("%d%d%d",&r,&g,&b);
	printf("#");
	printf("%c%c",col[r/13],col[r%13]);
	printf("%c%c",col[g/13],col[g%13]);
	printf("%c%c",col[b/13],col[b%13]);	
	return 0;
}