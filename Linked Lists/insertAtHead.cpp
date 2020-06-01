#include<iostream>
using namespace std;

class node{
public:
    int data;
    node* next;

    // Constructor
    node(int d){
        data = d;
        next = NULL;
    }
};
/*
class LinkedList{
    node*head;
    node*tail;
public:
    LinkedList(){
        head = NULL;
        tail = NULL;
    }    
    void InsertAtHead(){

    }
}

*/
// passing a pointer variable by reference
void insertAtHead(node*&head , int data){
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

void insertAtTail(node*&head, int data){
    if(head == NULL){
        head = new node(data);
        return;
    }
    node*tail = head;
    while(tail->next != NULL){
        tail = tail->next;
    }
    tail->next = new node(data);
    return;
}

void insertInMiddle(node*&head, int data, int p){
    if(head==NULL || p==0){
        insertAtHead(head, data);
    }
    else if(p>length(head)){
        insertAtTail(head, data);
    }
    else{
        // Insert in middle
        // take p-1 jumps
        int jump = 1;
        node*temp  = head;
        while(jump<=p-1){
            temp = temp->next;
            jump+=1;
            }
        node*n = new node(data);
        n->next = temp->next;
        temp->next = n;
    }
   
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
    // node*temp = head;
    while(head!=NULL){
        cout<<head->data<<"-->";
        head = head->next;
    }
    cout<<endl;
}

void deleteAtHead(node*&head){
    if(head==NULL){
        return;
    }
    node*temp = head;
    head = head->next;
    delete temp;
    return;
}

void deleteAtTAil(){
    node* prev = NULL;
    node* temp = head;
    while(temp->next != NULL){
        prev = temp;
        temp = temp->next;
    }
    delete temp;
   prev->next = NULL;
   return;
}

void buildList(node*&head){
    int data;
    cin>>data;
    while(data!=-1){
        insertAtTail(head, data);
        cin>>data;
    }
}

void reverse(node*head){
    node*C = head;
    node*P = NULL;
    node*N;

    while(C!=NULL){
        // Save the next node
        N = C->next;
        // Make the current node point to prevous P
        C->next = P;
        // Just update prec=vious and current
        P = C;
        C= N;
    }
}

int main(){
    node*head = NULL;
    buildList(head);
    print(head);
   return 0; 
}