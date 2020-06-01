#include<iostream>
using namespace std;
int Search(int A[100][100],int m, int n, int k){
	if((m ==0) || (n==0)){
		return false;
	}
	int smallest = A[0][0];
	int largest = A[n-1][m-1];
	if(k<smallest || k>largest){
		return false;
	}
	int i=0;
	int j= m-1;
		while(i<n && j>=0){
			if(A[i][j] == k){
			return true;

		}if(A[i][j] > k){
			j--;
		}
		else{
			i++;
		}
		}
	return false;
}



int main() {
	int n, m;
	cin >> n>>m;
	int A[100][100];
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			cin >> A[i][j];
		}
	}
	int k;
	cin >> k;
	if(Search(A,m, n, k) == true){
		cout << "1";
	}else{
		cout << "0";
	}
	return 0;
}