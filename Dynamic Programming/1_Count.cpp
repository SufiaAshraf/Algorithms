#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void maxLength(int* a, int n, int k){
    int left =0;
    int zero_count =0;
    int max_length =0;
	int length =0;
	int left_Index;
    for(int i=0; i<n; i++){
        if(a[i] == 0){
            zero_count++;
        }
        while(zero_count>k){
            if(a[left] == 0){
                zero_count--;
            }
			left++;
        }	
		length = i-left+1;
		if(length >max_length){
			max_length = length;
			left_Index=left;
		}
    }
    cout<< max_length<<endl;
	for(int i=0; i<left_Index; i++){
		cout<<a[i]<<" ";
	}
	for(int i=left_Index; i<left_Index+max_length; i++){
		cout<< "1"<<" ";
	}
	for(int i=left_Index+max_length; i<n; i++){
		cout<< a[i]<<" ";
	}
}

int main(){
    int n;
    cin>> n;
	int k;
    cin>> k;
    int a[n];
    for(int i=0; i<n; i++){
        cin>> a[i];
    }
    maxLength(a, n, k);
}