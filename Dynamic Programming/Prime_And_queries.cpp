
#include<iostream>
using namespace std;


bool isPrime (int number) { 
    if (number < 2) return false;
    if (number == 2) return true;
    if (number % 2 == 0) return false;
    for (int i=3; (i*i) <= number; i+=2) {
        if (number % i == 0 ) return false;
    }
    return true;
}


int main() {
   
    int q;
    cin >> q;
    while(q--){
        int a;
        int b;
        cin>>a>>b;
        int z=0,y=0;
        for(int i=a; i<=b; ++i)
        {
       bool flag = isPrime(i);
        if(flag)
        {
            z=i;
            //cout<<z<<" ";
            break;
        }
        }
        
        for(int i=b; i>=a; i--)
        {
       bool flag = isPrime(i);
        if(flag)
        {
            y=i;
           // cout<<y<<" ";
            break;
        }
        }
        //int x=v.size();
        cout <<y-z<< endl;
    }