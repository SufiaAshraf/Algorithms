#include<iostream>
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
    queue<node*>q;
    node* temp = NULL;
    node* root = NULL;
    int data;
    cin>> data;
    if(data!=-1){
        root= new node(data);
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

void rightViewHelper(node* root, int level, int* max_level){

        if(root == NULL){
            return;
        }
        if(level > *max_level){
            cout<< root->data<<" ";
            *max_level = level;
          
        }
    rightViewHelper(root->right, level+1, max_level);
    rightViewHelper(root->left, level+1, max_level);
}

void rightView(node* root){
    int max_level = 0;
    rightViewHelper(root, 1, &max_level);
}

int main(){
    node* root = buildTree();
    rightView(root);
}