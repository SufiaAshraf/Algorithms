#include <iostream>
#include <stack>
using namespace std;

class Queue{
    stack <int> s1, s2;
public:
    void enQueue(int x){
        while(!s1.empty()){
            s2.push(s1.top());
            s1.pop();
        }
        // push x to s1
        s1.push(x);

        // push everything back to s1
        while(!s2.empty()){
            s1.push(s2.top());
            s2.pop();
        }
    }

    void deQueue(){
        // if first stack is empty
        if(s1.empty()){
            exit(0);
        }

        // return top of s1
        int x = s1.top();
        s1.pop();
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