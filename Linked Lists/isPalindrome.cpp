#include <iostream>
#include <stack>
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

bool isPalindrome(node*&head) {
    // Temp pointer
    node* slow = head;

    // Declare a stack
    stack <int> s;
    // Push all elements onto stack
    while(slow!=NULL){
        s.push(slow->data);
        // Move slow pointer to next
        slow = slow->next;
    }
    while(head!=NULL){
        // Get the topmost element
        int i= s.top();
        // pop the element
		s.pop();
        if(head->data != i){
            return false;
        }
        head = head->next;
    }
    return true;
}
int main(){
   int n;
   cin>> n;
	node* head =  NULL;
   for(int i=0; i<n; i++){
       int data;
       cin>> data;
       insertAtTail(head, data);
   }
    if(isPalindrome(head)){
        cout<< "True";
    }else {
        cout<< "False";
    }
	return 0;
}