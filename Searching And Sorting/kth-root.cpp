#include<iostream>
#include<math.h>
using namespace std;

#define ll long long int

bool validIntergerX(ll n, ll k, ll ans){
    if(pow(ans, k) <= n)
        return true;
    return false;
}

int main() {
    int t;
    cin>> t;
    while(t--){
            ll n, k;
            cin>> n>> k;
            ll s = 1;
            ll e = n;
            ll mid;
            ll ans = 0;
            while(s<=e){
                mid = (s+e)/2;
                if(validIntergerX(n, k, mid)){
                    ans = mid;
                    s = mid+1;
                }
                else{
                     e = mid -1;
                }
            }
            cout<< ans<< endl;
        }
   
	return 0;
}