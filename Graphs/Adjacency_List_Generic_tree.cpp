#include<iostream>
#include<list>
#include<map>
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
};

int main(){
    // Graph has 5 vertices
    Graph<string> g;
    g.addEdge("Putin", "Trump",false);
    g.addEdge("Putin", "Modi",false);
    g.addEdge("Putin", "Pope",false);
    g.addEdge("Modi", "Trump",true);
    g.addEdge("Modi", "Yogi",true);
    g.addEdge("Yogi", "Prabhu",false); 
     g.addEdge("Prabhu", "Modi",false); 
    g.printList();
return 0;
}