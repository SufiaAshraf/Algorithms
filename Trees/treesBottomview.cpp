#include<iostream>
#include<queue>
#include <bits/stdc++.h>
using namespace std;

class node{
public:
    int data;
    int hd;
    node* left;
    node* right;
    node(int d){
        data = d;
        hd = INT_MAX;
        left = NULL;
        right = NULL;
    }
};

void bottomView(node* root){
    if(root == NULL){
        return;
    }
    // Initialize a variable 'hd' with 0 for the root element
    int hd = 0;
    // Tree map which stores key value pair with hd 
    map<int , int> m;
    // Queue for level order traversal of tree
    queue <node*> q;
    // Assign initialized hd value to root node and add root to queue
    root->hd = hd;
    q.push(root);
    // Loop until queue is empty
    while(!q.empty()){
        node* temp = q.front();
        q.pop();
        hd=temp->hd;
        m[hd] = temp->data;
        if(temp->left!=NULL){
            temp->left->hd = hd-1;
            q.push(temp->left);
        }
        if(temp->right!=NULL){
            temp->right->hd = hd+1;
            q.push(temp->right);
        }
    }

    for(auto i=m.begin(); i!= m.end(); i++){
        cout<<i->second<<" ";
    }
}

// node* buildTree(){
//     int d;
//     cin>>d;

//     if(d==-1){
//         return NULL;
//     }
//     node * root = new node(d);
//     root->left = buildTree();
//     root->right = buildTree();
//     return root;
// }
void printPRE(node* root){
    if(root== NULL){
        return;
    }
    cout<<root->data<<" ";
    printPRE(root->left);
    printPRE(root->right);
}
node* buildTree(){
    queue <node*> q;
    int data;
    node* root = NULL;
    cin>>data;
    node* temp = NULL;
    if(data != -1){
        root = new node(data);
    }
    q.push(root);
    while(!q.empty()){
        cin>>data;
        if(data != -1){
            temp = new node(data);
            q.front()->left = temp;
            q.push(temp);
        }
        cin>>data;
        if(data!=-1){
            temp = new node(data);
            q.front()->right = temp;
            q.push(temp);
        }
        q.pop();
    }
    return root;
}


int main(){
    node* root = buildTree();
    bottomView(root);
    // cout<<endl;
    // printPRE(root);
}