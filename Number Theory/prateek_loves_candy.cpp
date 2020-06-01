#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int p[1000000];

void primeSieve(){
    for(int i=2; i*i<=1000000; i++){
        if(p[i]){
            for(int j=2*i; j<=1000000; j+=i){
                p[j] = 0;
            }
        }

    }
	return;
}

int main() {
	int t;
	cin>>t;
	fill(p, p+1000000, 1);
	primeSieve();
	 int count[1000000+1];
	 int k=0;
		for( int i=2; i<1000000; i++){
			if(p[i]){
				count[k++] = i;
			}
		}

	while(t--){
		int a;
		cin>>a;
		cout<< count[a-1]<<endl;
	}
	return 0;
}