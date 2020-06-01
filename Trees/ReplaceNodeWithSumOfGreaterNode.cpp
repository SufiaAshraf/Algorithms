#include<iostream>
using namespace std;

class node{
public:
    int data;
    node* left;
    node* right;

    node(int d){
        data = d;
        right = NULL;
        left = NULL;
    }
};

node* buildTree(node* root, int* In, int s, int e){
    if(s>e){
        return NULL;
    }
    int mid = (s+e)/2;
    root = new node(In[mid]);

    root->left = buildTree(root->left, In, s, mid-1 );
    root->right = buildTree(root->right, In, mid+1, e);

    return root;
}

void helper(node* root, int* sum){
    if(root == NULL){
        return;
    }
    helper(root->right, sum);
    *sum = *sum + root->data;
    root->data = *sum;
    helper(root->left, sum);
}

void replaceWithSum(node* root){
    int sum = 0;
    helper(root, &sum);
}

void printPRE(node* root){
    if(root == NULL){
        return;
    }
    cout<<root->data<<" ";
    printPRE(root->left);
    printPRE(root->right);
}

int main(){
    int n;
    cin>> n;
    int In[n];
    for(int i=0; i<n; i++){
        cin>> In[i];
    }
    node* root = buildTree(root, In, 0, n-1);
    replaceWithSum(root);
    printPRE(root);
}