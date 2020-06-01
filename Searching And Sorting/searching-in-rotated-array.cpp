#include<iostream>
#include<algorithm>
using namespace std;

int Search(int A, int s, int e, int k){
    // Base Case
    if(s>e){
        return -1;
    }

    // Rec Case
    int mid = (s+e)/2;
    if(A[mid] == k){
        return mid;
    }

    // mid lies in the left part
    if(A[s] < = A[mid]){
        if(k>=A[s] && k<= A[mid]){
            return Search(A, s, mid-1, k);
        }else {
            return Search(A, mid+1, e, k);
        }
    }
    // Mid lies in the right part
    if(A[mid] < = A[e]){
        if(k>= A[mid] && k<= A[e]){
            return Search(A, mid+1, e, k);
        } else {
            return Search(A, s, mid-1, k);
        }
    }
}



int main(){
    int n;
    cin>> n;
    int A[n];
    for(int i=0; i<n; i++){
        cin>> A[i];
    }
    int k;
    cin>>k;
    cout<< Search ( A, 0 , n-1, k);
}