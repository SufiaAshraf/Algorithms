#include<iostream>

using namespace std;
class node{
public:
    int data;
    node* next;

    //  Constructor
    node(int d) {
        data = d;
        next = NULL;
    }
};
void insertAtHead(node* &head, int data){
    node*n = new node(data);
    n->next = head;
    head = n;
}

int length(node*head){
    int len =0;
    while(head!=NULL){
        head = head->next;
        len+=1;
    }
    return len;
}

void insertAtTail(node* &head, int data){
    if(head == NULL){
        head = new node(data);
        return;
    }
    node*tail = head;
    while(tail->next != NULL){
       tail = tail->next;
    }
     tail->next = new node(data);
}

void insertInMiddle(node*&head, int p, int data){
    if(head == NULL || p==0){
        insertAtHead(head,data);
    }else if(p>length(head)){
        insertAtTail(head, data);
    }
    int jump=1;
    node*temp = head;
    while(jump<=p-1){
        temp = temp->next;
        jump+=1;
    }
    node*n = new node(data);
    n->next = temp->next;
    temp->next = n;
}
bool searchRecursive(node*head, int key){
    // Base Case
    if(head == NULL){
        return false;
    }
    // Recursive Case
    if(head->data == key){
        return true;
    }else {
        return searchRecursive(head->next, key);
    }
}

bool searchIterative(node*head, int key){
    while(head!=NULL){
        if(head->data == key){
            return true;
        }else {
            head = head->next;
        }
    }
    return false;
}

void print(node*head){
    while(head!=NULL){
        cout<<head->data<<"->";
        head = head->next;
    }
    cout<<endl;
}

void deleteAtHead(node*&head){
    if(head == NULL){
        return;
    }
    node*temp = head;
    head = head->next;
    delete temp;
    return;
}

void deleteAtTail(node*&head){
    node*prev = NULL;
    node*temp = head;
    while(temp->next!=NULL){
        prev = temp;
        temp = temp->next;
    }
    delete temp;
    prev->next = NULL;
}

void buildList(node*&head){
    int data;
    cin>>data;
    while(data!=-1){
        insertAtTail(head, data);
        cin>>data;
    }
}

istream& operator>>(istream &is, node*&head){
    buildList(head);
    return is;
}

ostream& operator<<(ostream &os, node*&head){
    print(head);
    return os;
}

void reverse(node*&head){
    node*C = head;
    node*p = NULL;
    node*N;
    while(C!=NULL){
        N=C->next;
        C->next = P;
        P = C;
        C=N;
    }
    head = P;
}

int main(){
    node*head = NULL;
    node*head2 = NULL:
    cin>>head>>head2;
    cout<<head<<endl<<head2;
    reverse(head);
    cout<<head<<endl;
   return 0; 
}