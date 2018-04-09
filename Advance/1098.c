#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <iostream>
#include <map>
#include <cmath>
using namespace std;

#define maxn 105

int origin[maxn],changed[maxn],temp[maxn];
int n;

bool isSame(int num1[],int num2[]){
	for(int i = 1;i<=n;++i){
		if(num1[i] != num2[i])
			return false;
	}
	return true;
}

void showAns(int num[]){
	for(int i = 1;i<=n;++i){
		printf("%d",num[i]);
		if(i<n)
			printf(" ");
	}
	printf("\n");
}

bool insertSort(){
	bool flag = false;
	for(int i = 2;i<=n;++i){
		if(i != 2 && isSame(temp,changed))
			flag = true;
		sort(temp,temp+i+1);
		if(flag)
			return true;
	}
	return false;
}

void adjustDown(int low,int high){
	int i = low,j = i*2;
	while(j<=high){
		if(j+1 <= high && temp[j] < temp[j+1])
			j = j+1;
		if(temp[i] < temp[j]){
			swap(temp[i],temp[j]);
			i = j;
			j = j*2;
		}
		else break;
	}
}

void heapSort(){
	bool flag = false;
	for(int i = n/2;i>=1;--i){
		adjustDown(i,n);
	}
	for(int i = n;i>1;--i){
		if(isSame(temp,changed) && i!=n)
			flag = true;
		swap(temp[i],temp[1]);
		adjustDown(1,i-1);
		if(flag){
			showAns(temp);
			return ;
		}
	}
}

int main(int argc, char *argv[])
{
	scanf("%d",&n);
	for(int i = 1;i<=n;++i){
		scanf("%d",&origin[i]);
		temp[i] = origin[i];
	}
	for(int i = 1;i<=n;++i)
		scanf("%d",&changed[i]);
	if(insertSort()){
		printf("Insertion Sort\n");
		showAns(temp);
	}
	else{
		printf("Heap Sort\n");
		for(int i = 1;i<=n;++i)
			temp[i] = origin[i];
		heapSort();
	} 
	return 0;
}