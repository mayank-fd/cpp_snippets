int n, m;
vector<vector<pair<int, int>>> adj;

struct edge {
   int a, b, c;
};

void solve () {
   cin >> n >> m;
   adj.resize(n);
   for (int i = 1, a, b, c; i <= m; i++) {
      cin >> a >> b >> c, a--, b--;
      adj[a].push_back({b, c});
      adj[b].push_back({a, c});
   }
   vector<bool> vis(n, false);
   auto cmp = [&] (const edge& e1, const edge& e2) { return e1.c > e2.c; }; // sort my min-edge weight
   priority_queue<edge, vector<edge>, decltype(cmp)> pq(cmp);
   ll mstcost = 0;
   int a = 1; // pick any arbitrary node
   for (auto &[b, c] : adj[a]) { // add edges that connect to the component directly
      pq.push(edge{a, b, c});
   }
   vis[a] = true;
   vector<edge> mstedges;
   while (!pq.empty() && sz(mstedges) < n - 1) {
      edge e = pq.top();
      pq.pop();
      if (vis[e.b]) {
         continue;
      }
      vis[e.b] = true;
      mstcost += e.c;
      mstedges.push_back(e);
      for (auto [v, w] : adj[e.b]) { // push new edges to the queue 
         pq.push(edge{e.b, v, w});
      }
   }
   if (sz(mstedges) != n - 1) {
      cout << "-1\n";
      return;
   }
   cout << mstcost << "\n";
   for (auto e : mstedges) {
      cout << e.a + 1 << " " << e.b + 1 << "\n";
   }
}
