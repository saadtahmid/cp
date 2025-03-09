#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <set>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template <typename T>
using o_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
typedef long long ll;
#define int long long
#define pii pair<int, int>
#define pb push_back
#define vi vector<int>
#define endl "\n"
#define srt(x) sort(x.begin(), x.end())
#define pq priority_queue
#define loop(i, a, b) for (int i = a; i < b; i++)
#define MOD 1000000007

void solve(int i, vector<vi> &adj, vi &ans, vi &visited)
{
    visited[i] = 1;
    for(auto x : adj[i])
    {
        if(visited[x] == 0)
            solve(x, adj, ans, visited);
    }
    ans.pb(i);
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    vector<string> v;
    string s;
    set<char> present_chars;
    while(cin >> s)
    {
        if(s == "#")
            break;
        v.pb(s);
        for(char c : s) {
            present_chars.insert(c);
        }
    }    
    // Create a graph of characters that are present in the strings only
    vector<vi> adj(26);
    for(int i = 0; i < v.size() - 1; i++)
    {
        for(int j = 0; j < min(v[i].size(), v[i + 1].size()); j++)
        {
            if(v[i][j] != v[i + 1][j])
            {
                adj[v[i][j] - 'A'].pb(v[i + 1][j] - 'A');
                break;
            }
        }
    }

    // Perform topological sort 
    vi ans;
    vi visited(26, 0);
    for(char c : present_chars)
    {
        if(visited[c - 'A'] == 0)
            solve(c - 'A', adj, ans, visited);
    }
    reverse(ans.begin(), ans.end());
    for(auto x : ans)
        cout << (char)(x + 'A');
    cout << endl;
    return 0;
}