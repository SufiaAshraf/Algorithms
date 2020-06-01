#include<iostream>
#include<vector>
#include<queue>
#include<bits/stdc++.h>
using namespace std;

#define ll long long int

ll rocketdist(ll x, ll y){
    return(abs(x*x)+ abs(y*y)) ;
}

int main(){
   ll k, x, y, q, type;
   priority_queue<ll> pq;
   cin>>q>> k;
   for(ll i=0; i<q; i++){
       cin>> type;
       if(type == 1){
           cin>> x>> y;
           if(pq.size() == k){
               if(rocketdist(x, y) < pq.top()){
                   pq.pop();
                   pq.push(rocketdist(x,y));
               }
           }else{
               pq.push(rocketdist(x, y));
           }
       }
       else{
           cout<<pq.top()<<endl;
       }
   }
   return 0;
}