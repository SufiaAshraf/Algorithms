#include<bits/stdc++.h>
using namespace std;
#define ll long long int
vector<int> adj[200000];
int child_count[100000];
int visited[123456];
ll happy =0;
vector<int> master;
set<int> s;
int node, edge;

void dfs(int x){
    visited[x] = -1;
    for(int i=0; i<adj[x].size();i++){
        if(!visited[adj[x][i]]){
            dfs(adj[x][i]);
        }
    }
    visited[x] =1;
    s.insert(x);
}

void dfs2(int x, int y){
    visited[x]=-1;
    for(int i=0; i<adj[x].size(); i++){
        if(!visited[adj[x][i]]){
            dfs2(adj[x][i], x);
        }
    }
    visited[x] = 1;
    if(x!=y){
        if(child_count[x]>child_count[y]){
            happy++;
        }
    }
}

int main(){
    cin>>node>>edge;
    for(int i=1; i<=edge; i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
        child_count[u]++;
        child_count[v]++;
    }
    for(int i=1; i<=node; i++){
        visited[i] = 0;
    }
    for(int i=1; i<=node; i++){
        if(!visited[i]){
            dfs(i);
            master.push_back(*s.begin());
            s.erase(s.begin(),s.end());
        }
    }

    for(int i=1; i<=node; i++){
        vector<int>::iterator it;
        it=find(master.begin(),master.end(),i);
        if(it==master.end()){
            child_count[i]--;
        }
    }
    for(int i=1; i<=node; i++){
        visited[i] = 0;
    }
    for(int i=0; i<master.size(); i++){
        if(!visited[master[i]]){
            dfs2(master[i],master[i]);
        }
    }
    cout<<happy<<endl;
}

































// #include<iostream>
// #include<map>
// #include<queue>
// #include<list>
// using namespace std;
// int n,m;
// map<int, bool> beautiful;
// class Graph{

//     int V;
//     // Map will contain pair of node and list of nodes it is connected to and integer value denoting the count of children of that node
//     map<int, list<int>> m;
//     map<int, int> children;
//     map<int, int> parent;
// public:
//     Graph(int n){
//         this->V = n;
//     }
//     void addEdge(int x, int y){
//         m[x].push_back(y);
//         m[y].push_back(x);
//     }
//    void countchild(int src){
//         for(int i=1; i<=n; i++){
//             int count = 0;
//             for(auto nbr: m[i]){
//                 count++;
//                 children[i] = count; 
//             }
//         }
//         queue<int> q;
//         q.push(src);
//         parent[src] = src;
//         map<int, bool> visited;
//         visited[src] = true;
//         while(!q.empty()){
//             int node = q.front();
//             q.pop();
//             for(auto nbr: m[node]){
//                 if(!visited[nbr]){
//                     q.push(nbr);
//                     visited[nbr]= true;
//                     parent[nbr] = node;
//                 }
//             }
//         }
//         //  for(auto i:parent){
//         //     cout<< i.first<<"->"<<i.second<<endl;
//         // }
//         // cout<<endl;
          
//     }
   

//     void beautifulVertices(){
//         int master_parent = 0;
//         for(int i=1; i<=n; i++){
//             if(parent[i] == i){
//                 master_parent = i;
//             }
//         }
//         queue<int> q;
//         q.push(master_parent);
//         map<int, bool> visited;
//         visited[master_parent] = true;
//         while(!q.empty()){
//             int node = q.front();
//             q.pop();
//             int current_children = children[node];
//             for(auto p:m[node]){
//                 if(!visited[p]){
//                     q.push(p);
//                     visited[p] = true;
//                     if(children[p]>current_children){
//                     beautiful[p] = true;
//                     }
//                 }
//             }
//         }    
//     }
    

//     void printChild(){
       
//         // for(auto i:children){
//         //     cout<<i.first<<"->"<<i.second<<endl;
//         // }
//         // cout<<endl;
//     }

// };


// int main(){
//     cin>>n>>m;
//     Graph g(n);
//     while(m--){
//         int x, y;
//         cin>>x>>y;
//         g.addEdge(x,y);
//     }
//     g.countchild(1);
//     g.beautifulVertices();
//         // g.printChild();
//     int cnt=0;
//     for(int i=1; i<=n; i++){
//         if(beautiful[i]){
//             cnt++;
//         }
//     }
//     cout<<cnt<<endl;
// }