#include<iostream>
#include<bits/stdc++.h>

int firstOcc(int A[100] , int n, int k){
    int start = 0;
    int end = n-1;
    int ans = -1;
    while(start<=end){
        int mid = start +(end-start)/2;
        if(k == A[mid]){
            ans = mid;
            end = mid -1;
        }else if(k<A[mid]){
            end = mid-1;
        }else if ( k>A[mid]){
            start = mid+1;
        }
    }
    return ans;
}

int lastOcc(int A[100] , int n, int k){
    int start = 0;
    int end = n-1;
    int ans = -1;
    while(start<=end){
        int mid = start +(end-start)/2;
        if(k == A[mid]){
            ans = mid;
            start = mid+1;
        }else if(k<A[mid]){
            end = mid-1;
        }else if ( k>A[mid]){
            start = mid+1;
        }
    }
    return ans;
}



using namespace std;
int main() {
    int n;
    cin>>n;
    int A[n];
    for(int i=0; i<n; i++){
        cin>> A[i];
    }
    int t;
    cin >> t;
    while(t--){
        int k;
        cin>>k;
        cout<<firstOcc(A,n, k)<<" "<<lastOcc(A, n, k)<<endl;
    }
	return 0;
}
