#include<iostream>
#include<bits/stdc++.h>
#include<vector>
using namespace std;
#define ll long long int
int product(vector<int> &A){
    int dp[200][200]={0};
    int n = A.size()-1;
    for(int i=1; i<n; i++){
        ll r=0 , c=i;
        while(c<n){
            int val = INT_MAX;
            for( int pivot = r; pivot<c; pivot++){
                val = min(val, dp[r][pivot] + dp[pivot+1][c] + A[r]*A[pivot+1]*A[c+1]);
            }
            dp[r][c] = val;
            r++;
            c++;
        }
    }
    return dp[0][n-1];
}   

int main(){
    vector<int> A;
    int n;
    cin>> n;
    for(int i=0; i<n; i++){
        int x;
        cin>>x;
        A.push_back(x);
    }
}