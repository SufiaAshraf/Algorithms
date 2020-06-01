#include<iostream>
#include<bits/stdc++.h>
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

node* createTreeFromTraversal(int* In, int* PRE, int s, int e){
    static int i=0;
    if(s>e){
        return NULL;
    }
    node* root = new node(PRE[i]);
    int index = -1;
    for(int j=s; j<=e; j++){
        if(In[j] == PRE[i]){
            index = j;
            break;
        }
    }
    i++;
    root->left = createTreeFromTraversal(In, PRE, s, index-1);
    root->right = createTreeFromTraversal(In, PRE, index+1, e);
    return root;
}

class Info{
public:
    int size;
    int max;
    int min;
    int ans;
    bool isBST;
};

Info largestBST(node* root){
    if(root==NULL){
        return {0, INT_MIN, INT_MAX, 0, true};
    }
    if(root->left == NULL && root->right == NULL){
        return {1, root->data, root->data, 1, true};
    }

    Info l = largestBST(root->left);
    Info r = largestBST(root->right);

    Info p;
    p.size = (1+l.size+r.size);
    if(l.isBST && r.isBST && l.max<root->data && r.min>root->data){
        p.min = min(l.min , min(r.min, root->data));
        p.max = max(r.max , max(l.max, root->data));

        p.ans = p.size;
        p.isBST = true;
        return p;
    }
    p.ans = max(l.ans, r.ans);
    p.isBST = false;

    return p;
}

int main(){
    int n;
    cin>> n;
    int In[n], PRE[n];
    for(int i=0; i<n; i++){
        cin>> PRE[i];
    }
     for(int i=0; i<n; i++){
        cin>> In[i];
    }
    node* root = createTreeFromTraversal(In, PRE, 0, n-1);
    cout<<largestBST(root).ans;
}