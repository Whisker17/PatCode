#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int n,i,j,max=0;
    double p,a[100010];
    scanf("%d %lf",&n,&p);
    for(i=0;i<n;i++)
        scanf("%lf",&a[i]);
    sort(a,a+n);
    for(i=0;i<n;i++)
        for(j=i+max-1;j<n;j++)
        {
            if(a[i]*p<a[j])
                break;
            if(j-i+1>max)
                max =j-i+1;
        }
    printf("%d\n",max);
    system("pause");
    return 0;
}