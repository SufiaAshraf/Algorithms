#include<iostream>
#include<string>
#include<math.h>
using namespace std;

int stoint(string str){
    if(str.length() == 1){
        return str[0] - '0';
    }   
    double y = stoint(str.substr(1));
    double x = str[0] - '0';
    x = x*pow(10 , str.length()-1)+y;
    return int(x);
 }


int main() {
    string str;
    cin>>str;

    cout<<stoint(str);
	return 0;
}