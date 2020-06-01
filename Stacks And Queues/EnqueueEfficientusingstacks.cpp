#include <iostream>
#include <stack>
using namespace std;

class Queue{
    stack <int> s1, s2;
public:
    void enQueue(int x){
       s1.push(x);
    }

    void deQueue(){
       while(!s1.empty()){
           s2.push(s1.top());
           s1.pop();
       }
       int x = s2.top();
       s2.pop();
       return x;
    }
};

int main(){
    int n;
    cin>> n;
    Queue q;
    for(int i=0; i<n; i++){
        q.enQueue(i);
    }
    while(n<0){
        cout<<q.deQueue()<<" ";
    }
    return 0;
}