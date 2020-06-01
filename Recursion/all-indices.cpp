#include<iostream>
using namespace std;

void indices(int A[] , int n,int m, int i){
	if(i == n){
		return;
	}
	if(A[i] == m){
		cout<< i<<" ";
	}
	indices(A, n, m, i+1);
}

int main() {
	int n;
	cin>>n;
	int A[n];
	for(int i=0; i<n; i++){
		cin>> A[i];
	}
	int m;
	cin>>m;
	indices(A, n, m, 0);
	return 0;
}