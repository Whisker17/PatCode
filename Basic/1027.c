#include<stdio.h>

int main(){
	int num[22] = {0},j = 0,n;
	char s;
	for(int i = 0;i<22;i++){
		num[i] = 2*i*i+4*i+1;
	}
	scanf("%d %c",&n,&s);
	while(n > num[j] && n > num[j+1]){
		j++;
	}
	for(int k = j;k>=0;k--){
		for(int i = k;i<j;i++)
			printf(" ");
		for(int i = 2*k;i>0;i--)
		{
			printf("%c",s);
		}
		printf("%c\n",s);
	}
	for(int k = 1;k<=j;k++){
		for(int i = k;i<j;i++)
			printf(" ");
		for(int i = 2*k;i>0;i--)
		{
			printf("%c",s);
		}
		printf("%c\n",s);
	}
	printf("%d\n",n-num[j]);
	return 0;
}