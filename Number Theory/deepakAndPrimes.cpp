#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int p[100000001];

void primeSieve(){
    for(int i=2; i*i<=100000001; i++){
        if(p[i]){
            for(int j=2*i; j<=100000001; j+=i){
                p[j] = 0;
            }
        }

    }
	return;
}

int main() {
	fill(p, p+100000001, 1);
	primeSieve();
	 int count[100000001+1];
	 int k=0;
		for( int i=2; i<100000001; i++){
			if(p[i]){
				count[k++] = i;
			}
		}
		int n;
		cin>>n;
		cout<< count[n-1]<<endl;
	return 0;
}