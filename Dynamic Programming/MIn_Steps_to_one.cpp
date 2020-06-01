#include<iostream>
#include<climits>
using namespace std;

// Top Down Approach
int MinSteps(int n, int* dp){
    // Base Case
    if(n==1 ){
        return 0;
    }
    // Rec Case
    // Lookup if dp[n] is already computed
    if(dp[n]!=0){
        return dp[n];
    }
    // Compute if dp[n] is not known
    int op1, op2,op3;
    op1 = op2 = op3 = INT_MAX;
    if(n%3 == 0){
        op1 = MinSteps(n/3, dp)+1;
    }
    if(n%2 == 0){
        op2 = MinSteps(n/2, dp)+1;
    }
    op3 = MinSteps(n-1, dp)+1;
    int ans = min(min(op1, op2), op3);
    return dp[n] = ans;
}

int minStepsBU(int n){
    // Bottom Up
    int dp[100] = {0};
    dp[1] = 0;
    for(int i=2; i<=n; i++){
        int op1, op2, op3;
        op1 = op2 = op3 = INT_MAX;
        if(n%3 == 0){
            op1 = dp[i/3];
        }
        if(n%2 == 0){
            op2 = dp[i/2];
        }
        op3 = dp[i-1];
        dp[i] = min(min(op1, op2), op3) +1;
    }
    return dp[n];
}

int main(){
    int n;
    cin>> n;
    int dp[1000]={0};
    cout<< MinSteps(n, dp)<<endl;
    cout<<minStepsBU(n)<<endl;
}