#include<iostream>
#include<algorithm>

using namespace std;
int main() {
    int A[100];
    int n; 
    cin>> n;
    for(int i=0; i<n; i++){
        cin>> A[i];
    }
    sort(A, A+n);
    int T;
    cin>> T;
    int i;
    int* l= &A[1];
    int* r = &A[n-1];
    for(i=0; i<n;){
        while(l<r){
            int T2 = T-A[i];
            if(*l+*r<T2){
                l++;
            }if(*l+*r == T2){
                cout<<  A[i] << ", "<<*l<<" and "<<*r<<"\n";
                l++;
                r--;
            }if(*l+*r>T2){
                r--;
            }
        }
        i++;
        l=&A[i+1];
        r=&A[n-1];
    }
	return 0;
}