#include<iostream>
#include<climits>
using namespace std;
#define ll long long int
ll A[40];

ll optimalGameStrategy( int s, int e){
	if(s>e){
		return 0;
	}
	ll pickfirst =A[s] + min(optimalGameStrategy( s+2, e), optimalGameStrategy( s+1, e-1));
	ll pickLast =A[e] + min(optimalGameStrategy(s, e-2), optimalGameStrategy(s+1, e-1));

	return max(pickLast, pickfirst);
}
int main() {
	int n;
	cin>> n;
	for(int i=0; i<n; i++){
		cin>> A[i];
	}
	cout<< optimalGameStrategy(0, n-1);
	return 0;
}