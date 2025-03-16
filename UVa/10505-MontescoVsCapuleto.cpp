#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 205;
vector<int> adj[MAX_N];  // Adjacency list
int color[MAX_N];        // Color array: -1 (unvisited), 0, or 1

// Check if the component is bipartite and return max group size
int bfs(int start,int N) {
    queue<int> q;
    q.push(start);
    color[start] = 0; // Start with color 0

    int count[2] = {1, 0}; // Count nodes in each group
   int flag=0;
    while (!q.empty()) {

        int u = q.front();
        q.pop();

        for (int v : adj[u]) {
            if (color[v] == -1) {  // If not colored, assign opposite color
                color[v] = 1 - color[u];
                count[color[v]]++;
                q.push(v);
            } else if (color[v] == color[u]) {
                flag=1; // Not bipartite, return 0
            }
        }
    }
    return flag==1?0:max(count[0], count[1]); // Take max of the two groups
}

void solve() {
    int N;
    cin >> N;
    cin.ignore(); // Ignore newline

    // Reset adjacency list and color array
    for (int i = 0; i < MAX_N; i++) {
        adj[i].clear();
        color[i] = -1;
    }

    // Read input and construct graph
    for (int i = 1; i <= N; i++) {
        string line;
        getline(cin, line);
        stringstream ss(line);

        int p, enemy;
        ss >> p;
        while (ss >> enemy) {
            if(enemy>N) continue;//if enemy is greater than N then it does not matter so skip it
            adj[i].push_back(enemy);
            adj[enemy].push_back(i);
        }
    }

    int max_people = 0;
    
    // Process all components
    for (int i = 1; i <= N; i++) {
        if (color[i] == -1) {  // Not visited
            max_people += bfs(i,N);
        }
    }

    cout << max_people << "\n";
}

int main() {
    int T;
    cin >> T;
    cin.ignore(); // Ignore newline

    while (T--) {
        solve();
         // Print blank line between test cases
    }
    return 0;
}
