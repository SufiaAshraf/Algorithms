#include<iostream>
#include<vector>
using namespace std;

class Graph{
public: 
    void dsu(){
        vector<int> par, sz;
        // initialize
        int total_comp;
        void init(int n){
            par.resize(n);
            sz.resize(n);
            for(int i=0; i<n; i++){
                par[i] = i;
            }
            for(int i=0; i<n; i++){
                sz[i] = 1;
            }
            total_comp = n;
        }
        int get_superparent(int x){
            if(x==par[x]){
                return x;
            }else{
            // Path Compression
                return par[x] = get_superparent(par[x]);
            }
    }

    void unite(int x, int y){
        int super_parent_x = get_superparent(x);
        int super_parent_y = get_superparent(y);
        if(super_parent_x != super_parent_y){
            par[super_parent_x] = super_parent_y;
            sz[super_parent_y]+=sz[super_parent_x];
            sz[super_parent_x] = 0;
            total_comp--;
        }
    }
};

void solve(){
    int i , j, k , n, m, ans=0, cnt = 0, sum =0;
    cin>> n>> m;
    G.init(n);
    for(i=0; i<m; i++){
        int x, int y;
        cin>> x>> y;
        G.unite(x, y);
    }
    // all elements are in there connected components
    for(i=0; i<n; i++){
        // i is considered as x
        int super_parent_i = G.get_superparent(i);
        ans+=(n-G.sz[super_parent_i]);
    }
    cout<< ans/2;
}


int main(){
    Graph g;
    
    

}