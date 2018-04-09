#include<stdio.h>

int main(){
	int n,m,num[105] = {0};
	scanf("%d%d",&n,&m);
	m %= n;
	for(int i = 0;i<n;i++)
		scanf("%d",&num[i]);
	for(int i = n-1;i>=0;i--){
		num[i+m] = num[i];
	}
	for(int i = 0;i<m;i++)
		num[i] = num[n+i];
	for(int i = 0;i<n-1;i++)
		printf("%d ",num[i]);
	printf("%d\n",num[n-1]);
	return 0;
}