#include<stdio.h>
 int main(){
 	int n;
 	char s;
 	while(~scanf("%d %c",&n,&s)){
	 	for(int i = 0;i<n;i++)
	 		printf("%c",s);
 		printf("\n");
 		for(int i = 0;i<(n+1)/2-2;i++){
 			printf("%c",s);
			for(int j = 0;j<n-2;j++)
				printf(" ");
			printf("%c\n",s); 	
	 	}
	 	for(int i = 0;i<n;i++)
	 		printf("%c",s);
 		printf("\n");
	 }
 	return 0;
 }