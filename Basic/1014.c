#include<stdio.h>
#include<string.h>;

int main(){
	char str1[60],str2[60],str3[60],str4[60];
	int j,t;
	scanf("%s%s%s%s",str1,str2,str3,str4);
	int len1 = strlen(str1)<strlen(str2)?strlen(str1):strlen(str2);
	int len2 = strlen(str3)<strlen(str4)?strlen(str3):strlen(str4);
	for(int i = 0;i<len1;i++){
		if(str1[i] == str2[i] && str1[i] >= 'A' && str1[i] <= 'G'){
			switch(str1[i]){
				case 'A':
					printf("MON ");
					break;
				case 'B':
					printf("TUE ");
					break;
				case 'C':
					printf("WED ");
					break;
				case 'D':
					printf("THU ");
					break;
				case 'E':
					printf("FRI ");
					break;
				case 'F':
					printf("SAT ");
					break;
				case 'G':
					printf("SUN ");
					break;	
			}
			j = i;
			break;
		}
	}
	for(int i = j+1;i<len1;i++){
		if(str1[i] == str2[i] && ((str1[i] >= 'A' && str1[i] <= 'N') || (str1[i] >= '0' && str1[i] <= '9'))){
			if(str1[i] >= 'A' && str1[i] <= 'N'){
				t = str1[i] - 'A' + 10;
			}
			else t = str1[i] - '0';
			printf("%d%d:",t/10,t%10);
			break;
		}
	}
	for(int i = 0;i<len2;i++){
		if(str3[i] == str4[i] && ((str3[i] >= 'A' && str3[i] <= 'Z') || (str3[i] >= 'a' && str3[i] <= 'z'))){
			printf("%d%d\n",i/10,i%10);
			break;
		}
	}
	return 0;
}