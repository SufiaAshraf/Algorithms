#include <iostream>
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

void insertAtTail(node*&head, int data){
    if(head == NULL){
        head = new node(data);
        return;
    }
    node* tail = head;
    while(tail->next != NULL){
        tail = tail->next;
    }
    tail->next = new node(data);
}

void print(node* head){
    while(head != NULL){
        cout<< head->data<<" ";
        head = head->next;
    }
    cout<< endl;
}


void buildList(node*&head){
    int data;
    while(data!= -1){
        insertAtTail(head, data;)
        cin>> data;
    }
}


int main(){
    node* head =  NULL;
    buildList(head);
    print(head);
}