#include<stdio.h>
#include<math.h>

int isPrime(int a)
{
	for(int i = 3;i <= sqrt(a);i+=2)
		if(a % i == 0)
	 		return 0;
	return 1;
}
int main()
{
	int n,count;
	scanf("%d",&n);
	if(n >= 1 && n < 100000){
		count=0;
		for(int i = 3;i <= n-2;i += 2)
			if(isPrime(i)&&isPrime(i+2)) 
				count++;
		printf("%d\n",count);
	}
	return 0;
}