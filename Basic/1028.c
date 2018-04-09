#include<stdio.h>
#include<string.h>

int isBig(char s1[10],char s2[10]){
	for(int i = 0;i<10;i++){
		if(s1[i] > s2[i])
			return 1;
		if(s1[i] < s2[i])
			return 0;
	}
	return 0;
}
int main(){
	char name1[10],name2[10],str1[10],str2[10],str3[20]="1814/09/05",str4[20]="2014/09/07";
	int count = 0,n;
	scanf("%d",&n);
	for(int i = 0;i<n;i++){
		scanf("%s %s",str1,str2);
		if(isBig(str2,"1814/09/05") && isBig("2014/09/07",str2)){
			if(isBig(str2,str3)){
				strcpy(str3,str2);
				strcpy(name1,str1);
			}
			if(isBig(str4,str2)){
				strcpy(str4,str2);
				strcpy(name2,str1);
			}
			count++;
		}
	}
	if(!count)
		printf("0\n");
	else printf("%d %s %s",count,name2,name1);
	return 0;
}