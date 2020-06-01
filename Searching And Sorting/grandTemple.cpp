#include<bits/stdc++.h>
#include<algorithm>
using namespace std;
#define ll long long int
int main() {
    ll n;
    cin >> n;
    ll a[n], b[n];
    for(ll i=0; i<n; i++) {
        cin >> a[i] >> b[i];
    }
    sort(a, a + n);
    sort(b, b + n);
    for(ll i=n-1; i>0; i--) {
        a[i] = a[i] - (a[i-1] + 1);
        b[i] = b[i] - (b[i-1] + 1);
    }
    ll x=0, y=0;
    for(ll i=0; i<n; i++) {
        x = max(x, a[i]);
        y = max(y, b[i]);
    }
    cout << x*y << endl;
	return 0;
}