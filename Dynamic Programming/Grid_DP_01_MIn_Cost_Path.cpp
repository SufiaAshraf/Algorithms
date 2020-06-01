#include<iostream>
using namespace std;
#define ll long long int

ll cost[100][100];
ll dp[100][100];

int min_cost(int r, int c){
    for(int i=0; i<r; i++){
        for(int j=0; j<c; j++){
            if(i==0 && j==0){
                dp[i][j] = cost[0][0];
            }else if( i ==0 ){
                dp[i][j] = dp[0][j-1] + cost[0][j];
            }else if(j==0){
                dp[i][j] = dp[i-1][0] + cost[i][0];
            }else{
                dp[i][j] = min(dp[i-1][j], dp[i][j-1])+cost[i][j];
            }
        }
    }
    return dp[r-1][c-1];
}

int main(){
    int r, c;
    cin>> r>>c;
    for(int i=0; i<r; i++){
        for(int j=0; j<c; j++){
            cin>> cost[i][j];
        }
    }
    cout<< min_cost(r,c)<<endl;
}