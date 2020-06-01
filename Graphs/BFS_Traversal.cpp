#include<iostream>
#include<bits/stdc++.h>
#include<list>
#include<map>
#include<queue>
using namespace std;
template<typename T>;
class Graph{
    map<T, list<T>> adjList; 
public:
    Graph(){
        
    }

    void addEdge(T u, T v, bool bidir=true){
        adjList[u].push_back(v);
        if(bidir){
            adjList[v].push_back(u);
        }
    }
    void printList(){
        for(auto i: adjList){
            cout<< i.first<<"-> ";
            for(T entry:i.second){
                cout<<entry<<", "
            }
            cout<<endl;
        }
    }
    void bfs(T src){
        queue<T> q;
        map<T, bool> visited;
        q.push(src);
        visited[src] = true;
        while(!q.empty()){
            T node = q.front();
            cout<< node <<" ";
            q.pop();
            // For the neighbours og the current node not vivsted yet
            for(int neighbour : adjList[node]){
                if(!visited[neighbour]){
                    q.push(neighbour);
                    visited[neighbour] = true;
                }
            }
        }
    }
    void bfs2(T src){
        queue<T> q;
        map<T, int> dist;
        map<T, T> parent;
        for(auto i:adjList){
            dist[i.first] = INT_MAX;
        }
        q.push(src);
        dist[src] = 0;
        parent[src] = src;
        while(!q.empty()){
            T node = q.front();
            cout<< node <<" ";
            q.pop();
            // For the neighbours og the current node not vivsted yet
            for(int neighbour : adjList[node]){
                if(dist[neighbour] == INT_MAX){
                    q.push(neighbour);
                    dist[neighbour] = dist[node]+1;
                    parent[neighbour] = node;
                }
            }
        }
        for(auto i:adjList){
            T node = i.first;
            cout<< "Dist of "<<node<<" from"<<src <<" is"<<dist[node]<<endl;
        }
    }
};

int main(){
    // Graph has 5 vertices
   
    int t;cin>>t;
    while(t--){
         Graph<int> g;
        int n;
        int m;
        cin>> n>> m;
        while(m--){
            int u, v;
            cin>>u>>v;
            g.addEdge(u, v, false);
        }
        int src;
        cin>> src;
        g.bfs(src);

    }
    // g.addEdge("Putin", "Trump",false);
    // g.addEdge("Putin", "Modi",false);
    // g.addEdge("Putin", "Pope",false);
    // g.addEdge("Modi", "Trump",true);
    // g.addEdge("Modi", "Yogi",true);
    // g.addEdge("Yogi", "Prabhu",false); 
    //  g.addEdge("Prabhu", "Modi",false); 
    // g.bfs("Putin");
return 0;
}