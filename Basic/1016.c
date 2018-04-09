#include<stdio.h>
#include<string.h>

int main(){
	char str1[10],str2[10];
	int len1,len2,n1,n2,count1 = 0,count2 = 0,sum1 = 0,sum2 = 0;
	scanf("%s%d%s%d",str1,&n1,str2,&n2);
	len1 = strlen(str1);
	len2 = strlen(str2);
	for(int i = 0;i<len1;i++){
		if(str1[i] == n1 + 48)
			count1++;
	}
	for(int i = 0;i<count1;i++){
		sum1 = sum1*10 + n1;
	}
	for(int i = 0;i<len2;i++){
		if(str2[i] == n2 + 48)
			count2++;
	}
	for(int i = 0;i<count2;i++){
		sum2 = sum2*10 + n2;
	}
	printf("%d\n",sum1+sum2);
	return 0;
}