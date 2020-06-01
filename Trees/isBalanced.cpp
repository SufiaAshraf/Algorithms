#include <iostream>
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

node* build(string s){
    if(s=="true"){
        int d;
        cin>> d;
        node* root = new node(d);
        string l;
        cin>>l;
        root->left = build(l);
        string r;
        cin>>r;
        if(r=="true"){
            root->right =  build(r);
        }
        return root;
    }
    return NULL;
}

class HBPair{
public:
    int height;
    bool balance;
};

HBPair isHeightBalanced(node* root){
    HBPair p;
    if(root == NULL){
        p.height = 0;
        p.balance = true;
        return p;
    }
    HBPair left = isHeightBalanced(root->left);
    HBPair right = isHeightBalanced(root->right);
    p.height = max(left.height , right.height)+1;
    if(abs(left.height - right.height)<=1 && left.balance && right.balance){
        p.balance = true;
    }else{
        p.balance = false;
    }
    return p;
}

int main() {
    node* root = build("true");
	HBPair p = isHeightBalanced(root);
    if(p.balance){
        cout<<"true"<<endl;
    }
    else{
        cout<<"false"<<endl;
    }
}
