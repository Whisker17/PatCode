#include<stdio.h>

int main(){
	int a1=0,a2=0,a3=0,n,aJ=0,aC=0,aB=0,bJ=0,bC=0,bB=0;
	char x,y;
	scanf("%d",&n);
	for(int i = 0;i<n;i++){
        scanf(" %c %c",&x,&y);
        if((x=='C')&&(y=='J')) {a1++; aC++; continue;}
        if((x=='J')&&(y=='B')) {a1++; aJ++; continue;}
        if((x=='B')&&(y=='C')) {a1++; aB++; continue;}
        if((x=='C')&&(y=='C')) {a2++; continue;}
        if((x=='J')&&(y=='J')) {a2++; continue;}
        if((x=='B')&&(y=='B')) {a2++; continue;}
        if((x=='C')&&(y=='B')) {a3++; bB++; continue;}
        if((x=='B')&&(y=='J')) {a3++; bJ++; continue;}
        if((x=='J')&&(y=='C')) {a3++; bC++; continue;}
	}
	printf("%d %d %d\n%d %d %d\n",a1,a2,a3,a3,a2,a1);
	if((aB>=aC)&&(aB>=aJ))
        printf("B ");
    else if(aC>=aJ)
        printf("C ");
    else
        printf("J ");
    if((bB>=bC)&&(bB>=bJ))
        printf("B");
    else if(bC>=bJ)
        printf("C");
    else
        printf("J");
	return 0;
}