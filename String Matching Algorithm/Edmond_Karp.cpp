#include<bits/stdc++.h>
#include<queue>
using namespace std;

bool bfs(int **residualCapacity, int src, int sink, int n, int *parent){
    bool visited[n]={0};
    queue<int> q;
    visited[src] = true;
    q.push(src);
    bool foundAugmentedPath = false;
    while (!q.empty()){
       int u = q.front();
       q.pop();
       for(int v=0; v<n; v++){
           if(!visited[v] && residualCapacity[u][v]>0){
               parent[v] = u;
               visited[v] = true;
               q.push(v);
               if(v==sink){
                   foundAugmentedPath = true;
                   break;
               }
           }
       }
    }
    return foundAugmentedPath; 
}

void printAugmented(vector<vector<int> > augmentedPath){
    for(int i=0; i<augmentedPath.size(); i++){
        for(int j=0; j<augmentedPath[i].size(); j++){
            cout<<augmentedPath[i][j]<<", ";
        }
        cout<<endl;
    }
}

int max_flow(int **capacity, int src, int sink, int v){
    int **residualCapacity = new int*[v];
    for(int i=0; i<v; i++){
        residualCapacity[i] = new int[v];
    }
    for(int i=0; i<v; i++){
        for(int j=0; j<v; j++){
            residualCapacity[i][j] = capacity[i][j];
        }
    }
    int *parent = new int[1000];
    vector<vector<int>> augmentedPath;
    int maxFlow = 0;
    while(bfs(residualCapacity, src, sink, v, parent)){
        vector<int> currentAugmnented;
        int flow = INT_MAX;
        int v = sink;
        while(v!=src){
            currentAugmnented.push_back(v);
            int u = parent[v];
            if(flow > residualCapacity[u][v]){
                flow = residualCapacity[u][v];
            }
          v=u;
        }
        currentAugmnented.push_back(src);
        std::reverse(currentAugmnented.begin(), currentAugmnented.end());
        augmentedPath.push_back(currentAugmnented);
        maxFlow += flow;

        v= sink;
        while(v!=src){
            int u= parent[v];
            residualCapacity[u][v] -=flow;
            residualCapacity[v][u] +=flow;
            v=u;
        }
    }
    printAugmented(augmentedPath);
    return maxFlow;
}

int main(){
    int v,e;
    cin>>v>>e;
    int **capacity = new int*[v];
    for(int i=0; i<v; i++){
        capacity[i] = new int[v];
    }
    for(int i=0; i<e; i++){
        int u,v,c;
        cin>>u>>v>>c;
        capacity[u][v] = c;
    }
    cout<<max_flow(capacity, 0, 1, v);
}