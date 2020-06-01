#include<iostream>
using namespace std;

unsigned int countsetbits(int n){
	unsigned int count = 0;
	while(n!=0){
		count+= n&1;
		n>>=1;
	}
	return count;
}

int main() {
	int q;
	cin>> q;
	while(q--){
		int a, b;
		cin>> a>> b;
		unsigned int finalCount = 0;
		while(a<=b){
			finalCount += countsetbits(a);
			a++;
		}
		cout<< finalCount<< endl;
	}
	return 0;
}