#include<stdio.h>

int main(){
	int t;
	long long a[11]={0},b[11]={0},c[11]={0};
	scanf("%d",&t);
	for(int i = 1;i<=t;i++){
		scanf("%ld%ld%ld",&a[i],&b[i],&c[i]);
		if(a[i]+b[i]>c[i])
			printf("Case #%d: true\n",i);
		else printf("Case #%d: false\n",i);
	}
	return 0;
}