#include<iostream>
#include<bits/stdc++.h>
#include<map>
#include<list>
using namespace std;

template<typename T>
class Graph{
    unordered_map<T, list<pair <T, int> > > m;
public:
    void addEdge(T u, T v, int dist, bool bidir=true){
        m[u].push_back(make_pair(v, dist));
        if(bidir){
            m[v].push_back(make_pair(u, dist));
        }
    }
    void printAdj(){
        // Let's print adjcency list
        // iterate over a ll key value pairs

        for(auto j:m){
            cout<< j.first<<"-->";
            // Iterate over the lis of cities
            for(auto l:j.secoond){
                cout<<"("<< l.first<<","<<l.second<<")";
            }
            cout<< endl;
        }
    }
    void dijsktraSSSP(T src){
        unordered_map<T, int> dist;
        // Set all distances to infinity
        for(auto j:m){
            dist[j.first] = INT_MAX;
        }
        // Make a set to find out node with minimum dist
        set<pair<int , T>> s;
        dist[src] =0;
        s.insert(make_pair(0,src));
        while(!s.empty()){
            // Find the pair at the front.
            auto p = *(s.begin());
            T node = p.second;
            int nodeDist = p.first;
            s.erase(s.begin());
            // Iterate over neighbours/children of the current node
            for(auto childPair: m[node]){
                if(nodeDist + childPair.second < dist[childPair.first]){
                    // In the set updation is not possible
                    // We have to remove the old pair, and insert the new pair to simulation updation
                    T dest = childPair.first;
                    auto f = s.find(make_pair(dist[dest],dest));
                    if(f!=s.end()){
                        s.erase(f);
                    }
                    // Insert new pair
                    dist[dest] = nodeDist + childPair.second;
                    s.insert(make_pair(dist[dest],dest));
                }
            }
        }
        // Let's print distance to all other node from src
        for(auto d:dist){
            cout<< d.first<<"is located at a distance of "<< d.second<< " from source"<< endl;
        }
    }
};
int main(){
    Graph<int> g;
    g.addEdge(1, 2, 1);
    g.addEdge(1, 3, 4);
    g.addEdge(2, 3, 1);
    g.addEdge(3, 4, 2);
    g.addEdge(1, 4, 7);
    g.printAdj();
    g.dijsktraSSSP(1);
    cout<< endl;
    Graph<string> India;
    India.addEdge("Amritsar", "Delhi", 1);
    India.addEdge("Amritsar", "Jaipur", 4);
    India.addEdge("Jaipur", "Delhi", 2);
    India.addEdge("Jaipur", "Mumbai", 8);
    India.addEdge("Bhopal", "Agra", 2);
    India.addEdge("Mumbai", "Bhopal", 3);
    India.addEdge("Agra", "Delhi", 8);
    // India.dijsktraSSSP("Amritsar");
    India.printAdj()
}