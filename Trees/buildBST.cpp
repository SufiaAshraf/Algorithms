#include<iostream>
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

// node* insertInBST(node* root, int data){
//     if(root== NULL){
//         return new node(data);
//     }
//     if(data<=root->data){
//         root->left =  insertInBST(root->left, data);
//     }else{
//         root->right =  insertInBST(root->right, data);
//     }
//     return root;
// }

node* buildBST( int* A, int s, int e){
     if(s>e){
        return NULL;
    }
    int mid = (s+e)/2;
    node* root = new node(A[mid]);
    root->left = buildBST( A, s, mid-1);
    root->right = buildBST( A, mid+1, e);
    return root;
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
        int A[n];
        for(int i=0; i<n; i++){
            cin>> A[i];
        }
        node* root = buildBST( A, 0, n-1);
		printPRE(root);
    }
}