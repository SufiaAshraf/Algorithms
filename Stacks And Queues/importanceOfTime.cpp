#include <iostream>
#include <queue>

using namespace std;

int main(){
    int n;
    cin>> n;
    queue <int> q1;
    queue <int> q2;
    int x;
    for(int i=0; i<n; i++){
        cin>> x;
        q1.push(x);
    }
    for(int i=0; i<n; i++){
        cin>> x;
        q2.push(x);
    }
    int t =0;
    while(!q1.empty()){
        if(q1.front() != q2.front()){
            int c = q1.front();
            q1.pop();
            q1.push(c);
            t++;
        }else {
            q1.pop();
            q2.pop();
            t++;
        }
    }
    cout<<t;
    return 0;
}