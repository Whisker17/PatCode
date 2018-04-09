#include<stdio.h>
#include<stdlib.h>

struct yb{
	double l,t;
	double p;	
}num[1000];
int cmp(const void *a,const void *b){
	return (int)((*(yb*)a).p - (*(yb*)b).p);
}
int main(){
	int n,m;
	double temp = 0;
	scanf("%d%d",&n,&m);
	for(int i = 0;i<n;i++)
		scanf("%lf",&num[i].l);
	for(int i = 0;i<n;i++)
		scanf("%lf",&num[i].t);
	for(int i = 0;i<n;i++)
		num[i].p = num[i].t / num[i].l;
	qsort(num,n,sizeof(num[0]),cmp);
	for(int i = 0;i<n;i++){
		if(m > num[i].l){
			temp += num[i].t;
			m -= num[i].l;
		}
		else{
			temp += m * num[i].p;
			break;
		}
	}
	printf("%.2lf\n",temp);
	return 0;
}