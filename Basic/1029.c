#include<stdio.h>
#include<string.h>

int main(){
	int j = 0,k = 0;
	char str1[80],str2[80],str3[80];
	scanf("%s%s",str1,str2);
	for(int i = 0;i<strlen(str1);i++){
		if(strchr(str2,str1[i]) == 0 && strchr(str3,str1[i]) == 0){
			if((str1[i])>='a'&&(str1[i])<='z')  
                str1[i] -= 32;
            if(strchr(str3,str1[i]) == 0)
            	str3[j++] = str1[i];
		}
	}
	for(int i = 0;i<j;i++)
		printf("%c",str3[i]);	
	return 0;
}