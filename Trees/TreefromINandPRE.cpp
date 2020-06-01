#include<iostream>
using namespace std;

class node{
public:
    int data;
    node* left;
    node* right;

    node(int d){
        data = d;
        left = NULL;
        right = NULL;
    }
};

node* createTreeFromTraversal(int* IN, int* PRE, int s, int e){
    static int i=0;
    if(s>e){
        return NULL;
    }
    node* root = new node(PRE[i]);
    int index = -1;
    for(int j=s; j<=e; j++){
        if(IN[j] == PRE[i]){
            index = j;
            break;
        }
    }
    i++;
    root->left = createTreeFromTraversal(IN, PRE, s, index-1);
    root->right = createTreeFromTraversal(IN, PRE, index+1, e);
    return root;
}
void print(node* root){
    if(root==NULL){
        return;
    }
    if(root->left!=NULL&&root->right!=NULL){
        cout<< root->left->data << " => "  <<root->data <<" <= " <<root->right->data<<endl;
    }
    else if(root->left==NULL&&root->right!=NULL){
        cout<<"END => "<<root->data << "<="<<root->right->data<<endl;
    }
    else if(root->left!=NULL&&root->right==NULL){
        cout<<root->left->data <<" => "<< root->data<< " <= END"<<endl;
    }
    else{
        cout<<"END => " <<root->data<< " <= END" <<endl;  
    }
    print(root->left);
    print(root->right);
}



int main(){
    int n;
    cin>> n;
    int PRE[n];
    for(int i=0; i<n; i++){
        cin>> PRE[i];
    }
    int m;
    cin>> m;
    int IN[m];
    for(int i=0;i<m; i++){
        cin>> IN[i];
    }
    node* root = createTreeFromTraversal(IN, PRE , 0, n-1);
    print(root);
}