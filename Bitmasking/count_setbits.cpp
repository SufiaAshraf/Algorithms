#include<iostream>
using namespace std;

unsigned int countSetBits(int n){
	unsigned int count=0;
	while(n!=0){
		count+= n&1;
		n >>=1;
	}
	return count;
}

int main() {
	int t;
	cin>> t;
	while(t--){
		int n;
		cin>>n;
		cout<<countSetBits(n)<< endl;
	}
	return 0;
}