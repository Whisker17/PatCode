#include<stdio.h>
#include<stdlib.h>

int cmp(const void *a,const void *b){
	return ((*(int*)a) - (*(int*)b));
}
int main(){	
	int n,n1,n2,num[4];
	scanf("%d",&n);
	num[0]=n/1000;
    num[1]=n%1000/100;
    num[2]=n%100/10;
    num[3]=n%10;
	if(num[0] == num[1] && num[1] == num[2] && num[2] == num[3])
		printf("%04d - %04d = 0000",n,n);
	else{
		do{
			num[0]=n/1000;
		    num[1]=n%1000/100;
		    num[2]=n%100/10;
		    num[3]=n%10;
			qsort(num,4,sizeof(num[0]),cmp);
			n1 = num[0]*1000+num[1]*100+num[2]*10+num[3];
			n2 = num[3]*1000+num[2]*100+num[1]*10+num[0];
			n = n2 - n1;
			printf("%04d - %04d = %04d\n",n2,n1,n);
		}while(n != 6174);
	}
	return 0;
}