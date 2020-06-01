#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define mod (10^9)+7
const int MAX_CHAR = 256;
int countSub(string str){
    vector<int>last(MAX_CHAR, -1);
    int n = str.length();
    int dp[n+1];
    dp[0]=1;
    for(int i=1; i<=n; i++){
        dp[i] = (2* dp[i-1])%mod;
        if(last[str[i-1]] !=-1){
            dp[i] = (dp[i]-dp[last[str[i-1]]-1]+mod)%mod;
        }
        last[str[i-1]] = i;
    }
    return dp[n];
}
int main(){
    int t;
    cin>> t;
    while(t--){
        string str;
        cin>> str;
        cout<< countSub(str)%1000000007<<endl;
    }
}