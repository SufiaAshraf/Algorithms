#include<iostream>
#include<bits/stdc++.h>
using namespace std;
// Top down
int minJumpsRequired(int* A,int n){
	int* dp = new int[n];
    int i,j;
    if(n==0 || A[0] ==0){
        return INT_MAX;
    }
    dp[0]=0;
    for( i=1; i<n; i++){
        dp[i] = INT_MAX;
        for(j=0; j<i; j++){
            if(i<=j+A[j] && dp[j] != INT_MAX){
                dp[i] = min(dp[i], dp[j]+1);
                break;
            }
        }
    }
    return dp[n-1];
}

// Bottom up
int minJumps(int *A, int n){
    int* dp = new int[n];
    int min;
    dp[n-1] =0;
    for(int i=n-2; i>=0; i--){
        if(A[i]==0){
            dp[i] = INT_MAX;
        }
        else if(A[i] >= n-i-1){
            dp[i] =1;
        }
        else{
            min= INT_MAX;
            for(int j=i+1; j<n && j<= A[i]+i; j++){
                if(min>dp[j]){
                    min = dp[j];
                }
            }
            if(min != INT_MAX){
                dp[i] = min+1;
            }else{
                dp[i] = min;
            }
        }
    }
    return dp[0];
}

int main() {
	int t;
	cin>> t;
	while(t--){
		int n;
		cin>> n;
		int A[n];
		for(int i=0; i<n; i++){
			cin>> A[i];
		}
		cout<< minJumpsRequired(A, n)<<endl;
	}
	return 0;
}