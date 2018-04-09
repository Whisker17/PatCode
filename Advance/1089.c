#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <iostream>
#include <map>
#include <cmath>
using namespace std;

#define maxn 1000005

int n;
int temp[maxn],num[maxn],changed[maxn];

bool isSame(int num1[],int num2[]){
	for(int i = 0;i<n;++i){
		if(num1[i] != num2[i])
			return false;
	}
	return true;
}

void showArray(int num[]){
	for(int i = 0;i<n;++i){
		printf("%d",num[i]);
		if(i != n-1)
			printf(" ");
	}
}

bool insertSort(int temp[]){
	bool flag = false;
	for(int i = 1;i<n;++i){
		for(int j = i;j<n;++j){
			if(i != 1 && isSame(changed,temp))
				flag = true;
		}
		int tmp = temp[i],j = i;
		while(j > 0 && temp[j-1] > tmp){
			temp[j] = temp[j-1];
			--j;
		}
		temp[j] = tmp;
		if(flag){
			return true;
		}
	}
	return false;
}

void mergeSort(int num[]){
	bool flag = false;
	for(int step = 2;step/2 <= n;step*=2){
		if(step != 2 && isSame(num,changed))
			flag = true;
		for(int i = 0;i<n;i += step){
			sort(num+i,num+min(i+step,n));
		}
		if(flag){
			showArray(num);
			return ;
		}
	}
}

int main(int argc, char *argv[])
{
	scanf("%d",&n);
	for(int i = 0;i<n;++i){
		scanf("%d",&num[i]);
		temp[i] = num[i];
	}
	for(int i = 0;i<n;++i){
		scanf("%d",&changed[i]);
	}
	if(insertSort(temp)){
		printf("Insertion Sort\n");
		showArray(temp);
	}
	else{
		printf("Merge Sort\n");
		mergeSort(num);
	}
	return 0;
}