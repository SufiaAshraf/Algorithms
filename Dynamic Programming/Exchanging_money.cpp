#include<iostream>
#include<unordered_map>
#define ll long long int
using namespace std;
ll solve(ll n,unordered_map<ll ,ll >&dp)
{
	if(dp.count(n))
		return dp[n];
	if(n<12)
	{
		dp[n]=n;
		return dp[n];
	}
	dp[n]=max(n,solve(n/2,dp)+solve(n/3,dp)+solve(n/4,dp));
	return dp[n];
}

int main()
{
	ll n;
	cin>>n;
	unordered_map<ll,ll>dp;
	cout<<solve(n,dp);
}