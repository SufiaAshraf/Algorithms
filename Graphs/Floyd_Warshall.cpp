#include<iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define pii pair<int, int>
#define ff first 
#define ss second

vector<vi> all_pair_shortest_dist(int n, vector<vector<pii>> &adj){
    vector<vi> dist(n+1, vector<int>(n+1, 2e9));
    for(int i=1;i<=n; i++){
        dist[i][i] = 0;
        for(pii ed: adj[i]){
            int nb = ed.ff;
            int w = ed.ss;
            dist[i][nb] = w;
        }
    }
    for(int k=1; k<=n; k++){
        for(int i=1; i<=n; i++){
            for(int j=1; j<=n; j++){
                dist[i][j] = min(dist[i][j], dist[i][k]+dist[k][j]);
            }
        }
    }
    return dist; 
}


int main(){

}