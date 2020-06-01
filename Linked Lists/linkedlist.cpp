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

int length(node*head){
    int len = 0;
    while(head!=NULL){
        head = head->next;
        len+=1;
    }
    return len;
}

void insertAtHead(node*&head, int data){
    node*n = new node(data);
    n->next = head;
    head = n;
}

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


void insertInMiddle(node*&head, int data, int p){
    if(head == NULL || p==0){
        insertAtHead(head, data);
    }else if(p>length(head)){
        insertAtTail(head, data);
    }else {
        int jump =1;
        node*temp = head;
        while(jump<=p-1){
            temp = temp ->next;
            jump+=1;
        }
        node*n = new node(data);
        n->next = temp->next;
        temp->next = n;
    }
}

void searchIterative(node*&head, int key){
    while(head!=NULL){
        if(head->data == key){
            return true;
        }else{
            head = head->next;
        }
    }
    return false;
}

void searchRecursive(node*&head, int key){
    // Base Case
    if(head == NULL){
        return false;
    }
    // Recursive Case
    if(head->data == key){
        return true;
    }else {
        return searchRecursive(head->next , key);
    }
}

void deleteAthead(node*&head){
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
    while(temp -> next != NULL){
        prev = temp;
        temp = temp->next;
    }
    delete temp;
    prev->next = NULL;
    return;
}

void deleteInMiddle(node*&head, int p){
    int jump = 0;
    node*prev = NULL;
    node*temp = head;
    while(jump<=p-1){
        prev = temp;
        temp = temp->next;
        jump+=1;
    }
    delete temp;
    prev->next = p;
}

node* midPoint(node* head){
    if(head == NULL || head->next == NULL){
        return head;
    }
    node*slow = head;
    node*fast = head->next;
    while(fast!=NULL && fast->next != NULL){
        fast = fast->next->next;
        slow = slow->next;
    }
    return slow;
}


void reverse(node*&head){
    node*P = NULL;
    node*N;
    node*C = head;
   while(C!=NULL){
     // Save the next node
    N = C->next;
    // Make current node point to prev
    C->next = P;
    // Update the pointers
    P= C;
    C = N;
    
   }

}

void reverseRec(node*head){
    // Base Case
    if(head ->next == NULL || head == NULL){
        return head;
    }
    // Rrec Case
    node*smallHead = reverseRec(head->next);
    node*C = head;
    C->next->next = C;
    C->next = NULL;
    return smallHead;
}


node* merge(node*a, node*b){
    if(a == NULL){
        return b;
    }
    else if(b==NULL){
        return a;
    }
    node*c;

    // Compare a and b for smaller elements
    if(a->data < b->data){
        c = a;
        c->next = merge(a->next, b);
    }else {
        c = b;
        c->next = merge(a, b->next);
    }
}


node* mergeSort(node*head){
    // Base Case
    if(head == NULL || head->next == NULL){
        return head;
    }
    // Rec Case
    // 1.Mid Point
    node*mid = midPoint(head);
    node*a = head;
    node*b = mid->next;
    mid->next = NULL;

    // 2. Recursively Sort
    a = mergeSort(a);
    b = mergeSort(b);
    
    // 3.Merge a and b
    node*c = merge(a, b);
    return c;

}

void print(node*head){
    while(head!=NULL){
        cout<<head->data<<"-->";
        head = head ->next;
    }
    cout<<endl;
}

void buildList(node*&head){
    int data;
    while(data!=-1){
        insertAtTail(head, data);
        cin>>data;
    }
}

bool detectCycle(node*head){
    node*slow = head;
    node*fast = head;
    while(fast != NULL && fast->next == NULL){
        fast = fast->next->next;
        slow = slow->next;

        if(fast == slow){
            return true;
        }
    }
    return false;
}

int main(){
    node*head = NULL;
    buildList(head);
    print(head);
    return 0;
}