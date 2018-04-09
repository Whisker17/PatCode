#include<stdio.h>
#include<stdlib.h>

int cmp(const void *a,const void *b){
	return (*(double*)a - *(double*)b);
}

int main(){
	int n,max = 0;
	double p,num[100000];
	scanf("%d%lf",&n,&p);
	for(int i = 0;i<n;i++)
		scanf("%lf",&num[i]);
	qsort(num,n,sizeof(num[0]),cmp);
	for(int i = 0;i<n;i++){
		for(int j = i+max-1;j<n;j++){
			if(num[i]*p < num[j])
				break;
			if(j+1-i > max)
				max = j+1-i;
		}
	}
	printf("%d\n",max);
	return 0;
}