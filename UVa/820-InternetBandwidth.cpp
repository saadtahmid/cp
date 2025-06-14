#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef tuple<int, ll, ll> edge;
typedef vector<int> vi;
typedef pair<int, int> ii;

const ll INF = 1e18;                             // large enough

class max_flow {
private:
  int V;
  vector<edge> EL;
  vector<vi> AL;
  vi d, last;
  vector<ii> p;

  bool BFS(int s, int t) {                       // find augmenting path
    d.assign(V, -1); d[s] = 0;
    queue<int> q({s});
    p.assign(V, {-1, -1});                       // record BFS sp tree
    while (!q.empty()) {
      int u = q.front(); q.pop();
      if (u == t) break;                         // stop as sink t reached
      for (auto &idx : AL[u]) {                  // explore neighbors of u
        auto &[v, cap, flow] = EL[idx];          // stored in EL[idx]
        if ((cap-flow > 0) && (d[v] == -1))      // positive residual edge
          d[v] = d[u]+1, q.push(v), p[v] = {u, idx}; // 3 lines in one!
      }
    }
    return d[t] != -1;                           // has an augmenting path
  }

  ll send_one_flow(int s, int t, ll f = INF) {   // send one flow from s->t
    if (s == t) return f;                        // bottleneck edge f found
    auto &[u, idx] = p[t];
    auto &cap = get<1>(EL[idx]), &flow = get<2>(EL[idx]);
    ll pushed = send_one_flow(s, u, min(f, cap-flow));
    flow += pushed;
    auto &rflow = get<2>(EL[idx^1]);             // back edge
    rflow -= pushed;                             // back flow
    return pushed;
  }

  ll DFS(int u, int t, ll f = INF) {             // traverse from s->t
    if ((u == t) || (f == 0)) return f;
    for (int &i = last[u]; i < (int)AL[u].size(); ++i) { // from last edge
      auto &[v, cap, flow] = EL[AL[u][i]];
      if (d[v] != d[u]+1) continue;              // not part of layer graph
      if (ll pushed = DFS(v, t, min(f, cap-flow))) {
        flow += pushed;
        auto &rflow = get<2>(EL[AL[u][i]^1]);     // back edge
        rflow -= pushed;
        return pushed;
      }
    }
    return 0;
  }

public:
  max_flow(int initialV) : V(initialV) {
    EL.clear();
    AL.assign(V, vi());
  }

  // if you are adding a bidirectional edge u<->v with weight w into your
  // flow graph, set directed = false (default value is directed = true)
  void add_edge(int u, int v, ll w, bool directed = true) {
    if (u == v) return;                          // safeguard: no self loop
    EL.emplace_back(v, w, 0);                    // u->v, cap w, flow 0
    AL[u].push_back(EL.size()-1);                // remember this index
    EL.emplace_back(u, directed ? 0 : w, 0);     // back edge
    AL[v].push_back(EL.size()-1);                // remember this index
  }

  ll edmonds_karp(int s, int t) {
    ll mf = 0;                                   // mf stands for max_flow
    while (BFS(s, t)) {                          // an O(V*E^2) algorithm
      ll f = send_one_flow(s, t);                // find and send 1 flow f
      if (f == 0) break;                         // if f == 0, stop
      mf += f;                                   // if f > 0, add to mf
    }
    return mf;
  }

  ll dinic(int s, int t) {
    ll mf = 0;                                   // mf stands for max_flow
    while (BFS(s, t)) {                          // an O(V^2*E) algorithm
      last.assign(V, 0);                         // important speedup
      while (ll f = DFS(s, t))                   // exhaust blocking flow
        mf += f;
    }
    return mf;
  }
  vector<tuple<int, int, ll, ll>> get_edges() {
    vector<tuple<int, int, ll, ll>> result;
    for (int u = 0; u < V; ++u) {
        for (int idx : AL[u]) {
            auto &[v, cap, flow] = EL[idx];
            // Only consider original (forward) edges
            if (cap > 0 && flow > 0) {
                result.emplace_back(u, v, cap, flow);
            }
        }
    }
    return result;
}
  //get vertices in min cut
  vector<int> get_min_cut(int s) {
    vector<int> visited(V, 0);
    queue<int> q;
    q.push(s);
    visited[s] = 1;
    while (!q.empty()) {
      int u = q.front(); q.pop();
      for (int idx : AL[u]) {
        auto &[v, cap, flow] = EL[idx];
        if (!visited[v] && cap > flow) { // only consider edges with positive residual capacity
          visited[v] = 1;
          q.push(v);
        }
      }
    }
    vector<int> min_cut_vertices;
    for (int i = 0; i < V; ++i) {
      if (visited[i]) {
        min_cut_vertices.push_back(i);
      }
    }
    return min_cut_vertices;
  }
};

signed main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n;int l=1;
  while(cin>>n &&n){
    
    int s,t,m;
    cin>>s>>t>>m;
    max_flow mf(n+1);
    for(int i=0;i<m;i++){
      int u,v;
      ll w;
      cin>>u>>v>>w;
      mf.add_edge(u,v,w,false);
    }
    ll max_flow_value = mf.dinic(s, t);
    cout<<"Network "<<l++<<"\n";
    cout<<"The bandwidth is "<<max_flow_value<<".\n\n";
  }
  return 0;
}