#include<bits/stdc++.h>
using namespace std;
#define ll long long int
// Bottom Up
int knapsack(int *arr,int n,int s,int* value)
{
    int dp1[10000]={0};
    for(int i=0;i<n;i++)
    {
        for(int j=s;j>=arr[i];j--)
        dp1[j]=max(dp1[j],dp1[j-arr[i]]+value[i]);
    }
    return dp1[s];
}
// Bottom Up sing 2D array
int  knapSack2(int S,int* size,int* val,int N){
    int i, j;
    int dp[N+1][S+1];
    for(i=0; i<=N; i++){
        for(j=0; j<=S; j++){
            if(i==0 || j==0){
                dp[i][j] = 0;
            }else if(size[i-1]<=j){
                dp[i][j] = max(val[i-1]+dp[i-1][j-size[i-1]], dp[i-1][j]);
            }else{
                dp[i][j] = dp[i-1][j];
            }
        }
    }
    return dp[N][S];
}

ll dp[1005][1005];
// Top Down Dp Approach
ll knapSack3(int S, int* size, int* val, int N){
    // Base case
    if(N==0 || S==0){
        return 0;
    }
    if(dp[N][S]!=0){
        return dp[N][S];
    }
    ll include =0;
    ll exclude =0;
    if(size[N-1]<=S){
        include = val[N-1]+knapSack3( S-size[N-1], size, val, N-1);
    }
    exclude = knapSack3(S, size, val, N-1);
    dp[N][S] = max(include, exclude);
    return dp[N][S];
}

int main() {
    int N, S;
    cin>> N>>S;
    int size[N], val[N];
    for(int i=0; i<N; i++){
        cin>> size[i];
    }
    for(int i=0; i<N; i++){
        cin>> val[i];
    }
    cout<< knapSack(S, size, val, N)<<endl;
}
