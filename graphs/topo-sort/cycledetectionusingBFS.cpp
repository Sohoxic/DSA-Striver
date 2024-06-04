// Kahn's algorithm

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	//Function to return list containing vertices in Topological order.
	bool topoSort(int V, vector<int> adj[])
	{
		
        int indegree[V] = {0};
        for(int node=0; node<V; node++){
            for(auto it: adj[node]){
                indegree[it]++;
            }
        }

        int cnt = 0;
        queue<int> q;
        for(int i=0; i<V; i++){
            if(indegree[i] == 0){
                q.push(i);
            }
        }

        while(!q.empty()){
            int node = q.front();
            q.pop();
            cnt++;

            for(auto it: adj[node]){
                indegree[it]--;
                if(indegree[it] == 0 )  q.push(it);
            }
        }

        if(cnt == V) return false;
        return true;
	}
};


int main() {

	//V = 6;
	vector<int> adj[6] = {{}, {}, {3}, {1}, {0, 1}, {0, 2}};
	int V = 6;
	Solution obj;
	bool ans = obj.topoSort(V, adj);

	cout<<"Cycle is "<< ans;
	cout << endl;

	return 0;
}
