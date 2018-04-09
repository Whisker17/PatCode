#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <iostream>
#include <map>
#include <queue>
#include <cmath>
using namespace std;

struct Node{
	int val;
	Node *left,*right;
};

int n;
int post[50],in[50];

Node* create(int postL,int postR,int inL,int inR){
	if(postL > postR)
		return NULL;
	Node *root = new Node;
	root->left = root->right = NULL;
	root->val = post[postR];
	int k = 0;
	for(k = inL;k<=inR;++k){
		if(in[k] == post[postR])
			break;
	}
	int numL = k-inL;
	root->left = create(postL,postL+numL-1,inL,k-1);
	root->right = create(postL+numL,postR-1,k+1,inR);
	return root;
}

int num=0;
void bfs(Node *root){
	queue<Node*> q;
	q.push(root);
	while(!q.empty()){
		Node *now = q.front();
		q.pop();
		printf("%d",now->val);
		++num;
		if(num < n)
			printf(" ");
		if(now->left != NULL)
			q.push(now->left);
		if(now->right != NULL)
			q.push(now->right);
	}
}

int main(int argc, char *argv[])
{
	scanf("%d",&n);
	for(int i = 0;i<n;++i)
		scanf("%d",&post[i]);
	for(int i = 0;i<n;++i)
		scanf("%d",&in[i]);
	Node *root = create(0,n-1,0,n-1);
	bfs(root);
	return 0;
}