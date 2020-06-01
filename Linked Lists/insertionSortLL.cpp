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

void insertAtTail(node*&head,int data){
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

void insertionSort(node*&head){
    node* Ins = head;
    node* current = head;
    current = current->next;
    
    while(current!=NULL){
        Ins = head;
        while(Ins != current){
            if(Ins->data> current->data){
                int temp = current->data;
                current->data = Ins->data ;
                Ins->data = temp;
            }else {
                Ins = Ins->next;
            }
        }
        current = current->next;
    }
    
}

void print(node* head){
    while(head!=NULL){
        cout<<head->data<<" ";
        head = head->next;
    }
    cout<<endl;
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
    insertionSort(head);
    print(head);
}
