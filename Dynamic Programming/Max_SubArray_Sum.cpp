#include<iostream>
using namespace std;

int maxSum(int* arr, int n){
    int dp[100] = {0};
    dp[0] = arr[0]>0?arr[0]:0;
    int max_so_far = dp[0];
    for(int i=1; i<n; i++){
        dp[i] = dp[i-1]+arr[i];
        if(dp[i]<0){
            dp[i] = 0;
        }
        max_so_far = max(dp[i], max_so_far);
    }
    return max_so_far;
}

// Space Optimised
int maxSumSpaceOpt(int a[], int n){
    int currentSum =0;
    int max_so_far = 0;
    for(int i=0; i<n; i++){
        currentSum +=a[i];
        if(currentSum<0){
            currentSum = 0;
        }
        max_so_far = max(currentSum, max_so_far);
    }
    return max_so_far;
}
// Special Case
// Array contains all -ve element
// You need to output the smallest -ve element

int main(){
    int arr[] = {-3, 2, 5, -1, 6, 3, -2, 7, -5, 2};
    int n = sizeof(arr)/sizeof(int);
}