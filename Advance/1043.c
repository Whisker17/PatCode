#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <iostream>
#include <map>
#include <cmath>
using namespace std;

struct Node{
	int val;
	Node *left,*right;
};

void insert(Node *&root,int val){
	if(root == NULL){
		root = new Node;
		root->val = val;
		root->left = root->right = NULL;
		return ;
	}
	if(val < root->val)
		insert(root->left,val);
	else 
		insert(root->right,val);
}

void preOrder(Node *root,vector<int> &vi){
	if(root == NULL)
		return ;
	vi.push_back(root->val);
	preOrder(root->left,vi);
	preOrder(root->right,vi);
}

void preOrderMirror(Node *root,vector<int> &vi){
	if(root == NULL)
		return ;
	vi.push_back(root->val);
	preOrderMirror(root->right,vi);
	preOrderMirror(root->left,vi);
}

void postOrder(Node *root,vector<int> &vi){
	if(root == NULL)
		return ;
	postOrder(root->left,vi);
	postOrder(root->right,vi);
	vi.push_back(root->val);
}

void postOrderMirror(Node *root,vector<int> &vi){
	if(root == NULL)
		return ;
	postOrderMirror(root->right,vi);
	postOrderMirror(root->left,vi);
	vi.push_back(root->val);
}

vector<int> origin,pre,preM,post,postM;

int main(int argc, char *argv[])
{
	int n,val;
	Node *root=NULL;
	scanf("%d",&n);
	for(int i = 0;i<n;++i){
		scanf("%d",&val);
		origin.push_back(val);
		insert(root,val);
	}
	preOrder(root,pre);
	preOrderMirror(root,preM);
	postOrder(root,post);
	postOrderMirror(root,postM);
	if(origin == pre){
		printf("YES\n");
		for(int i = 0;i<post.size();++i){
			printf("%d",post[i]);
			if(i < post.size()-1)
				printf(" ");
		}
	}
	else if(origin == preM){
		printf("YES\n");
		for(int i = 0;i<postM.size();++i){
			printf("%d",postM[i]);
			if(i < postM.size()-1)
				printf(" ");
		}
	}
	else{
		printf("NO\n");
	}
	return 0;
}