#include <iostream>
#include <algorithm>
using namespace std;

#define ll long long int

bool sufficient(ll A[] ,ll n, ll k, ll ans){
        ll curr_sum , painter = 1;
        for(ll i=0; i<n; i++){
           curr_sum += A[i];
           if(curr_sum>ans){
               curr_sum = A[i];
               painter++;
           }
        }
        if(painter<=k){
            return true;
        }else{
            return false;
        }    
}

ll binarySearch(ll A[], ll n, ll k, ll t, ll s, ll e){
    ll finalAns = s;
    while(s<=e){
        ll mid = (s+e)/2;
        if(sufficient(A, n, k, mid)){
            finalAns = mid;
            e= mid - 1;
           
        }else {
            s = mid+1;
        }
    }
    return finalAns;
}

int main(){
    ll n, k, t;
    cin>>n>>k>>t;
    ll A[n];
    ll total = 0;
    ll maximum = 0;
    for(ll i=0; i<n; i++){
        cin>> A[i];
        total+=A[i];
        maximum = max(maximum, A[i]);
    }
    ll s, e;
    s =maximum;
    e = total;
         ll ans = binarySearch(A, n, k, t, s ,e)*t;
        cout<< ans % 10000003;
}