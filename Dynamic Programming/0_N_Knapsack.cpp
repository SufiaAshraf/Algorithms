#include<iostream>
#include<climits>
using namespace std;
#define ll long long int
ll knapsack(int N, int cap, int* wt, int* val){
	ll dp[cap+1]={0};
	for(int i=0; i<=cap;i++){
		for(int j=0; j<N; j++){
			if(wt[j]<=i){
				dp[i] = max(dp[i], dp[i-wt[j]]+val[j]);
			}
		}
	}
	return dp[cap];
}

int main() {
	int N, cap;
	cin>> N>>cap;
	int wt[N], val[N];
	for(int i=0; i<N; i++){
		cin>> wt[i];
	}
	for(int j=0; j<N; j++){
		cin>> val[j];
	}
	cout<< knapsack(N,cap,wt, val)<<endl;
	return 0;
}
