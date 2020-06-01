#include<iostream>
#include<map>
#include<list>
#include<set>
#include<bits/stdc++.h>
using namespace std;

class Graph{
    int V;
    map<int, list<pair<int, int>>> m;
public:
    Graph(int V){
        this->V = V;
    }
    void addEdge(int u, int v, int dist, bool bidir=true){
        m[u].push_back(make_pair(v,dist));
        if(bidir){
            m[v].push_back(make_pair(u,dist));
        }
    }
    void dijkstra(int src,int n){
        map<int, int> dist;
        for(int j=1; j<=n; j++){
            dist[j] = INT_MAX;
        }

        set<pair<int,int>> s;
        dist[src] = 0;
        s.insert(make_pair(0,src));
        while(!s.empty()){
            auto p = *(s.begin());
            int node = p.second;
            int nodeDist = p.first;
            s.erase(s.begin());
            for(auto childPair: m[node]){
                if(nodeDist+childPair.second < dist[childPair.first]){
                    int dest = childPair.first;
                    auto f = s.find(make_pair(dist[dest],dest));
                    if(f!=s.end()){
                        s.erase(f);
                    }
                    dist[dest] = nodeDist+childPair.second;
                    s.insert(make_pair(dist[dest],dest));
                }

            }
        }
        for(int i=1; i<=n; i++){
            if(dist[i] == INT_MAX){
                cout<<"-1"<<" ";
            }
            else if(dist[i]!=0){
                cout<<dist[i]<<" ";
            } 
        }
    
    }
};


int main(){
    int t;
    cin>>t;
    while(t--){
        int n,m;
        cin>>n>>m;
        Graph g(n);
        for(int i=0; i<m; i++){
            int s,e,dist;
            cin>>s>>e>>dist;
            g.addEdge(s,e,dist);
        }
        int src;
        cin>>src;
        g.dijkstra(src,n);
        cout<<endl;
    }
}