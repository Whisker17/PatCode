#include<stdio.h>
int main()
{
    int g1=0,s1=0,k1=0,g2=0,s2=0,k2=0;
    long long sum1=0,sum2=0;
    scanf("%d.%d.%d %d.%d.%d",&g1,&s1,&k1,&g2,&s2,&k2);
    sum1 = k1 + 29 * (s1 + 17 * g1);
    sum2 = k2 + 29 * (s2 + 17 * g2);
    if(sum2 >= sum1) 	
		sum2=sum2-sum1;
    else{
    	sum2 = sum1-sum2;
    	printf("-");
    }
    printf("%lld.%lld.%lld",sum2/(17*29),(sum2/29)%17,sum2%29);
    return 0;
     
}