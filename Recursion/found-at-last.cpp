#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int lastIndex(int* a, int n, int m, int i){
    if(i==0 && a[i] != m ){
        return -1;
    }
    if(a[i] == m ){
       return i;
       lastIndex(a, n, m, i-1);
    }else{
       return lastIndex(a, n, m, i-1);
    }
  
}

int main() {
    int n;
    cin>>n;
    int a[n];
    for(int i=0; i<n; i++){
        cin>> a[i];
    }
    int m;
    cin>>m;
    cout<< lastIndex(a, n, m, n-1);
	return 0;
}