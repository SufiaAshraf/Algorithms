#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define MOD 1000000007
int dp[1001][1001];

int numWays(int m, int n){
    // Base Case
    if(dp[0][0] == -1){
        return 0;
    }
    // Compute ways for first row
    for(int j=0; j<n; j++){
        if(dp[0][j] == -1){
            break;
        }
        dp[0][j] = 1;
    }
    for(int j=0; j<m; j++){
        if(dp[j][0] == -1){
            break;
        }
        dp[j][0] = 1;
    }
    // Bottom Up
    for(int i=1; i<m; i++){
        for(int j=1; j<n; j++){
            if(dp[i][j] == -1){
                continue;
            }
            dp[i][j] = 0;
            if(dp[i][j-1]!=-1){
                dp[i][j] = dp[i][j-1]%MOD;
            }
            if(dp[i-1][j]!=-1){
                dp[i][j] = (dp[i][j] + dp[i-1][j])%MOD;
            }
        }
        
    }
    if(dp[m-1][n-1] == -1){
            return 0;
        }
        return dp[m-1][n-1];
}

int main(){
    memset(dp, 0, sizeof(dp));
    int m, n, p;
    cin>> m>> n>>p;
    for(int i=0; i<p; i++){
        int x, y;
        cin>> x>> y;
        dp[x-1][y-1] = -1;
    }
    cout<< numWays(m, n)<<endl;
}