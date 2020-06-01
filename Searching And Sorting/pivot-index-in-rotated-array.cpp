#include<iostream>
using namespace std;

int PivotIndex(int A[] , int n , int s, int e){
	 if(s > e){
		 return -1;
	 }
	while ( s<=e){
		int mid = (s+e)/2;
		if(A[mid] > A[mid+1] && mid< e){
			return mid;
		} else if(mid > s && A[mid] < A[mid-1]){
			return mid-1;
		}if(A[s] >= A[mid]){
            e = mid -1
        }
        else {
			s = mid +1;
		}
	}
	return -1;
}


int main() {
	int n;
	int A[n];
	cin>> n;
	for(int i=0; i<n; i++){
		cin>> A[i];
	}
	cout<< PivotIndex(A, n , 0, n-1);
	return 0;
}