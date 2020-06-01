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

void insertAtTail(node* &head, int data){
    if(head == NULL){
        head = new node(data);
        return;
    }
    node* tail= head;
    while(tail->next != NULL){
        tail = tail->next;
    }
    tail->next = new node(data);
    return;
}

int getIntersectionNode(int d, node*head1, node*head2){
    node* current1 = head1;
    node* current2 = head2;

    while(d--){ 
        current1 = current1->next;
    }
    while(current1 != NULL && current2 != NULL){
        if(current1->data == current2->data){
            return current1->data;
        }
            current1 = current1->next;
            current2 = current2->next;
        
    }
    return -1;
}

int main(){
    int N1;
    cin>> N1;
    node*head1 = NULL;
    for(int i=0; i<N1; i++){
        int data;
        cin>> data;
        insertAtTail(head1, data);
    }
    int N2;
    cin>> N2;
    node* head2 = NULL;
    for(int j= 0;j<N2; j++){
        int data;
        cin>> data;
        insertAtTail(head2, data);
    }
    int d;
    if(N1>N2){
        d = n1-N2;
        cout<< getIntersection(d, head1, head2);
    }else{
        d = N2-N1;
        cout<< getIntersectionNode(d, head2, head1);
    }
   return 0; 
}