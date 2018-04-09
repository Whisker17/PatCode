#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <iostream>
#include <map>
#include <set>
#include <cmath>
using namespace std;

#define maxn 100005

int book[maxn];

struct Node{
	int val,cnt;
	Node(int a,int b):val(a),cnt(b){
		
	}
	bool operator < (const Node &a) const {
		if(cnt != a.cnt)
			return  cnt > a.cnt;
		else return val < a.val;
	}
};

int main(int argc, char *argv[])
{
	int n,k,num;
	set<Node> s;
	scanf("%d %d",&n,&k);
	for(int i = 0;i<n;++i){
		scanf("%d",&num);
		if(i != 0){
			printf("%d:",num);
			int tempCnt=0;
			set<Node>::iterator iter;
			for(iter = s.begin();iter != s.end() && tempCnt	< k;++iter){
				printf(" %d",iter->val);
				++tempCnt;
			}
			printf("\n");
		}
		set<Node>::iterator it;
		it = s.find(Node(num,book[num]));
		if(it != s.end())
			s.erase(it);
		++book[num];
		s.insert(Node(num,book[num]));
	}
	return 0;
}