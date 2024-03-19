#include <bits/stdc++.h>
using namespace std;

class Solution {
  private: 
    void dfs(int node, vector<int> adjLs[], int vis[]) {
        vis[node] = 1; 
        for(auto it: adjLs[node]) {
            if(!vis[it]) {
                dfs(it, adjLs, vis); 
            }
        }
    }
  public:
    int numProvinces(vector<vector<int>> adj, int V) {
        int count  = 0;
        vector<int> adjls[V];
        for(int i=0; i<V; i++){
            for(int j=0; j<V; j++){
                if(adj[i][j]==1 && i!=j){
                    adjls[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }

        // for(int i=0; i<V; i++){
        //     cout<<i<<"-> ";
        //     for(auto i: adjls[i]){
        //         cout<<i<<" ";
        //     }
        //     cout<<endl;
        // }

        // return 0;

        int vis[V] = {0}; 
        int cnt = 0; 

        for(int i = 0;i<V;i++) {
            // if the node is not visited
            if(!vis[i]) {
                // counter to count the number of provinces 
                cnt++;
               dfs(i, adjls, vis); 
            }
        }
        return cnt;
    }
};

int main() {
    
    vector<vector<int>> adj
    {
        {1, 0, 1},
        {0, 1, 0},
        {1, 0, 1}
    };

        
    Solution ob;
    cout << ob.numProvinces(adj,3) << endl;
        
    return 0;
}