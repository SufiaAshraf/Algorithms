#include<iostream>
using namespace std;

class node{
public: 
    int data;
    node*next;
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
    return;
}

void buildlist(node*&head){
    int data;
    while(data != -1){
        insertAtTail(head, data);
        cin>> data;
    }
}

int length (node* head){
    int len = 0;
    while(head!= NULL){
        head = head->next;
        len+=1;
    }
    return len;
}
void kthelement(node*&head, int k){
    node* temp = head;
    int n = length(head);
    if(n<k){
        return;
    }
    for(int i=1; i< n-k+1; i++){
        temp = temp->next;
    }
    cout<< temp->data;
    return;
}

int main(){
    node* head = NULL;
    buildlist(head);
    int k;
    cin>> k;
    kthelement(head, k);

}