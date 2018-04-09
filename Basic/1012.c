#include<stdio.h>

int main(){
	int t,j = 1,n,flag = 0,count = 0;
	double num[5] = {0};
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		switch(n%5){
			case 0:
				if(n%2 == 0)
					num[0] += n;
				break;
			case 1:
				num[1] += j*n;
				j *= -1;
				flag++;
				break;
			case 2:
				num[2]++;
				break;
			case 3:
				num[3] += n;
				count++;
				break;
			case 4:
				if(n>num[4])
					num[4] = n;
				break;
		}
	}
	if(count != 0){
		num[3] /= (double)count;
	}
	for(int i = 0;i<5;i++){
		if(i == 3){
			if(num[3] == 0)
				printf("N");
			else printf("%0.1f",num[i]);
		}
		else if(i == 1){
			if(!flag)
				printf("N");
			else printf("%d",(int)num[i]);
		}
		else{
			if(num[i] == 0)
				printf("N");
			else printf("%d",(int)num[i]);
		}
		if(i != 4){  
			printf(" ");
		}
	}
}