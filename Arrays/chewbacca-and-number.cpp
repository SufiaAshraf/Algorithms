#include<iostream>
#include<algorithm>

using namespace std;
int main() {
	char A[50];
	cin>> A;
	int i=0;
	if(A[i] == '9'){
		i++;
	}
	for( ; A[i] != '\0'; i++){
		int digit = A[i] - '0';
		if(digit >=5){
			digit = 9 - digit;
			A[i] = digit +'0';
		}
	}
	cout<< A;
	return 0;
}
