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
    void addEdge(T u, T v){
        l[u].push_back(v);
        // l[v].push_back(u);
    }

    void dfs_helper(T src, map<T, bool> &visited, list<T> &ordering){
        // Rec Function that will traverse
        // cout<< src<<" ";
        visited[src] = true;
        // go to ANY neighbou
        for(T nbr: l[src]){
            if(!visited[nbr]){
                dfs_helper(nbr, visited, ordering);
            }
        }
        ordering.push_front(src);
        return;
    }
    void dfs(){
        map<T, bool> visited;
        list<T> ordering;
        // mark all nodes as not visited in the beginning
        for(auto p:l){
            T node = p.first;
            visited[node] = false;
        }
        // Call Helper
        for(auto p:l){
            T node = p.first;
            if(!visited[node]){
                dfs_helper(node, visited, ordering);
            }
        }
        for(auto node:ordering){
            cout<< node<< endl;
        }
    }

};

int main(){
    // Graph has 5 vertices
    Graph<string> g;
    g.addEdge("Python","DataPerProcessing");
    g.addEdge("Python","pyTorch");
    g.addEdge("DataPerProcessing", "ML");
    g.addEdge("pyTorch","DL");
    g.addEdge("ML","DL");

    g.addEdge("DL","Facerecogn");
    g.addEdge("DataSet","Facerecogn");
    g.dfs();
return 0;
}