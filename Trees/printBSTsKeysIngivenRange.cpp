#include<iostream>
#include<algorithm>
using namespace std;

class node{
public:
    int data;
    node*left;
    node*right;
    node(int d){
        data = d;
        left = NULL;
        right = NULL;
    }
};

void printPRE(node* root){
    if(root== NULL){
        return;
    }
    cout<<root->data<<" ";
    printPRE(root->left);
    printPRE(root->right);
}


void NODES(node* root, int K1, int K2){
    if(root==NULL){
        return;
    }
	NODES(root->left, K1, K2);
    if(root->data <=K2 && root->data>=K1){
        cout<<root->data<<" ";
    }
    NODES(root->right, K1, K2);
    return;
}

node* insert(node* root, int d){
    if(root == NULL){
        return new node(d);
    }
    if(d<=root->data){
        root->left = insert(root->left, d);
    }else{
        root->right = insert(root->right, d);
    }
    return root;
}

node* build(int* A, node* root, int n){
    for(int i=1; i<n; i++){
        root = insert(root, A[i]);
    }
    return root;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>> n;
        int d;
        cin>>d;
        int A[n];
        for(int i=1; i<n; i++){
            cin>> A[i];
        }
        node*root = new node(d);
        root = build(A, root, n);
        cout<<"# "<<"Preorder "<<": ";
        printPRE(root);
        int K1, K2;
        cin>>K1>>K2;
		cout<<endl;
        cout<<"# "<<"Nodes within range are "<<": ";
        NODES(root, K1, K2);
    }
}