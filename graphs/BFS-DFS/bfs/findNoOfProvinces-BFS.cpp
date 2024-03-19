#include<bits/stdc++.h>
using namespace std;

int findNumOfProvinces(vector<vector<int>>& roads, int n) {
    vector<int> visited(n, 0);
    int count = 0;
    queue<int> bfsQ;

    for (int i = 0; i < n; i++) {
        // If city 'i' is unvisited then mark all cities connected to it as visited using BFS traversal.
        if (!visited[i]) {
            visited[i] = 1;
            bfsQ.push(i);

            while (!bfsQ.empty()) {
                int v = bfsQ.front();
                bfsQ.pop();
                for (int j = 0; j < n; j++) {
                    if (roads[v][j] && !visited[j]) {
                        visited[j] = 1;
                        bfsQ.push(j);
                    }
                }
            }
            // Increase 'COUNT' for each BFS traversal.
            count++;  
        }
    }

    return count;
}
