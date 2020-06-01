#include <iostream>
using namespace std;
void selectionSort(int a[], int n ){
	for(int i=0; i<n-1; i++){
		// Assume ith element is the minimum
		int minIndex = i;
		for(int j=i+1; j<n;j++){
			if(a[j]<a[minIndex]){
				minIndex = j;
			}
		}
		swap(a[minIndex], a[i]);
	}
}


int main(){
	int A[100];
	int n;
	cin >> n;
	for(int i=0;i<n;i++){
		cin>>A[i];
	}
	selectionSort(A, n);
    for(int j=0; j<n; j++){
        cout << A[j] <<" ";
    } 
	return 0;
}