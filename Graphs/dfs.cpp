#include<iostream>
#include<bits/stdc++.h>
#include<list>
#include<map>
#include<queue>
using namespace std;
template<typename T>
class Graph{
    map<T, list<T>> l; 
public:
    void addEdge(int u, int v){
        l[u].push_back(v);
        l[v].push_back(u);
    }

    void dfs_helper(T src, map<T, bool> &visited){
        // Rec Function that will traverse
        cout<< src<<" ";
        visited[src] = true;
        // go to ANY neighbou
        for(T nbr: l[src]){
            if(!visited[nbr]){
                dfs_helper(nbr, visited);
            }
        }
    }
    void dfs(T src){
        map<T, bool> visited;
        // mark all nodes as not visited in the beginning
        for(auto p:l){
            T node = p.first;
            visited[node] = false;
            // dfs_helper(node, visited);
        }
        // call helper
       
         int cnt =0;// Iterate over all vertices and initiate a dfs call
        for(auto p:l){
            T node = p.first;
           
            if(!visited[node]){
                cout<< "Component"<< cnt<<"--> ";
                dfs_helper(node, visited);
                cnt++;
                cout<<endl;
            }
        }
    }

};

int main(){
    // Graph has 5 vertices
    Graph<int> g;
    g.addEdge(0,1);
    g.addEdge(1,2);
    g.addEdge(2,3);
    g.addEdge(3,4);
    g.addEdge(3,0);

    g.addEdge(5,6) ;
    g.addEdge(6,7);
    g.addEdge(8,8 );
    g.dfs(0);
return 0;
}