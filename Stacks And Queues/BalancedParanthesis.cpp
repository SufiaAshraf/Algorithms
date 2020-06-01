#include <iostream>
#include<stack>
#include <cstring>
using namespace std;

bool checkExpression(string str){
    stack <char> s;
    for(int i=0; i<str.size(); i++){
        char curChar = str[i];
        if(curChar == '('){
            s.push(curChar);
        }
        else if(curChar == ')'){
            if(s.empty() || s.top() != '('){
                return false;
            }
            s.pop();
        }
    }
	for(int i=0; i<str.size(); i++){
        char curChar = str[i];
        if(curChar == '{'){
            s.push(curChar);
        }
        else if(curChar == '}'){
            if(s.empty() || s.top() != '{'){
                return false;
            }
            s.pop();
        }
    }
	for(int i=0; i<str.size(); i++){
        char curChar = str[i];
        if(curChar == '['){
            s.push(curChar);
        }
        else if(curChar == ']'){
            if(s.empty() || s.top() != '['){
                return false;
            }
            s.pop();
        }
    }
    return s.empty();
}


int main(){
    string exp;
    cin>>exp;

    bool isValid = checkExpression(exp);
		if(isValid){
				cout<<"Yes";
		}else{
			cout<<"No";
		}
    return 0;
}