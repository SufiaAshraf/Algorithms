#include<iostream>
#include<bits/stdc++.h>
#include<queue>
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

node* buildTree(){
    queue <node*> q;
    node* root = NULL;
    node* temp = NULL;
    int data;
    cin>> data;
    if(data!=-1){
        root = new node(data);
    }
    q.push(root);
    while(!q.empty()){
        cin>> data;
        if(data!=-1){
            temp = new node(data);
            q.front()->left = temp;
            q.push(temp);
        }
        cin>> data;
        if(data!=-1){
            temp = new node(data);
            q.front()->right = temp;
            q.push(temp);
        }
        q.pop();
    }
    return root;
}

void leftViewHelper(node* root , int Level, int *Max_level){
    if(root == NULL){
        return;
    }
    if(*Max_level<Level){
        cout<<root->data<<" ";
        *Max_level = Level;
    }
    leftViewHelper(root->left, Level+1, Max_level);
    leftViewHelper(root->right, Level+1, Max_level);
}

void leftView(node* root){
    int Max_level = 0;
    leftViewHelper(root, 1, &Max_level);
}

int main(){
    node* root = buildTree();
    leftView(root);
}