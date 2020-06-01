#include<iostream>
using namespace std;
 int dp[100];
int lis(int* A,int n){
   
    for(int i=0; i<n; i++){
        dp[i]=1;
    }
    int best = -1;
    for(int i=1; i<n; i++){
        for(int j= 0; j<i; j++){
            if(A[j]<=A[i]){
                // jth element can by absorbed by ith element
                int curr = 1 + dp[j];
                dp[i] = max(curr, dp[i]);
            }

        }
        best = max(best, dp[i]);
    }
    return best;
}

int main(){
    int A[100];
    int n;
    cin>> n;
    for(int i=0; i<n; i++){
        cin>> A[i];
    }
    cout<< lis(A, n)<<endl;
}