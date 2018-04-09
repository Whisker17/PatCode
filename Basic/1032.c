#include<stdio.h>

int num[100001] = {0};
int main(){
	int max1 = 0,max2 = 0,max = -1,n,a,b;
	scanf("%d",&n);
	for(int i = 0;i<n;i++){
		scanf("%d%d",&a,&b);
		num[a] += b;
		if(a > max1)
			max1 = a;
	}
	for(int i = 1;i<=max1;i++){
		if(num[i] > max){
			max = num[i];
			max2 = i;
		}
	}
	printf("%d %d\n",max2,max);
	return 0;
}