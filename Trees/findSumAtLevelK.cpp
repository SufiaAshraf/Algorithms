#include<iostream>
using namespace std;

class node{
public:
    int data;
    node*left;
    node*right;

    node(int d){
        data = d;
        left = NULL;
        right = NULL;
    }
};

node* build(){
    int data, num;
    cin>> data;
    node* root = new node(data);
    cin>>num;
    if(num== 2){
        root->left = build();
        root->right = build();
    }else if(num==1){
        root->left= build();
    }
    return root;
}
int sum =0;
void sumAtLevelK(node* root, int k){
    if(root==NULL){
        return;
    }
    if(k==0){
        sum+=root->data;
    }
    if(k<1){
        return;
    }
     sumAtLevelK(root->left , k-1);
    sumAtLevelK(root->right, k-1);
}

int main(){
    node* root = build();
    int k;
    cin>>k;
    sumAtLevelK(root, k);
    cout<<sum<<endl;
}