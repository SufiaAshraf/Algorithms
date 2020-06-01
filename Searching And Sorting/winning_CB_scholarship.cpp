#include<iostream>
#include<bits/stdc++.h>
using namespace std;

#define ll long long int

bool validNoofstudents(ll n, ll m,ll x,ll y,ll ans){
	ll q = (n-ans)*y;
	ll C = m+q;
	if(C>=ans*x){
		return true;
	}else {
		return false;
	}
}


int main() {
	ll n, m, x, y;
	cin>> n>>m>>x>>y;
	ll ans = 0;
	ll s = 0;
	ll e = n;

	while(s<=e){
		ll mid = (s+e)/2;
		if(validNoofstudents(n, m, x, y, mid)){
			s = mid+1;
			ans = mid;
		}else {
			e = mid -1;
		}
		
	}
	cout<< ans<<endl;
	return 0;
}