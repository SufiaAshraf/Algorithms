#include<iostream>
using namespace std;
int gcd(int a,int b){
	if(b==0){
		return a;
	}else {
		return (gcd(b, a%b));
	}
}
int main() {
	int N1, N2;
	cin>> N1>> N2;
	cout<< gcd(N1, N2);
	return 0;
}