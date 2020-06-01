#include<iostream>
using namespace std;

int dp[2001][2001][6];
int N, M;

int kOrderedLCS(int* a,int* b,int i,int j,int k){
    if(k<0){
        return -1;
    }
    if(i==N || j==M){
        return 0;
    }
    
    if(dp[i][j][k] !=-1){
        return dp[i][j][k];
    }
    int ans =0;
    if(a[i]==b[j]){
        ans = 1+kOrderedLCS(a, b, i+1, j+1, k);
    }else{
        if(k>0){
            ans =  1+kOrderedLCS(a, b, i+1, j+1, k-1);
        }
        ans = max(ans , kOrderedLCS(a, b, i, j+1, k));
        ans = max(ans, kOrderedLCS(a, b, i+1, j, k));
    }
  
    return dp[i][j][k] = ans;
}
int main(){
    int k;
    cin>> N>>M>>k;
    int a[N];
    int b[M];
    for(int i=0; i<N; i++){
        cin>> a[i];
    }
    for(int j=0;j<M; j++){
        cin>> b[j];
    }
    for(int i=0; i<=2000; i++){
        for(int j=0; j<=2000; j++){
            for(int k=0; k<=5; k++){
                dp[i][j][k] =-1;
            }
        }
    }
    cout<< kOrderedLCS(a,b,0,0,k);
}