#include<iostream>
#include<bits/stdc++.h>
#include<queue>
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
void topView(node* root){
    if(root== NULL){
        return;
    }
    queue<node*> q;
    map<int , int> m;
    int hd = 0;
    root->hd = hd;
    q.push(root);
    while(q.size()){
        hd = root->hd;
        if(m.count(hd) == 0){
            m[hd] = root->data;
        }
        if(root->left){
            root->left->hd = hd-1;
            q.push(root->left);
        }
        if(root->right){
            root->right->hd = hd+1;
            q.push(root->right);
        }
        q.pop();
        root= q.front();
    }
    for(auto i=m.begin(); i!=m.end(); i++){
        cout<<i->second<<" ";
    }
}

int main(){
    node* root = buildTree();
    bfs(root);
    cout<<endl;
    topView(root);
}