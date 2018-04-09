#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <iostream>
#include <map>
#include <cmath>
using namespace std;

#define maxn 10005

struct Node{
	int val,height;
	Node *left,*right;
}*root;

int n;

Node* newNode(int val){
	Node *root = new Node;
	root->right = root->left = NULL;
	root->val = val;
	root->height = 1;
	return root;
}

int getHeight(Node *root){
	if(root == NULL)
		return 0;
	return root->height;
}

void updateHeight(Node *root){
	root->height = max(getHeight(root->left),getHeight(root->right))+1;
}

int getBalanceFactor(Node *root){
	return getHeight(root->left)-getHeight(root->right);
}

void L(Node *&root){
	Node *temp = root->right;
	root->right = temp->left;
	temp->left = root;
	updateHeight(root);
	updateHeight(temp);
	root = temp;
}

void R(Node *&root){
	Node *temp = root->left;
	root->left = temp->right;
	temp->right = root;
	updateHeight(root);
	updateHeight(temp);
	root = temp;
}

void insert(Node *&root,int val){
	if(root == NULL){
		root = newNode(val);
		return ;
	}	
	if(val < root->val){
		insert(root->left,val);
		updateHeight(root);
		if(getBalanceFactor(root) == 2){
			if(getBalanceFactor(root->left) == 1)
				R(root);
			else if(getBalanceFactor(root->left) == -1){
				L(root->left);
				R(root);
			}
		}
	}
	else{
		insert(root->right,val);
		updateHeight(root);
		if(getBalanceFactor(root) == -2){
			if(getBalanceFactor(root->right) == -1)
				L(root);
			else if(getBalanceFactor(root->right) == 1){
				R(root->right);
				L(root);
			}
		}
	}
}

Node* create(int num[]){
	Node *root=NULL;
	for(int i = 0;i<n;++i){
		insert(root,num[i]);
	}
	return root;
}

int main(int argc, char *argv[])
{
	int num;
	scanf("%d",&n);
	for(int i = 0;i<n;++i){
		scanf("%d",&num);
		insert(root,num);
	}
	printf("%d\n",root->val);
	return 0;
}