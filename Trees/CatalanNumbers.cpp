#include<iostream>
using namespace std;
// overlapping subproblems
int dp[100] = {0};
// binary search trees
int Catalan(int n){
    if(n==0){
        return 1;
    }
    if(dp[n]!=0){
        return dp[n];
    }
    int ans = 0;
    for(int i=1; i<=n; i++){
        ans += Catalan(i-1)+Catalan(n-i);
    }
    dp[n] = ans;
    return ans;
}

int main(){
    int n;
    cin>>n;
    for(int i=0; i<=n; i++){
        cout<<Catalan(i)<<",";
    }
}