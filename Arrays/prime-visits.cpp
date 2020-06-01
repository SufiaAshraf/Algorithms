#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin>> t;
	while(t--){
		int a, b;
		cin>> a>> b;
		bool prime[b+1];
		prime[0] = 0;
		prime[1] = 0;
			for(int i=2; i<b; i++){
				if((!(i&1)) || i<a){
					prime[i] = 0;
				}else {
					prime[i] = 1;
				}
			}
			if(2>=a){
				prime[2] = 1;
			}
			for(int i=3; i<b; i+=2){
				int j=2;
				while(i*j <= b){
					prime[i*j] = 0;
					j++;
				}
			}
			int count = 0;
			for(int i=0; i<b; i++){
				if(prime[i]){
					count++;
				}
			}
			cout<<count<<endl;
	}
	return 0;
}