#include<stdio.h>
#include<string.h>

int main(){
	char str1[1000],str2[1000];
	while(~scanf("%s %s",str1,str2)){
		int len1 = strlen(str1);
		int len2 = strlen(str2);
		int count = 0;
		for(int i = 0;i<len2;i++){
			for(int j = 0;j<len1;j++){
				if(str2[i] == str1[j]){
					str1[j] = str2[i] = '\0';
					break;
				}
			}
		}
		for(int i = 0;i<len2;i++){
			if(str2[i] == '\0')
				count++;
		}
		if(count == len2){
			printf("Yes %d\n",len1-len2);
		}
		else printf("No %d\n",len2-count);
	}
	return 0;
}