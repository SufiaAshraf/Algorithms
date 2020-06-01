#include<iostream>
#include<climits>
using namespace std;

int minTopDown(int N, int* coins, int T, int* dp){
    if(N == 0){
        return 0;
    }
    if(dp[N]!=0){
        return dp[N];
    }
    // Rec Case
    int ans = INT_MAX;
    for(int i=0; i<T; i++){
        if(N-coins[i]>=0){
            int subProb = minTopDown(N-coins[i], coins, T, dp);
            ans = min(ans, subProb+1);
        } 
    }
    dp[N] = ans;
    return dp[N];  
}
int minCoins(int N,int* coins, int T){
    int dp[100] =  {0};
    for(int i=1; i<=N; i++){
        dp[i] = INT_MAX;
        for(int j=0; j<T; j++){
            if(i-coins[j]>=0){
                int sub = dp[i-coins[j]];
                dp[i] = min(dp[i], sub+1);
            }
        }
    }
    return dp[N];
}

int main(){
    int coins[] = {1, 7, 10};
    int dp[100]={0};
    int N;
    cin>> N;
    int T = sizeof(coins)/sizeof(int);
    cout<<minTopDown(N,coins, T, dp) <<endl;
     cout<<minCoins(N,coins, T);

    return 0;
}