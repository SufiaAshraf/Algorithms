#include<iostream>
#include<stack>
using namespace std;

class node{
public:
    int data;
    node* left;
    node*right;
    node(int d){
        data = d;
        left = NULL;
        right = NULL;
    }
};

node* buildTree(string s){
    int data;
    if(s == "true"){
        cin>>data;
        node* root = new node(data);
        string l;
        cin>>l;
        root->left = buildTree(l);
        string r;
        cin>> r;
        if(r=="true"){
            root->right = buildTree(r);
        }
        return root;
    }
    return NULL;
}


void printZigZag(node* root){
   if(root == NULL){
       return;
   }
   stack<node*> currentLevel;
   stack<node*> nextLevel;

    // Push the root to currentLevel stack
    currentLevel.push(root);
    // check if stack is empty
    bool leftToRight = true;
    while(!currentLevel.empty()){
        node* temp = currentLevel.top();
        currentLevel.pop();
        if(temp){
            cout<<temp->data<<" ";
        }
        // Store data according to the current order
        if(leftToRight){
            if(temp->left){
                nextLevel.push(temp->left);
            }if(temp->right){
                nextLevel.push(temp->right);
            }
        }else{
            if(temp->right){
                nextLevel.push(temp->right);
            }
            if(temp->left){
                nextLevel.push(temp->left);
            }
        }
        if(currentLevel.empty()){
            leftToRight = !leftToRight;
            swap(currentLevel, nextLevel);
        }
    }
}


int main(){
    node* root = buildTree("true");
    printZigZag(root);
}