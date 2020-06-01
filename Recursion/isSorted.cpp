#include<iostream>
using namespace std;

bool isSorted(int A[] , int n){
    if(n==0 || n==1){
        return true;
    }
    if(A[n-1] < A[n-2]){
        return false;
    }
    else {
        isSorted(A, n-1);
    }
}

int main() {
    int n;
    cin>>n;
    int A[n];
    for(int i=0; i<n; i++){
        cin>> A[i];
    }
    if(isSorted(A, n)){
        cout<< "true"<<endl;
    }else{
        cout<< "false"<< endl;
    }
	return 0;
}