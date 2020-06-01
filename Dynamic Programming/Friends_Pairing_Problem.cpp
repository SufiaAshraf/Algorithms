#include<iostream>
using namespace std;

int friendPair(int n, int* A, int* dp){
    dp[0] = 0;
    dp[1] = 1;
    dp[2] = 2;
    for(int i=3; i<=n; i++){
        dp[i] = (dp[i-1]+(i-1)*dp[i-2]);
    }
    return dp[n];
}

int main(){
    int n;
    cin>>n;
    int A[n];
    for(int i=0; i<n; i++){
        cin>> A[i];
    }
    int dp[1000] = {0};
    cout<< friendPair(n, A, dp);
}