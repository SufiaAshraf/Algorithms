#include<iostream>

using namespace std;
int main() {
	int n;
	cin>> n;
	int A[n];
	for(int i=0; i<n; i++){
		cin>> A[i];
	}
	int left_max[n];
	int right_max[n];
	left_max[0] = A[0];
	right_max[n-1] = A[n-1];
	for(int i=1; i<n; i++){
		left_max[i] = max(left_max[i-1], A[i]);
	} 
	for(int i=n-2; i>=0; i--){
		right_max[i] = max(right_max[i+1], A[i]);
	}
	int sum =0; 
	for(int i=0; i<n; i++){
		sum+=min(left_max[i], right_max[i]) - A[i];
	}
	cout<< sum;
	return 0;
}