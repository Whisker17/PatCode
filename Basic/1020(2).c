#include<stdio.h>
#include<algorithm>
using namespace std;
struct yb{
	double l,t;
	double p;	
}num[1000];
        
bool cmp(yb a,yb b){
     return a.p>b.p;
     }
int main(){
    int n,m;
    double temp;
    scanf("%d%d",&n,&m);
    
    for(int i=0;i<n;i++)
     	scanf("%lf",&num[i].l);
    for(int i=0;i<n;i++)
    	scanf("%lf",&num[i].t);
    for(int i=0;i<n;i++)
      num[i].p=num[i].t / num[i].l; 
    sort(num,num+n,cmp);
    temp = 0;
    for(int i = 0;i<n;i++){
		if(m > num[i].l){
			temp += num[i].t;
			m -= num[i].l;
		}
		else{
			temp += m * num[i].p;
			break;
		}
	}
	printf("%.2lf\n",temp);
    return 0;
    }
