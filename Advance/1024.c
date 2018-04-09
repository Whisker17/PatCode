#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <iostream>
#include <map>
#include <cmath>
using namespace std;

struct bign{
	int num[1005],len;
	bign(){
		len = 0;
		memset(num,0,sizeof(num));
	}
};

bign strToNum(char num[]){
	bign res;
	res.len = strlen(num);
	for(int i = 0;i<res.len;++i){
		res.num[i] = num[res.len-i-1]-'0';
	}
	return res;
}

bign add(bign a,bign b){
	bign res;
	int carry = 0;
	for(int i = 0;i < a.len;++i){
		int temp = a.num[i] + b.num[i] +carry;
		res.num[res.len++] = temp%10;
		carry = temp/10;
		//printf("%d %d %d\n",temp,res.num[res.len-1],carry);
	}
	while(carry != 0){
		res.num[res.len++] = carry%10;
		carry /= 10;
	}
	return res;
}

bool judge(bign a){
	for(int i = 0;i<=a.len/2;++i){
		if(a.num[i] != a.num[a.len-1-i])
			return false; 
	}
	return true;
}

void showBign(bign a){
	for(int i = a.len-1;i>=0;--i){
		printf("%d",a.num[i]);
	}
	printf("\n");
}

int main(int argc, char *argv[])
{
	int n,i;
	char str[1005];
	scanf("%s %d",str,&n);
	bign a = strToNum(str);
	for(i = 0;i<n;++i){
		if(judge(a)){
			showBign(a);
			printf("%d\n",i);
			return 0;
		}
		else{
			bign b = a;
			reverse(b.num,b.num+b.len);
			a = add(a,b);
		}
	}
	showBign(a);
	printf("%d\n",n);
	return 0;
}