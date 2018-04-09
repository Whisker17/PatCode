#include<stdio.h>
#include<stdlib.h>
struct stu{
	int num;
	int d;
	int c;
};
int cmp(const void *a, const void *b)
{
    if((*(stu*)a).d+(*(stu*)a).c != (*(stu*)b).d+(*(stu*)b).c)
        return ((*(stu*)b).d+(*(stu*)b).c)-((*(stu*)a).d+(*(stu*)a).c);
    else if((*(stu*)a).d != (*(stu*)b).d)
        return (*(stu*)b).d-(*(stu*)a).d;
    else return (*(stu*)a).num-(*(stu*)b).num;
}

int main(){
	int 
	scanf("%d%d%d",&n,&d,&c);
	
	return 0;
}