#include<iostream>
#include<bits/stdc++.h>

using namespace std;
int binarySearch(int A[100], int n, int m){
    int Start = 0;
    int End = n-1;
    int mid = Start+(End - Start)/2;
    while(Start<=End){
        mid = Start+(End - Start)/2;
        if(m>A[mid]){
            Start = mid+1;    
       }else if(m==A[mid]){
           return mid;
       }else if(m<A[mid]){
           End = mid-1;
       }
    }
    return -1;
}


int main() {
    int n;
    cin>> n;
    int A[n];
    for(int i=0; i<n; i++){
        cin>> A[i];
    }
    int m;
    cin>>m;
    cout<<binarySearch(A , n , m);
	return 0;
}