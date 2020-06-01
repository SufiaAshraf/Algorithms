#include<iostream>
using namespace std;

class node{
public:
    int data;
    node* left;
    node* right;

    node(int d){
        data= d;
        left = NULL;
        right = NULL;
    }
};

node* BuildTreeUsingPRE(){
    int d;
    cin>>d;
    if(d == -1){
        return NULL;
    }
   node* root = new node(d);
    root->left = BuildTreeUsingPRE();
    root->right = BuildTreeUsingPRE();
    return root;
}