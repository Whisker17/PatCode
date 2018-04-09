#include <stdio.h>  
#include <string.h>  

int main() {  
    char str[100001];  
    gets(str);  
    int num1 = 0,num2 = 0,num3 = 0;  
    int len = strlen(str);
    for(int i = len-1; i >= 0;i--) {    
        if(str[i] == 'T')         
            num1++;  
        else if(str[i] == 'A')  
            num2 = (num2 + num1) % 1000000007;  
        else {   
            num3 = (num3 + num2) % 1000000007;  
        }  
    }  
    printf("%d",num3);  
    return 0;  
} 