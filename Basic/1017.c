#include<stdio.h>
#include<string.h>

int main(){
	char str[1000];
	int n,num,first = 1,y = 0;
	scanf("%s%d",str,&n);
	if(strlen(str) == 1 && (str[0]-48) < n)
		printf("0 %d",n);
	else{
		for(int i = 0;i<strlen(str);i++){
			num = (str[i]-48+y*10)/n;
			y = (str[i]-48+y*10)%n;
			if(first){
				if(num != 0)
					printf("%d",num);
				first = 0;
			}
			else printf("%d",num);
		}
		printf(" %d",y);
	}
	return 0;
}