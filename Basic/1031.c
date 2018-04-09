#include<stdio.h>

int main()
{
	int n,i,j,count,sum,num[17]={7,9,10,5,8,4,2,1,6,3,7,9,10,5,8,4,2};
	char str2[11]={'1','0','X','9','8','7','6','5','4','3','2'};
	char str[100][20];
	scanf("%d",&n);
	count = 0;
	for(i=0;i<n;i++)
	{
		scanf("%s",str[i]);
		sum = 0;
		for(j = 0;j<17;j++)
		{
			if(str[i][j]<'0' || str[i][j]>'9')
		 		break;
			sum += (str[i][j]-'0')*num[j];
		}
		if(j<17)
		{
			printf("%s\n",str[i]);
			continue;
		}
		sum%=11;
		if(str2[sum]==str[i][j]) 
			count++;
		else printf("%s\n",str[i]);
	}
	if(count == n) 
		printf("All passed\n");
	return 0;
}