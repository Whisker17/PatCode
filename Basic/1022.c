#include<stdio.h>

int main(){
	int a,b,n,sum,num[1000],j = 0;
	scanf("%d%d%d",&a,&b,&n);
	sum = a + b;
	while(sum != 0){
		num[j++] = sum%n;
		sum /= n;
	}	
	if(j == 0) 
		printf("0");
	else{
		for(int i = j-1;i>=0;i--){
			printf("%d",num[i]);
		}
	}
	return 0;	
}