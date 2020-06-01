#include <bits/stdc++.h>
#define C 1000000007
using namespace std;

long long tiling_ways(int N,int M)
{
    long long count[N+1];
    count[0]=count[1]=1;
    for(int i=2;i<=N;i++)
        if(i>=M)
            count[i]=(count[i-1]+count[i-M])%C;
        else
            count[i]=count[i-1];
    return count[N];
}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int N,M;
        cin>>N>>M;
        cout<<tiling_ways(N,M)<<endl;
    }
}