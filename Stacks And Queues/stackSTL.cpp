#include <iostream>
#include<stack>
#include<cstring>

using namespace std;

int main(){
    stack<string> s;
    s.push("Apple");
    s.push("Mangoes");
    s.push("Guava");

    while(!s.empty()){
        cout<<s.top()<<endl;
        s.pop();
    }
    return 0;
}