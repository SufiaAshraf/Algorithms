#include<iostream>
#include<list>
#include<map>
#include<queue>
#include<unordered_set>
using namespace std;
template<typename T>
class Graph{
    
public:
	map<T, list<T>> adjList;
    Graph(){

    }
    void addEdge(T u, T v, bool bidir = true){
        adjList[u].push_back(v);
        if(bidir){
            adjList[v].push_back(u);
        }
    }
    
    map<T, T> bfs(T src){
        queue<T>q;
        map<T, int> dist;
        map<T, T> parent;

        dist[src] = 0;
        unordered_set<T> mark;
        parent[src] = src;
        q.push(src);
        mark.insert(src);

        while(!q.empty()){
            T node = q.front();
            q.pop();

            for(T neighbour: adjList[node]){
                if(!mark.count(neighbour)){
                    q.push(neighbour);
                    mark.insert(neighbour);
                    dist[neighbour] = dist[node]+1;
                    parent[neighbour] = node;
                }
            }
        }
        return dist;
    }
};

int main(){
    int q;
    cin>>q;
    while(q--){
        int n, m;
        cin>>n>>m;
        Graph<int> G;
        for(int i=0; i<m; i++){
            int u, v;
            cin>>u>>v;
            G.addEdge(u, v);
        }
        int src;
        cin>>src;
        map<int, int> dist;
        dist = G.bfs(src);
        for(int i=1; i<=n; i++){
            if(i==src){
                continue;
            }

            if(!dist.count(i)){
                cout<<"-1"<<" ";
            }else{
                cout<<dist[i]*6<<" ";
            }
        }
        cout<<endl;
    }
}