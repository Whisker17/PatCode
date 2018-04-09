#include<stdio.h>
#include<string.h>

int main(){
	char str[1000];
	int n,num = 0,first = 0;
	scanf("%s%d",str,&n);
	for(int i = 0;i<strlen(str);i++){
		num = num*10+str[i]-48;
		if(num>=n){
			printf("%d",num/n);
			first = 1;
		}
		else if(first){
			printf("0");
		}
		num = num%n;
	}
	if(first == 0)
		printf("0");
	printf(" %d\n",num);
	return 0;
}