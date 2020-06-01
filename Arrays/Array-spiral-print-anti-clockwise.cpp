#include<iostream>
using namespace std;
int main() {
	int m;
	int n;
	cin>> m>> n;
	int A[m][n];
	for(int i=0; i<m; i++){
		for(int j=0; j<n; j++){
			cin>> A[i][j];
		}
	}
	int start_row = 0;
	int end_row = m-1;
	int start_column = 0;
	int end_column = n-1;
	while(start_row<=end_row && start_column<= end_column){
		for(int i= start_row; i<=end_row; i++){
			cout<< A[i][start_column]<< ", ";
		}
		start_column++;
		for(int j = start_column; j<= end_column; j++){
			cout<< A[end_row][j]<< ", ";
		}
		end_row--;
		if(end_row>start_row){
			for(int i=end_row; i>=start_row; i--){
				cout<< A[i][end_column]<< ", ";
			}
			end_column--;
		}
		if(start_column<end_column){
			for(int i=end_column; i>=start_column; i--){
				cout<< A[start_row][i]<< ", ";
			}
			start_row++;
		}
	}
	cout<< "END"<< endl;
		return 0;
}