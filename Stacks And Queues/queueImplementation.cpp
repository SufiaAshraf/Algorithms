#include<iostream>
using namespace std;

template<typename T>
class Queue{
    T *arr;
    int f;
    int r;
    int ms;
    int cs;
public:
    // Constructors
    Queue(int ds= 4){
        f = 0;
        ms = ds;
        r = ms-1;
        arr = new T[ms];
        cs = 0;
    }  
    //   Push: Enqueue which inserts data at rear+1
    bool isFull(){
        return cs == ms;
    }
    bool isEmpty(){
        return cs ==0;
    }

    void push(T data){
        if(!isFull()){
            r = (r+1)%ms;
            arr[r] = data;
            cs++;
        }
    }
    void pop(){
        if(!isEmpty()){
            f = (f+1)%ms;
            cs--;
        }
    }

    T getFront(){
        return arr[f];
    }
};


int main(){
    Queue <int > q(10);
    for(int i=1; i<=6; i++){
        q.push(i);
    }
    q.pop();
    a.push(8);

    while(!q.isEmpty()){
        cout<< q.getFront();
        q.pop();
    }
    return 0;
}