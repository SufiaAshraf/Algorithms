#include <iostream>
#include <math.h>
#include <algorithm>
#include<queue>
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

node* buildTree(){
    int d;
    cin>>d;

    if(d==-1){
        return NULL;
    }
    node * root = new node(d);
    root->left = buildTree();
    root->right = buildTree();
    return root;
}
void printPRE(node *root){
    if(root==NULL){
        return;
    }
    //Otherwise, print root first followed by subtrees(children)
    cout<<root->data<<" ";
    printPRE(root->left);
    printPRE(root->right);
}

void printIN(node* root){
    if(root == NULL){
        return;
    }
    printIN(root->left);
    cout<<root->data<<" ";
    printIN(root->right);
}

void printPOST(node*root){
    if(root == NULL){
        return;
    }
    printPOST(root->left);
    printPOST(root->right);
    cout<<root->data<<" ";
}

int height(node* root){
    if(root == NULL){
        return 0;
    }
    int ls = height(root->left);
    int rs = height(root->right);
    return max(ls, rs)+1;
}

void printKthLevel(node*root, int k){
    if(root == NULL){
        return;
    }
    if(k == 1){
        cout<< root->data<<" ";
        return;
    }
    printKthLevel(root->left, k-1);
    printKthLevel(root->right, k-1);
    return;
}

int count(node* root){
    if(root == NULL){
        return 0;
    }
    return 1+count(root->left)+count(root->right);
}
void printAllLevels(node* root){
    int H = height(root);
    for(int i=0; i<=H; i++){
        printKthLevel(root, i);
        cout<<endl;
    }
    return ;
}

void bfs(node*root){
    queue <node*> q;
    q.push(root);
    q.push(NULL);
    while(!q.empty()){
        node* f = q.front();
        if(f == NULL){
            cout<<endl;
            q.pop();
            if(!q.empty()){
                q.push(NULL);
            }
        }else {
            cout<<f->data<<" ,";
            q.pop();
            if(f->left){
                q.push(f->left);
            }
            if(f->right){
                q.push(f->right);
            }
        }
    }
    return;
}

int sum(node*root){
    if(root == NULL){
        return 0;
    }
    return root->data+sum(root->left)+sum(root->right);
}

int diameter(node*root){
    if(root == NULL){
        return 0;
    }
    int h1 = height(root->left);
    int h2 = height(root->right);
    int op1 = h1+h2;
    int op2 = diameter(root->left);
    int op3 = diameter(root->right);
     
    return max(op1, max(op2, op3));
}

class Pair{
public:
    int height;
    int diameter;    
};

Pair fastDiameter(node*root){
    Pair p;
    if(root == NULL){
        p.height = p.diameter = 0;
        return p;
    }
    // Otherwise
    Pair left = fastDiameter(root->left);
    Pair right = fastDiameter(root->right);

    p.height = max(left.height, right.height)+1;
    p.diameter = max(left.height+right.height , max(left.diameter, right.diameter));
    return p;
}

int replaceSum(node*root){
    if(root == NULL){
        return 0;
    }
    if(root->left == NULL && root->right == NULL){
        return root->data;
    }

    // Recursive Part
    int leftSum = replaceSum(root->left);
    int rightSum = replaceSum(root->right);
    int temp;
    temp = root->data;
    root->data = leftSum+rightSum;
    return temp+root->data;
}

class HBPair{
public:
    int height;
    bool balance;
};

HBPair isHeightBalanced(node*root){
    HBPair p;
    if(root == NULL){
        p.height = 0;
        p.balance = true;
        return p;
    }
    HBPair left = isHeightBalanced(root->left);
    HBPair right = isHeightBalanced(root->right);

    p.height = max(left.height, right.height)+1;
    if(abs(left.height - right.height) && left.balance && right.balance){
        p.balance = true;
    }else {
        p.balance = false;
    }
    return p;
}

node* buildTreeFromArray(int* a, int s, int e){
    if(s>e){
        return NULL;
    }
    int mid = (s+e)/2;
    node* root = new node(a[mid]);
    root->left = buildTreeFromArray(a, s, mid-1);
    root->right = buildTreeFromArray(a, mid+1, e);
    return root;
}

node* createTreeFromTraversal(int* in, int* pre, int s, int e){
    static int i=0;
    if(s>e){
        return NULL;
    }
    // Rec Case
    node* root = new node(pre[i]);
    int index = -1;
    for(int j=s; j<=e; j++){
        if(in[j] == pre[i]){
            index = j;
            break;
        }
    }
    i++;
    root->left = createTreeFromTraversal(in, pre, s, index-1);
    root->right = createTreeFromTraversal(in , pre, index+1, e);
    return root;
}
int main(){ 
    // node* root = buildTree();
    // printIN(root);
    // cout<<endl;
    // printPRE(root);
    // cout<<endl;
    // printPOST(root);
    // cout<<endl;
    // cout<<height(root);
    // printAllLevels(root);
    // bfs(root);
    // cout<<endl;
    // replaceSum(root);
    // bfs(root);
    // cout<<count(root)<<endl;
    // cout<<sum(root)<<endl;
    // cout<< diameter(root);
    // Pair p = fastDiameter(root);
    // cout<< p.height<<endl;
    // cout<<p.diameter<<endl;
    // if(isHeightBalanced(root)){
    //     cout<<" Balanced "<<endl;
    // }else{
    //     cout<<"Not a Balanced tree"<<endl;
    // }
    // int n;
    // cin>>n;
    // int A[n];
    // for(int i=0; i<n; i++){
    //     cin>> A[i];
    // }
    // node*root = buildTreeFromArray(a,0,n-1);
    // bfs(root);
    // return 0;
    int pre[] = {1,2,3,4,8,5,6,7};
    int in[] = {3,2,8,4,1,6,7,5};
    int n = sizeof(in)/sizeof(int);
    node*root = createTreeFromTraversal(in, pre, 0, n-1);
    bfs(root);
}
