#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define ll long long int
ll Nth_ugly(ll n){
    ll dp[n]={0};
    ll i2=0, i3=0, i5=0;
    ll next_multiple2 = 2, next_multiple3 = 3, next_multiple5 = 5;
    ll next_ugly =1;
    dp[0] =1;
    for(ll i=1; i<n; i++){
        next_ugly = min(next_multiple2 , min(next_multiple3, next_multiple5));
        dp[i] = next_ugly;
        if(next_ugly == next_multiple2){
            i2++;
            next_multiple2 = dp[i2]*2;
        }
        if(next_ugly == next_multiple3){
            i3++;
            next_multiple3 = dp[i3]*3;
        }
        if(next_ugly == next_multiple5){
            i5++;
            next_multiple5 = dp[i5]*5;
        }
    }
    return next_ugly;
}

int main(){
    ll t;
    cin>> t;
    while(t--){
        ll n;
        cin>> n;
        cout<< Nth_ugly(n)<<endl;
    }
}