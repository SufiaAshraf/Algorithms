#include<iostream>
#include <bits/stdc++.h>

using namespace std;

int bitonic(int A[], int n){
	int inc[n];
	int dec[n];
	int i;
	int max;
	inc[0] = 1;
	dec[n-1] = 1;
	for(i=1; i<n; i++){
		if(A[i]>=A[i-1]){
			inc[i] = inc[i-1] +1;
		}else{
			inc[i] = 1;
		}
	}
	for(i=n-2; i>=0; i--){
		if(A[i] >= A[i+1]){
			dec[i] = dec[i+1] +1;
		}
		else{
			dec[i] = 1;
		}
	}
	max = inc[0] + dec[0] - 1;
	for(int i=1; i<n; i++){
		if(inc[i]+dec[i] - 1 > max){
			max = inc[i] +dec[i] -1;
		}
	}
	return max;
}

int main() {
	int t;
	cin>> t;
	while(t--){
		int n;
		cin>> n;
		int A[n];
		for(int i=0; i<n; i++){
			cin>> A[i];
		}
		cout<< bitonic(A, n)<< endl;
	}
	return 0;
}

