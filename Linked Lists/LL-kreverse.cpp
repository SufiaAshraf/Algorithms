#include <iostream>
using namespace std;

class node{
public: 
        int data;
        node* next;

            //Constructor
            node(int d) {
                data = d;
                next = NULL;
            }
};


void insertAtTail(node*&head, int data){
    if(head == NULL){
        head = new node(data);
        return;
    }
    node*tail = head;
    while(tail->next !=NULL){
        tail = tail->next;
    }
    tail->next = new node(data);
    return;
}

void print(node*head){
    while(head!=NULL){
        cout<<head->data<<" ";
        head = head ->next;
    }
    cout<<endl;
}
node* reverse(node* head, int K){
    node* current = head;
    node* next = NULL;
    node* prev = NULL;
    int count = 0;

    // Reverese first k nodea of the linked list
    while(current != NULL && count < k){
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
        count++;
    }
    // next i now pointer to K+1th node 
    // Recursively call for the list starting from current and make rest of the list as next of first node
    if(next!=NULL){
        head->next = reverse(next, k);
    }
    return prev;
}

int main(){
    int N, K;
    cin>> N;
    cin>>K;
    node* head = NULL;
    for(int i = 0; i<N; i++){
        int data;
        cin>> data;
        insertAtTail(head, data);
    }
    head = reverse(head, K);
    print(head);
}