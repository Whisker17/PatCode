#include<stdio.h>

int main(){
	int a,b,flag = 0;
	while(scanf("%d%d",&a,&b) != EOF){
		if(b>0){
			if(flag == 0)
			{
				printf("%d %d",a*b,b-1);
				flag = 1;
			}
			else printf(" %d %d",a*b,b-1);
		}
	}
	if(!flag)
		printf("0 0");
	return 0;
}