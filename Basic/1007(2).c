#include<stdio.h>
#include<math.h>

int main()
{
	int n,count = 0,flag = 1,k = 0,t = 0;
	scanf("%d",&n);
	int a[10000]={0};
	for(int i = 2;i<10000;i++){
		flag = 1;
		for(int j = 2;j<=sqrt(i);j++){
			if(i%j == 0){
				flag = 0;
				continue;
			}
		}
		if(flag){
			a[k] = i;
			k++;
		} 
	}
	while(a[t]<=n){
		if(a[t]-a[t-1] == 2){
			count++;
		}
		t++;
	}
	printf("%d",count);
	return 0;
}