#include<iostream>
#include<list>
#include<queue>
using namespace std;

class Graph{
    int V;
    map<int, list<int> > adj;
public:
    Graph(int V){
        this->V;
    }

    void addEdge(int u, int v, bool bidir = true){
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    void bfs(int src){
        queue<int> q;
        map<int, bool> visited
        q.push(src);
        visited[src] = true;
        while(!q.empty()){
            int node = q.front();
            cout<< node<<" ";
            q.pop();
            for(int nbr: adj[node]){
                if(!visited[nbr]){
                    q.push(nbr);
                    visited[nbr] = true;
                }
            }
        }
    }
};

int main(){

}
