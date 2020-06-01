#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define ll long long int
ll dp[10001][10001];

ll optimal(int* A, int i, int j){
    if(i>j){
        return 0;
    }
    if(dp[i][j] !=-1){
        return dp[i][j];
    }
    int c1, c2;
    c1 =A[i] + min(optimal(A, i+2, j), optimal(A, i+1, j-1));
    c2 =A[j] + min(optimal(A, i, j-2), optimal(A, i+1, j-1));
    return dp[i][j] = max(c1, c2);
}

int main(){
    int n;
    cin>> n;
    int A[n];
    for(int i=0; i<n; i++){
        cin>> A[i];
    }
    memset(dp, -1, sizeof(dp));
    cout<< optimal(A, 0, n-1)<<endl;
}