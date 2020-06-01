#include<bits/stdc++.h>
using namespace std;
class node{
public:
     int data;
     node* next;
     
	//  Constructor
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

node* append(node* head, int k, int n)
{
      if(k<=0)
      return head;
      if(k>=n){
		  k = k%n;
	  }
      node* temp = head;
        for(int i=0;i<n-k-1;i++){
            temp = temp->next;
        } 
      node* temp2 = head;
        for(int i=1;i<n;i++){
            temp2 = temp2->next;
        } 
      temp2->next = head;
      head = temp->next;
      temp->next = NULL;
      return head;
}
void print(node* head){
     while(head !=NULL){
          cout<<head->data<<" ";
          head = head->next;
     }
    
}
int main(){
     int n,k;
     cin>>n;
     node *head = NULL;
     for(int i=0;i<n;i++)
     {  
         int data;
          cin>>data;
          insertAtTail(head,data);
     }
     cin>>k;
     head = append(head,k,n);
     print(head);
}