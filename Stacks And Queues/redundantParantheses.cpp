#include <iostream>
#include<stack>
#include<cstring>
using namespace std;

bool findDuplicates(string str){
    stack <char > s;
    // Iterate through expression
    for(char ch:str){
        // If character is ) pop
        if(ch == ')'){
            // pop character from stack
            char top = s.top();
            s.pop();
            if(top == '('){
                return true;
            }else{
                while(top !='('){
                    
                    top = s.top();
                    s.pop();
                }
            }
        }
        else {
            s.push(ch);
        }
    }
    return false;
}



int main(){
    int t;
    cin>> t;
    string str;
    while(t--){
        cin>> str;
        if(findDuplicates(str)){
            cout<<"Duplicates"<<endl;
        }else {
            cout<<"Not Duplicates"<<endl;
        }
    }
}