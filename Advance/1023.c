#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <iostream>
#include <map>
#include <cmath>
using namespace std;

#define maxn 100005

struct bign{
	int num[21];
	int len;
	bign(){
		memset(num,0,sizeof(num));
		len = 0;
	}
};

bign strToNum(char num[]){
	int len  = strlen(num);
	bign res;
	res.len = len;
	for(int i = 0;i<len;++i){
		res.num[i] = num[res.len - i - 1]-'0';
	}
	return res;
}

bign multi(bign a,int b){
	int carry = 0;
	bign res;
	for(int i = 0;i<a.len;++i){
		int temp = a.num[i] * b + carry;
		carry = temp/10;
		res.num[res.len++] = temp % 10;
	}
	while(carry != 0){
		res.num[res.len++] = carry%10;
		carry /= 10;
	}
	return res;
}

bool judge(bign a,bign b){
	int cnt[11]={0};
	for(int i = 0;i<a.len;++i){
		++cnt[a.num[i]];
		--cnt[b.num[i]];
	} 
	for(int i = 0;i<10;++i){
		if(cnt[i] != 0)
			return false;
	}
	return true;
}

void showRes(bign a){
	for(int i = a.len-1;i>=0;--i)
		printf("%d",a.num[i]);
}

int main(int argc, char *argv[])
{
	char str[20]; 
	gets(str);
	bign a = strToNum(str);
	bign b = multi(a,2);
	if(judge(a,b))
		printf("Yes\n");
	else printf("No\n");
	showRes(b);
	return 0;
}