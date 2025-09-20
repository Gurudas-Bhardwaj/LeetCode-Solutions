#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Function to run Floyd-Warshall algorithm
    vector<vector<int>> floydWarshall(int n, vector<vector<int>>& graph) {
        
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(graph[i][j] == -1)
                    graph[i][j] = INT_MAX;
            }
        }

        for(int k=0; k<n; k++){
            for(int i=0; i<n; i++){
                for(int j=0; j<n; j++){
                    if(graph[i][k] == INT_MAX || graph[k][j] == INT_MAX)
                        continue;
                    graph[i][j] = min(graph[i][j], graph[i][k] + graph[k][j]);
                }
            }
        }


        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(graph[i][j] == INT_MAX)
                    graph[i][j] = -1;
            }
        }


        return graph; 
    }
};

int main() {
    int n = 5;
    vector<vector<int>> graph = {
        {0,   5,   9,  -1, -1},
        {5,   0,   2,   3, -1},
        {9,   2,   0,   6, -1},
        {-1,  3,   6,   0,  7},
        {-1, -1,  -1,   7,  0}
    };

    Solution sol;
    vector<vector<int>> result = sol.floydWarshall(n, graph);

    cout << "Shortest distance matrix:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << result[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
