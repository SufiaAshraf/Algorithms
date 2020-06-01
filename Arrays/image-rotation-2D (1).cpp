#include<iostream> 
using namespace std;

void imageRoation(int A[][100], int n){
    for(int i=0; i<n/2; i++){
        for(int j=i; j<n-i-1; j++){
            int t = A[i][j];
            // right to top
            A[i][j] = A[j][n-i-1];
            // bottom to right
            A[j][n-i-1] = A[n-i-1][n-j-1];
            // left to bottom
            A[n-i-1][n-j-1] = A[n-j-1][i];
            // assign t to left
            A[n-j-1][i] = t;
        }
    }
}

int main() {
    int  n;
    cin>>n;
    int A[100][100];
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin >> A[i][j];
        }
    }
    imageRoation(A, n);
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cout<< A[i][j]<< " ";
        }
        cout<<"\n";
    }
	return 0;
}