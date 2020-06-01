#include<iostream>
#include<climits>
using namespace std;
#define INF 100000000
int minPrice(int i, int W, int* val, int* dp){
    if(W==0){
        return 0
    }
    if(i == val.length()){
        return INF;
    }
    if(dp[i][W] !=-1){
        return dp[n][W];
    }
    int ans = INF;
    if(W>=i+1 && val[i] !=-1){
        ans = minPrice(i, W-i-1, val, dp)+val[i];
    }
    int exclude = minPrice(i+1, W, val, dp);
    return dp[i][W] = min(ans, exclude);
}

int main(){
    int n, W;
    cin>> n>>W;
    int val[W+1];
    for(int i=0; i<W; i++){
        cin>> val[i];
    }
    int dp[n+1][W+1];
    for(int i=0; i<=n; i++){
        dp[i][0] = 0;
    }
    for(int j=0; j<=W; j++){
        dp[0][j] = INF;
    }
    cout<< minPrice(0, W, val, dp)<<endl;
}