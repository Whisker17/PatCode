#include<stdio.h>
#include<string.h>

int main(){
	char str1[100000],str2[100000],s[100000];
	int flag = 0,n = 0,flag1 = 0;
	gets(str1);
	gets(str2);
	if(strlen(str1) == 0){
		printf("%s\n",str2);
	}
	else{
		for(int i = 0;i<strlen(str1);i++){
			if(str1[i] == '+'){
				flag = 1;
				break;
			}
		}
		if(!flag){
			for(int i = 0;i<strlen(str2);i++){
				flag1 = 0;
				for(int j = 0;j<strlen(str1);j++){
					if(str2[i] == str1[j] || str2[i] == str1[j] + 32){
						flag1 = 1;
						break;
					}
				}
				if(!flag1)
					s[n++] = str2[i];
			}
		}
		else{
			for(int i = 0;i<strlen(str2);i++){
				flag1 = 0;
				for(int j = 0;j<strlen(str1);j++){
					if(str2[i] == str1[j] || str2[i] == str1[j] + 32 || (str2[i] >= 'A' && str2[i] <= 'Z')){
						flag1 = 1;
						break;
					}
				}
				if(!flag1)
					s[n++] = str2[i];
			}
		}
	}
	for(int i = 0;i<n;i++)
		printf("%c",s[i]);
	printf("\n");
	return 0;
}