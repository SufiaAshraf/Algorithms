#include <iostream>
using namespace std;

class node{
public: 
    int data;
    node* next;

    // constructor
    node(int d){
        data = d;
        next = NULL;
    }
};

void insertatTail(node *&head, int data){
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

node* midPoint(node* head){
    if(head == NULL || head->next == NULL){
        return head;
    }
    node*slow  = head;
    node*fast  = head ->next;
    while(fast!=NULL && fast->next != NULL){
        fast = fast->next->next;
        slow = slow->next;
    }
    return slow;
}

node* merge(node*a, node*b){
    if(a == NULL){
        return b;
    }else if( b== NULL){
        return a;
    }
    node* c;

    if(a->data < b->data){
        c = a;
        c->next = merge(a->next , b);
    }else {
        c = b;
        c->next = merge(a, b->next);
    }
    return c;
}

// node* mergeSort(node* head){
//     // Base Case
//     if(head == NULL || head->next == NULL){
//         return head;
//     }
//     // Rec Case
//     // 1.Mid Point
//     node* mid = midPoint(head);
//     node* a = head;
//     node* b = mid->next;
//     mid->next = NULL;

//     // 2.Recursively sort
//     a = mergeSort(a);
//     b = mergeSort(b);
    
//     // 3. Merge a and b;
//     node* c = merge(a, b);
//     return c;
// }

void print(node* head){
    while(head != NULL){
        cout<< head->data<<" ";
        head = head->next;
    }
    cout<< endl;
}

int main(){
    int t;
    cin>> t;
    while(t--){
        int N1;
        cin>> N1;
        node* head1 = NULL;
        for(int i=0; i<N1; i++){
            int data;
            cin>> data;
            insertatTail(head1, data);
        }
        int N2;
        cin>> N2;
        node* head2 = NULL;
        for(int j=0; j<N2; j++){
            int data;
            cin>> data;
            insertatTail(head2, data);
        }
       node* head3 = merge(head1, head2);
      print(head3);
    }
}