#include <bits/stdc++.h>
using namespace std;

bool isBicolorable(int n, vector<vector<int>>& adj) {
    vector<int> color(n, -1); // -1 means uncolored
    queue<int> q;
    
    q.push(0);  // Start BFS from node 0
    color[0] = 0;  // Assign first color
    
    while (!q.empty()) {
        int u = q.front();
        q.pop();

        for (int v : adj[u]) {
            if (color[v] == -1) { // If uncolored, assign opposite color
                color[v] = color[u] ^ 1;
                q.push(v);
            } else if (color[v] == color[u]) { // Conflict found
                return false;
            }
        }
    }
    return true;
}

int main() {
    while (true) {
        int n, l;
        cin >> n;
        if (n == 0) break; // Termination condition
        
        cin >> l;
        vector<vector<int>> adj(n);

        for (int i = 0; i < l; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        if (isBicolorable(n, adj)) {
            cout << "BICOLORABLE.\n";
        } else {
            cout << "NOT BICOLORABLE.\n";
        }
    }
    return 0;
}
