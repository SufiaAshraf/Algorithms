#include<iostream>
using namespace std;
void InsertionSorting(int a[], int n){
	for(int i=1; i<n; i++){
		int j=i-1;
		int no = a[i];
		while(j>=0 && a[j]>no){
			a[j+1] = a[j];
			j--;
		}
		a[j+1] = no;
	}
}

int main(){
	int n;
	cin >> n;
	int A[100];
	for(int i=0; i<n; i++){
		cin>> A[j];
	}
	InsertionSorting(A, n);
	cout << "Sorted Array: ";
	for(int i=0; i<n; i++){
		cout << A[i] << ", ";
	}
}