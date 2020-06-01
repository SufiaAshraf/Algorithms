#include<iostream>
using namespace std;
void bubbleSorting(int a[], int n){

	for(int i=0; i<n-1; i++){
		for(int j=0; j<n-i-1; j++){
			if(A[j]>A[j+1]){
				int temp;
				temp = A[j];
				A[j] = A[j+1];
				A[j+1] = temp;
			}
			
        }
	}
}

int main(){
	int n;
	cin >> n;
	int A[100];
	for(int i=0; i<n; i++){
		cin>> A[j];
	}
	bubbleSorting(A, n);
	cout << "Sorted Array: ";
	for(int i=0; i<n; i++){
		cout << A[i] << ", ";
	}
}