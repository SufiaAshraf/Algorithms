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


class Solution{
    node* prev;
    node* head;

    void BT2LL(node* root){
        if(root == NULL){
            return ;
        }
        BT2LL(root->left);
        if(prev == NULL){
            head = root;
        }else{
            root->left = prev;
            prev->right = root;
        }
        prev = root;
        BT2LL(root->right);
    }
}