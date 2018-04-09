#include<stdio.h>

int main(){
	int a,b,c,h,m,s;
	scanf("%d%d",&a,&b);
	c=(b-a)/100;
    if((b-a)%100 >= 50)
        c++;
    h = c / 3600;
    m = c % 3600 / 60;
    s = c % 60;
    printf("%02d:%02d:%02d\n",h,m,s);
	return 0;
}