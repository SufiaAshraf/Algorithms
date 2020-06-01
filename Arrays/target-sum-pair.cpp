#include<iostream>
#include<algorithm>
using namespace std;

int main() {
	int n;
	cin>>n;
	int A[1000];
	for(int i=0; i<n; i++){
		cin>> A[i];
	}
	int target;
	cin>>target;

	sort(A, A+n);
	int* l = &A[0];
	int* r = &A[n-1];
	while(l<r){
		if(*l+*r < target){
			l++;
		}
		if(*l+*r > target){
			r--;
		}
		if(*l+*r == target){
			cout<< *l << " and "<< *r<<endl;
			l++;
			r--;
		}
	}

	return 0;
}