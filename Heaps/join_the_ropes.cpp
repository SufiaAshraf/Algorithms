#include<iostream>
#include<queue>
#include<vector>
using namespace std;
int ConnectRopesWithMinCost(int *ropes, int n){
    priority_queue<int, vector<int> , greater<int> > pq(ropes, ropes+n);
    int cost = 0;
    while(pq.size()>1){
        int first = pq.top();
        pq.pop();
        int second = pq.top();
        pq.pop();
        cost+= first+second;
        pq.push(first+second);
    }
    return cost;
}


int main(){
   int ropes[100];
    int n;
    cin>>n;
    for(int i=0; i<n; i++){
       cin>> ropes[i];
    }
    cout<< ConnectRopesWithMinCost(ropes, n);
    return 0;
}