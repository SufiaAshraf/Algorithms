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
    return;
}

void print(node*head){
    while(head!=NULL){
        cout<<head->data<<" ";
        head = head->next;
    }
    cout<<endl;
}

void segregateEvenOdd(node*&head){
    node* end = head;
    node* curr = head;
    node* prev = NULL;

    while(end->next!= NULL){
        end = end->next;
    }
    node* new_end = end;

    while(curr->data % 2 == 0 && curr != end){
        new_end->next = curr;
        curr = curr->next;
        new_end->next->next =NULL;
        new_end = new_end->next;
    }
    if(curr->data%2 != 0){
        head = curr;
        while(curr != end){
            if((curr->data)%2 != 0){
                prev = curr;
                curr = curr->next;
            }
            else {
                prev->next = curr->next;
                curr->next = NULL;
                new_end->next = curr;
                new_end = curr;
                curr = prev->next;
            }
        }
    }
    else {
        prev = curr;
    }
    if(new_end != end && (end->data)% 2 == 0){
            prev->next = end->next;
            end->next = NULL;
            new_end->next = end;
        }
    return;
}

int main(){

    int n;
    cin>> n;
    node* head = NULL;
    for(int i=0; i<n; i++){
        int data;
        cin>> data;
        insertAtTail(head, data);
    } 
    segregateEvenOdd(head);
    print(head);
}