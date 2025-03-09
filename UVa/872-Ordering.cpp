#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <algorithm>
#include <set>
using namespace std;

#define int long long
#define pb push_back
#define vi vector<int>
#define endl "\n"
#define loop(i, a, b) for (int i = a; i < b; i++)

void backtrack(vector<char>& result, vector<char>& variables, unordered_map<char, vector<char>>& adj, unordered_map<char, int>& in_degree, set<string>& all_orders) {
    if (result.size() == variables.size()) {
        string order;
        for (char c : result) {
            order += c;
        }
        all_orders.insert(order);
        return;
    }

    for (char var : variables) {
        if (in_degree[var] == 0) {
            result.pb(var);
            in_degree[var] = -1; // Mark as visited
            for (char neighbor : adj[var]) {
                in_degree[neighbor]--;
            }

            backtrack(result, variables, adj, in_degree, all_orders);

            // Backtrack
            result.pop_back();
            in_degree[var] = 0;
            for (char neighbor : adj[var]) {
                in_degree[neighbor]++;
            }
        }
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    cin.ignore(); // Ignore the newline after the number of test cases
    string blank;
    getline(cin, blank); // Consume the blank line after the number of test cases

    while (t--) {
        string variables_line, constraints_line;
        getline(cin, variables_line);
        getline(cin, constraints_line);

        vector<char> variables;
        unordered_map<char, vector<char>> adj;
        unordered_map<char, int> in_degree;

        // Parse variables
        for (char c : variables_line) {
            if (c != ' ') {
                variables.pb(c);
                in_degree[c] = 0;
            }
        }

        // Parse constraints
        for (size_t i = 0; i < constraints_line.size(); i += 4) {
            char u = constraints_line[i];
            char v = constraints_line[i + 2];
            adj[u].pb(v);
            in_degree[v]++;
        }

        // Sort variables to ensure alphabetical order
        sort(variables.begin(), variables.end());

        // Backtracking to find all valid topological sorts
        vector<char> result;
        set<string> all_orders;
        backtrack(result, variables, adj, in_degree, all_orders);

        // Output results
        if (all_orders.empty()) {
            cout << "NO" << endl;
        } else {
            for (const string& order : all_orders) {
                for (size_t i = 0; i < order.size(); ++i) {
                    if (i > 0) cout << " ";
                    cout << order[i];
                }
                cout << endl;
            }
        }

        if (t) {
            cout << endl; // Print a blank line between test cases
            getline(cin, blank); // Consume the blank line between test cases
        }
    }

    return 0;
}