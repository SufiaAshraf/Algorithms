#include <iostream>
using namespace std;

#define ll long long int

int main(){
    int t;
    cin>> t;
    ll arr[30];
    arr[0] = 1;
    arr[1] = 2;
    for(int i=2; i<=30; i++){
        arr[i] = arr[i-1] + arr[i-2];
    }
    for(int T=1; T<=t; T++){
        int n;
        cin>> n;
        cout<<"#"<<T<<" : "<<arr[n]<<endl;
    }
    return 0;
}