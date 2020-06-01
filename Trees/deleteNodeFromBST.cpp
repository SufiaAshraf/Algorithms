#include <iostream>
#include<queue>
#include<climits>
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

//Accepts the old root node & data and returns the new root node 
node* insertInBST(node *root,int data){
    //Base Case
    if(root==NULL){
        return new node(data);
    }
    //Rec Case - Insert in the Subtree and Update Pointers
    if(data<=root->data){
        root->left = insertInBST(root->left,data);
    }
    else{
        root->right = insertInBST(root->right,data);
    }
    return root;
}


node* build(int n){
    //Read a list of numbers till -1 and also these numbers will be inserted into BST
    
    node*root = NULL;
    int d;
    for(int i=0; i<n; i++){
        cin>>d;
        root = insertInBST(root,d);
        
    }
    return root;
}

node* deleteInBST(node*root,int data){
    if(root==NULL){
        return NULL;
    }
    else if(data<root->data){
        root->left = deleteInBST(root->left,data);
        return root; 
    }
    else if(data==root->data){
        //Found the node to delete 3 Cases
        //1. Node with 0 children - Leaf Node
        if(root->left==NULL && root->right==NULL){
            delete root;
            return NULL;
        }
        //2. Case Only 1 child
            if(root->left!=NULL && root->right==NULL){
                node* temp = root->left;
                delete root;
                return temp;
            }
            if(root->right!=NULL && root->left==NULL){
                node* temp = root->right;
                delete root;
                return temp;
            }
        //3. Case 2 children
            node *replace = root->right;
            //Find the inorder successor from right subtree
            while(replace->left!=NULL){
                replace = replace->left;
            }
            root->data = replace->data;
            root->right = deleteInBST(root->right,replace->data);
            return root;
    }
    else{
        root->right = deleteInBST(root->right,data);
        return root;
    }
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
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        node* root = build(n);
        int m;
        cin>>m;
        int A[1001];
        for(int i=0; i<m; i++){
            cin>> A[i];  
        }
		for(int j=0; j<m; j++){
			root = deleteInBST(root, A[j]);
		}
        printPRE(root);
		cout<<endl;
    }
return 0;
}
