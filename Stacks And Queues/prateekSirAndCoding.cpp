#include <iostream>
#include <stack>
using namespace std;

int main(){
    stack <int> s;
    int q;
    cin>>q;
    while(q){
        int num;
        cin>> num;
        if(num == 1){
            if(s.empty()){
                cout<<"No Code"<<endl;
            }else{
                cout<<s.top()<<endl;
                s.pop();
            }
        }
        if(num == 2){
            int cost;
            cin>> cost;
            s.push(cost);
        }
        q--;
    }
    return 0;
}