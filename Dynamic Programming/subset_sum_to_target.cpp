#include<iostream>
#include<bits/stdc++.h>
using namespace std;
// recursive solution
bool subsetsumtarget(int* A,int n,int target){
    if(n==0 && target!=0){
        return false;
    }
    if(target==0){
        return true;
    }
    if(A[n-1]>target){
        return subsetsumtarget(A, n-1, target);
    }else{
        return subsetsumtarget(A, n-1, target) || subsetsumtarget(A, n-1, target-A[n-1]);
    }
}
// Bottom Up DP
bool SubSetSumTarget(int* A, int n, int target){
    bool dp[n+1][target+1];
    for(int i=0; i<=n; i++){
        dp[i][0] = true;
    }
    for(int i=0; i<=target; i++){
        dp[0][i] = false;
    }
    for(int i=1; i<=n; i++){
        for(int j=1; j<=target; j++){
            if(j<A[i-1]){
                dp[i][j] = dp[i-1][j];
            }else{
                dp[i][j] = dp[i-1][j] || dp[i-1][j-A[i-1]];
            }
        }
    }
    return dp[n][target];
}

int main(){
    int n;
    cin>>n;
    int target;
    cin>> target;
    int A[n];
    for(int i=0; i<n; i++){
        cin>> A[i];
    }
    if(SubSetSumTarget(A,n,target)){
        cout<<"Yes"<<endl;
    }else{
        cout<<"No"<<endl;
    }
}