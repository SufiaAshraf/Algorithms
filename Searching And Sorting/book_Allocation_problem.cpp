#include<iostream>
using namespace std;

#define ll long long int

bool isValidConfig(ll A[] , ll n, ll m, ll ans){
    int student = 1;
    ll currentPages = 0;
    for(int i=0; i<n; i++){
       if(currentPages+A[i] > ans){  
        currentPages = A[i];
        student++;
            if(student>m){
                return false;
            }
       }
       else {
           currentPages += A[i];
       }
    }
    return true;
}


ll binarySearchBooks(ll A[] , ll n, ll m){
    ll total_pages = 0;
    ll s =0;
    ll e = 0;
    for(int i=0; i<n; i++){
        total_pages+= A[i];
        s = max(s, max(s, A[i]));
    }
    e = total_pages;
    ll finalAns = 0;
    while(s<=e){
       ll mid = (s+e)/2; 
       if(isValidConfig(A, n, m, mid)){
           finalAns = mid;
           e = mid-1;
       }else {
           s = mid+1;
       }
    }
    return finalAns;
}


int main(){
    int t;
    cin>>t;
    while(t--){
        ll n;
        cin>> n;
        ll m;
        cin>>m;
        ll A[100005];
        for(int i=0; i<n; i++){
            cin>> A[i];
        }
        cout<< binarySearchBooks(A, n, m)<<endl;
    }
}