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

class Custom{
public:    
    bool hasKeyP;
    bool hasKeyQ;
    node* Node;
};

Custom* helper(node* root, node* p, node* q){
    // Base Case
    if(root == NULL){
        return NULL;
    }
    Custom* leftans = helper(root->left, p, q);
    if(leftans != NULL && leftans->Node != NULL){
        return leftans;
    }
    Custom* rightans = helper(root->right, p, q);
    if(rightans != NULL && rightans->Node != NULL){
        return rightans;
    }
    Custom* result = new Custom();
    if(leftans != NULL && rightans != NULL){
        result->Node = root;
        result->hasKeyP = true;
        result->hasKeyQ = true;
        return result;
    }
    else if(root->data == p->data){
        result->hasKeyP = true;
        result->hasKeyQ = (leftans)?leftans->hasKeyQ:false or (rightans)?rightans->hasKeyQ:false; 
        if(result->hasKeyQ && result->hasKeyP){
             result->Node = root;
        }
            return result;
    }
    else if(root->data == q->data){
        result->hasKeyQ = true;
        result->hasKeyP = (leftans)?leftans->hasKeyP:false or (rightans)?rightans->hasKeyP:false; 
        if(result->hasKeyQ && result->hasKeyP){
              result->Node = root;
        }
            return result;
    }
    else if(leftans){
        return leftans;
    }
    else if(rightans){
        return rightans;
    }
    return NULL;
}

node* LCA(node* root, node* p, node* q){
    Custom* result = helper(root, p, q);
    if(result == NULL){
        return NULL;
    }
    else{
        return result->Node;
    }
}


node* buildTree(){
    int d;
    cin>>d;

    if(d==-1){
        return NULL;
    }
    node * root = new node(d);
    root->left = buildTree();
    root->right = buildTree();
    return root;
}

int main(){
    node* root = buildTree();
    int data;
    cin>> data;
    node* p = new node(data);
    int data2;
    cin>> data2;
    node* q = new node(data2);
    node* result = LCA(root, p, q);
    cout<< result->data;
}

