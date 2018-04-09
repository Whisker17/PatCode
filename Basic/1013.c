#include<stdio.h>
#include<math.h>

int sushu(int n){
	for(int i = 2;i<=sqrt(n);i++){
		if(n%i == 0)		
			return 0;		
	}
	return 1;
}

int main(){
	int i = 2,n,m,k = 0,count = 0;
	scanf("%d%d",&n,&m);
	while(1){
		if(sushu(i)){
			k++;
			if(k>=n && k<m){
				count++;
				if(count%10 == 0)
					printf("%d\n",i);
				else printf("%d ",i);
			}
			if(k == m){
				printf("%d",i);
				break;
			}
		}
		i++;
	}
	return 0;
}