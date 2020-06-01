#include<iostream>
#include<bits/stdc++.h>
#include<list>
#include<map>
#include<queue>
#include<cstring>
using namespace std;

class Graph{
    list<int> *l;
    int V;
public:
    Graph(int v){
        this->V = v;
        l = new list<int>[V];
    }

    void addEdge(int x, int y, bool directed = true){
        // directed graph
        l[x].push_back(y);
        if(!directed){
            l[y].push_back(x);
        }    
    }
    
    bool cycle_helper(int node, bool* visited, bool* stack){
        // Visit a node
        visited[node] = true;
        stack[node] = true;

        for(int nbr: l[node])   {
            // two cases
            if(stack[nbr]){
                return true;
            }
            else if(!visited[nbr]){
                bool cycle = cycle_helper(nbr, visited, stack);
                if(cycle){
                    return true;
                }
            }
            
        }
        // leave a node
        stack[node] = false;
        return false;
    }

    bool contains_cycle(){
        // Check for cycle in dorected graph
        bool *visited = new bool[V];
        bool *stack = new bool[V];
        for(int i=0; i<V; i++){
            visited[i] = stack[i] = false;
        }
        return cycle_helper(0, visited, stack);
    }
};



int main(){
    Graph g(7);

    g.addEdge(0,1);
    g.addEdge(1,2);
    g.addEdge(2,3);
    g.addEdge(3,4);
    g.addEdge(4,5);
    g.addEdge(1,5);
    g.addEdge(5,6);
    // Back Edge
    // g.addEdge(4,2);    
    if(g.contains_cycle()){
        cout<< "Yes";
    }else{
        cout<<"No";
    }
}