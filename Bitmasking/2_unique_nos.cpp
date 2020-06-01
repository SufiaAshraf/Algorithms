#include<iostream>
using namespace std;

int main(){
    int n;
    cin>>n;
    int no.;
    int a[100005];
    int Xor = 0;
    for(int i=0; i<n; i++){
        cin>> no.;
        a[i] = no.;
        Xor = Xor ^ no.;
    }
    int temp = Xor;
    int pos = 0;
    while((temp&1) != 1){
        pos++;
        temp = temp>>1;
    }
    int mask = (1<<pos);
    int x =0;
    int y =0;
    for(int i=0; i<n; i++){
        if((a[i]&mask)>0){
            x = x^a[i];
        }
    }
    y = Xor^x;
    cout<< min(x,y)<<endl<<max(x,y);

}