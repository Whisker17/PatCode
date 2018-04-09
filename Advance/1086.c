#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <iostream>
#include <map>
#include <stack>
#include <cmath>
using namespace std;

struct Node{
	int val;
	Node *left,*right;
};

int n;
int pre[50],in[50];

Node* create(int preL,int preR,int inL,int inR){
	if(preL > preR)
		return NULL;
	Node *root = new Node;
	root->val = pre[preL];
	int k;
	for(k = inL;k<=inR;++k){
		if(in[k] == pre[preL])
			break;
	}
	int numL = k-inL;
	root->left = create(preL+1,preL+numL,inL,k-1);
	root->right = create(preL+numL+1,preR,k+1,inR);
	return root;
}

int num=0;
void postOrder(Node *root){
	if(root->left != NULL)
		postOrder(root->left);
	if(root->right != NULL)
		postOrder(root->right);
	++num;
	printf("%d",root->val);
	if(num < n)
		printf(" ");
}

int main(int argc, char *argv[])
{
	char str[5];
	int v;
	int cntPre = 0,cntIn=0;
	stack<int> st;
	scanf("%d",&n);
	for(int i = 0;i<2*n;++i){
		scanf("%s",str);
		if(strcmp(str,"Push") == 0){
			scanf("%d",&v);
			pre[cntPre++] = v;
			st.push(v);
		}
		else{
			in[cntIn++] = st.top();
			st.pop();
		}
	}
	Node *root = create(0,n-1,0,n-1);
	postOrder(root);
	return 0;
}