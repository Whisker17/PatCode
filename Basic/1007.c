#include<stdio.h>
#include<math.h>
int main(){
	int n,a[10000]={0},count = 0;
	scanf("%d",&n);
	a[0] = a[1] = 1;
	for(int i = 4;i<10000;i++){
		for(int j = 2;j<=sqrt(i);j++){
			if(i%j == 0){
				a[i] = 1;
				continue;
			}
		}
	}
	for(int i = 2;i<=n-2;i++){
		if(a[i] == 0 && a[i+2] == 0)
			count++;
	}
	printf("%d\n",count);
	return 0;
}