#include<iostream>
using namespace std;

// Top Down Approach
int ladders_sol(int n, int k, int dp[]){
    if(n==0){
        return 1;
    }
    // lookUp
    if(dp[n]!= 0){
        return dp[n];
    }

    // Rec Case
    int ways = 0;
    for(int i=1; i<=k; i++){
        if(n-i>=0){
            ways+=ladders_sol(n-i, k, dp);
        }
    }
    return dp[n] = ways;
}

// Bottom Up
int ladders_Bottom_Up(int n, int k){
    int dp[100]={0};
    dp[0] = 1;
    for(int i=1; i<=n; i++){
        dp[i] = 0;
        for(int j=1; j<=k; j++){
            if(i-j>=0){
                dp[i] += dp[i-j];
            }
        }
    }
    return dp[n];
}

// Another Optimised Approach
int ladders_optimised(int n, int k){
    int dp[100] = {0};
    dp[0] = dp[1] = 1;
    for(int i=2; i<=k; i++){
        dp[i] = 2*dp[i-1];
    }
    for(int i=k+1; i<=n; i++){
        dp[i] = 2*dp[i-1]-dp[i-k-1];
    }
    // for(int i=0; i<=n; i++){
    //     cout<<dp[i]<<" ";
    // }
    return dp[n];
}

int main(){
    int n;
    cin>>n;
    int k;
    cin>> k;
    int dp[100] = {0};
    cout<<ladders_sol(n, k, dp)<<endl;
    cout<<ladders_Bottom_Up(n, k)<<endl;
    cout<<ladders_optimised(n, k)<<endl;
}