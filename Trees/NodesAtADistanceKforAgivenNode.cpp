#include<iostream>
#include<bits/stdc++.h>
#include<vector>
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

vector<int> v;

node* createTreeFromTraversal(int* In,int* Pre,int s, int e){
    static int i=0;
    if(s>e){
        return NULL;
    }
    node* root = new node(Pre[i]);
    int index = -1;
    for(int j=s; j<=e; j++){
        if(In[j] == Pre[i]){
            index = j;
            break;
        }
    }
    i++;
    root->left = createTreeFromTraversal(In, Pre, s, index-1);
    root->right = createTreeFromTraversal(In, Pre, index+1, e);
    return root;

}

void printNodeAtkDistance(node* root, int k) {
    if(root==0 || k<0){
        return;
    }
    if(k==0){
        v.push_back(root->data);
        return;
    }
    printNodeAtkDistance(root->left, k-1);
    printNodeAtkDistance(root->right, k-1);
}
vector<int> v;
int nodesAtADistK(node* root, int k, int target){
    if(root == NULL){
        return -1;
    }
    if(root->data == target){
        printNodeAtkDistance(root, k);
        return 0;
    }
    int dl = nodesAtADistK(root->left,k, target);
    if(dl != -1){
        if(dl+1 == k)
           v.push_back(root->data);
        else
            printNodeAtkDistance(root->right, k-dl-2);   
        return 1+dl;
    }
    int R = nodesAtADistK(root->right,k, target);
    if(R != -1){
            if(R+1==k)
               v.push_back(root->data);
            else
                printNodeAtkDistance(root->left, k-R-2);
            return 1+R;
        }
    return -1;
}

int main(){
    int n;
    cin>>n;
    int In[n], Pre[n];
    for(int i=0; i<n; i++){
        cin>> Pre[i];
    }
    for(int i=0; i<n; i++){
        cin>> In[i];
    }
    node* root= createTreeFromTraversal(In, Pre, 0, n-1);
    int t;
    cin>>t;
    while(t--){
        int target;
        cin>>target;
        int k;
        cin>> k;
        nodesAtADistK(root, k, target);
        sort(v.begin(), v.end());
        for(auto x:v){
            cout<<x<<" ";
        }
        cout<<endl;
    }
}