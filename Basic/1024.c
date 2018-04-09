#include<stdio.h>
#include<string.h>

int main(){
	int temp = 0,e = 1,n,flag = 0;
	char str[10000];
	scanf("%s",str);
	if(str[0] == '-')
		printf("-");
	n = strlen(str) - 1;
	while(str[n] != '+' && str[n] != '-'){
		temp += (str[n]-'0') * e;
		e *= 10;
		n--;
	}
	if(str[n] == '+')
		flag = 1;
	else if(str[n] == '-') flag = 2;
	if(temp == 0){
		for(int i = 1;i<n-1;i++)
			printf("%c",str[i]);
	}
	else if(flag == 1){
		for(int i = 1;i<n-1;i++){
			if(temp == i-3)
				printf(".");
			if(str[i] != '.')
				printf("%c",str[i]);
		}
		int j = temp-n+4;
		while(j--){
			printf("0");
		}
	}
	else if(flag == 2){
		printf("0.");
		temp--;
		while(temp--){
			printf("0");
		}
		for(int i = 1;i<n-1;i++){
			if(str[i] != '.')
				printf("%c",str[i]);
		}
	}
	return 0;
}