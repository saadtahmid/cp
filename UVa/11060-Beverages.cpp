#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <algorithm>
using namespace std;

#define int long long
#define pb push_back
#define vi vector<int>
#define endl "\n"
#define loop(i, a, b) for (int i = a; i < b; i++)

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int case_num = 1;
    int n;
    while (cin >> n) {
        vector<string> beverages(n);
        unordered_map<string, int> bev_to_index;
        unordered_map<int, string> index_to_bev;

        loop(i, 0, n) {
            cin >> beverages[i];
            bev_to_index[beverages[i]] = i;
            index_to_bev[i] = beverages[i];
        }

        int m;
        cin >> m;
        vector<vi> adj(n);
        vi in_degree(n, 0);

        loop(i, 0, m) {
            string b1, b2;
            cin >> b1 >> b2;
            int u = bev_to_index[b1];
            int v = bev_to_index[b2];
            adj[u].pb(v);
            in_degree[v]++;
        }

        // Kahn's algorithm for topological sorting
        priority_queue<int, vector<int>, greater<int>> q;
        loop(i, 0, n) {
            if (in_degree[i] == 0) {
                q.push(i);
            }
        }

        vi topo_order;
        while (!q.empty()) {
            int node = q.top();
            q.pop();
            topo_order.pb(node);

            for (int neighbor : adj[node]) {
                in_degree[neighbor]--;
                if (in_degree[neighbor] == 0) {
                    q.push(neighbor);
                }
            }
        }

        cout << "Case #" << case_num << ": Dilbert should drink beverages in this order:";
        for (int i = 0; i < topo_order.size(); i++) {
            cout << " " << index_to_bev[topo_order[i]];
        }
        cout << "." << endl << endl;

        case_num++;
    }

    return 0;
}