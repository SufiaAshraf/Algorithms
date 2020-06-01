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

class Solution{
    int globalMax = INT_MIN;
    int maxPathNodetoNode(node* root){
        // Base Case
        if(root == NULL){
            return 0;
        }
        // Recursive Work
        int ls = maxPathNodetoNode(root->left);
        int rs = maxPathNodetoNode(root->right);

        // Self Work
        int Case1 = root->data;
        int Case2 = ls + root->data;
        int Case3 = rs + root->data;
        int Case4 = ls+ rs+ root->data;
        globalMax = max(Case1, max(Case2 , max(Case3, max(Case4, globalMax))));
        return max(ls, max(rs, 0)) + root->data;
    }
};

int main(){

}