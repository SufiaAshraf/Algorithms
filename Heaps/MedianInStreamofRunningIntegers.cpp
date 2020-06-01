#include<iostream>
#include<bits/stdc++.h>
#include<vector>
#include<queue>
using namespace std;

void printMedians(double arr[], int n){
    priority_queue<double> max_heap;
    priority_queue<double, vector<double>, greater<double>> min_heap;

    double median = arr[0];
    max_heap.push(arr[0]);
    cout<< median<<" ";
    for(int i=1; i<n; i++){
        double x = arr[i];

        if(max_heap.size() > min_heap.size()){
            if(x <= median){
                min_heap.push(max_heap.top());
                max_heap.pop();
                max_heap.push(x);
            }else{
                min_heap.push(x);
            }
            median = (max_heap.top() + min_heap.top()) /2.0;
        }else if(max_heap.size() == min_heap.size()){
            if(x<=median){
                max_heap.push(x);
                median = (double) max_heap.top();
            }else{
                min_heap.push(x);
                median = (double) min_heap.top();
            }
        }
        else{
            if(x>=median){
                max_heap.push(min_heap.top());
                min_heap.pop();
                min_heap.push(x);
            }else{
                max_heap.push(x);
            }
            median = (max_heap.top() + min_heap.top()) /2.0;
        }
        cout<<median<<" ";
    }
}

int main(){
    int t;
    cin>> t;
    while(t--){
        int n;
        cin>>n;
        double arr[n];
        for(int i=0; i<n; i++){
            cin>>arr[i];
        }
        printMedians(arr,n);
        cout<<endl;
    }
    return 0;
}