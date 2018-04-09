#include<stdio.h>

int main(){
	int n,num1[100000],num2[100000],t;
	while(~scanf("%d",&n)){
		int count[100000] = {0};
		for(int i = 0;i<n;i++)
			scanf("%d",&num1[i]);
		scanf("%d",&t);
		for(int i = 0;i<t;i++)
			scanf("%d",&num2[i]);
		for(int i = 0;i<t;i++){
			for(int j = 0;j<n;j++){
				if(num2[i] == num1[j])
					count[i]++;
			}
		}
		for(int i = 0;i<t-1;i++)
			printf("%d ",count[i]);
		printf("%d\n",count[t-1]);
	}
	return 0;
}