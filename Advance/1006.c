#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <iostream>
#include <map>
#include <cmath>
using namespace std;
struct Stu{
	char sId[16];
	int hh,mm,ss;
}stu[1005],tmp1,tmp2;
int main(int argc, char *argv[])
{
	int n;
 	tmp1.hh = 24,tmp1.mm = 60,tmp1.ss = 60;
	tmp2.hh= 0,tmp2.mm = 0,tmp2.ss = 0;
	scanf("%d",&n);
	for(int i = 0;i<n;++i){
		scanf("%s %d:%d:%d",&stu[i].sId,&stu[i].hh,&stu[i].mm,&stu[i].ss);
		if(stu[i].hh < tmp1.hh)
			tmp1 = stu[i];
		else if(stu[i].hh == tmp1.hh && stu[i].mm < tmp1.mm)
			tmp1 = stu[i];
		else if(stu[i].hh == tmp1.hh && stu[i].mm == tmp1.mm && stu[i].ss < tmp1.ss)
			tmp1 = stu[i];
		scanf("%d:%d:%d",&stu[i].hh,&stu[i].mm,&stu[i].ss);
		if(stu[i].hh > tmp2.hh)
			tmp2 = stu[i];
		else if(stu[i].hh == tmp2.hh && stu[i].mm > tmp2.mm)
			tmp2 = stu[i];
		else if(stu[i].hh == tmp2.hh && stu[i].mm == tmp2.mm && stu[i].ss > tmp2.ss)
			tmp2 = stu[i];
	}
	printf("%s %s",tmp1.sId,tmp2.sId);
	return 0;
}