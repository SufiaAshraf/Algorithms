#include<iostream>
using namespace std;
int max_profit(int* profit, int n, int* dp){
    if(n == 0){
        return 0;
    }
    if(dp[n]!=0){
        return dp[n];
    }
    int best = 0;
    for(int i = 1; i<=n; i++){
        int net_profit = profit[i] + max_profit(profit, n-i, dp);
        best = max(best, net_profit);
    }
    return dp[n] = best;
}

int max_profit_BU(int n, int* profit){
    int dp[100] = {0};
    int best =0;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=i; j++){
           best = max(best, dp[i] = profit[j]+dp[i-j]);
        }
        dp[i] = best;
    }
    return dp[n];
}

int main(){
    int profit[100];
    int n;
    cin>>n;
    for(int i=1; i<=n; i++){
        cin>> profit[i];
    }
    int dp[100] = {0};
    cout<<  max_profit(profit, n,dp)<<endl;
    cout<<max_profit_BU(n, profit)<<endl;
}