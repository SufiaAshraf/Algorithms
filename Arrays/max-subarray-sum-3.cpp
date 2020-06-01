#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>> n;
        int A[n];
        for(int i=0; i<n;i++){
            cin>> A[i];
        }
        int currentSum=0;
        int maxSum =0;
        for(int i=0; i<n; i++){
            currentSum+=A[i];
            if(currentSum<0){
                currentSum = 0;
            }if(currentSum>maxSum){
                maxSum= currentSum;
            }
        }
        cout<<maxSum<<endl;
    }
	return 0;
}