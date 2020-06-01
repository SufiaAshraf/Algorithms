#include <iostream>
#include <stack>
using namespace std;

int main(){
    int n, q, v;
    vector<int> primes;
    cin>>n>>q;
    primes.push_back(2);
    for(int i=3; i<=10000; i++){
        int no=0;
        for(int j=2; j*j<=i; j++){
            if(i%j == 0){
                no=1;
            }
        }
        if(!no)
            primes.push_back(i);
    }
    stack<int>stack1, stack2, stack3;
    for(int i=0;i<n; i++){
        cin>>v;
        stack1.push(v);
    }
    for(int i=0;i<q; i++){
        if(stack1.empty()){
            break;
        }
        int curr = primes[i];
        while(!stack1.empty()){
            int curEle = stack1.top();
            stack1.pop();
            if(curEle%curr == 0){
                stack2.push(curEle);
            }else{
                stack3.push(curEle);
            }
        }
        while(!stack2.empty()){
            cout<<stack2.top()<<endl;
            stack2.pop();
        }
        stack1 = stack3;
        while(!stack3.empty()){
            stack3.pop();
        }
    }
    while(!stack1.empty()){
        cout<<stack1.top()<<endl;
        stack1.pop();
    }

    return 0;
}