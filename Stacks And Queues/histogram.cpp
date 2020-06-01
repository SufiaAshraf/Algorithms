#include <iostream>
#include <stack>
using namespace std;
#define ll  long long int

ll maxAreaHist(ll bar[], ll n){
    stack <ll> s;
    ll curr_Area;
    ll max_Area = 0;
    for(ll i=1; i<n; i++){
        while(!s.empty() && bar[s.top()]>bar[i]){
            int top = s.top();
            s.pop();
            if(s.empty()){
                curr_Area = bar[top]*i;
            }else{
                curr_Area = bar[top]*(i-s.top()-1);
            }
            if(curr_Area>max_Area){
                max_Area = curr_Area;
            }
        }
        s.push(i);
    }
    ll size = s.size();
    while(!s.empty()){
        ll top = s.top();
        s.pop();
        curr_Area = bar[top]*(size-s.size());
        if(curr_Area>max_Area){
                max_Area = curr_Area;
            }
    }
    return max_Area;
}





int main(){
    ll n;
    cin>> n;
    ll bar[n];
    for(int i=0; i<n; i++){
        cin>>bar[i];
    }
    cout<<maxAreaHist(bar, n);
}