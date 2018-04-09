#include<stdio.h>
#include<string.h>

int main(){
	int count[10] = {0};
	char str[1000];
	scanf("%s",str);
	for(int i = 0;i<strlen(str);i++){
		count[str[i]-48]++;
	}
	for(int i = 0;i<10;i++){
		if(count[i] != 0){
			printf("%d:%d\n",i,count[i]);
		}
	}
	return 0;
}