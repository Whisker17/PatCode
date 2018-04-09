#include<stdio.h>
#include<string.h>

int main(){
	char str[100];
	gets(str);
	if(strrchr(str,' ') == NULL){
		printf("%s",str);
	}
	else {
		while(strrchr(str,' ') != NULL){
			printf("%s ",strrchr(str,' ') + sizeof(char));
			*strrchr(str,' ') = 0;
		}
		printf("%s",str);
	}
	return 0;
}