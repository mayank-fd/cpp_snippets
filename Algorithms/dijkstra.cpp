int n, m;
const int MAX_N = 1e5 + 5, INF = 1e9 + 5;
vector<vector<pair<int, int>>> adj;
vector<int> d, p;

void dijkstra (int s) {
   d.assign(n, INF);
   p.assign(n, -1);
   vector<bool> marked(n, false);
   d[s] = 0;
   priority_queue<pair<int, int>> q;
   q.push({0, s});
   while (!q.empty()) {
      int u = q.top().yy; q.pop();
      if (marked[u]) {
         continue;
      }
      marked[u] = true;
      for (auto x : adj[u]) {
         int v = x.xx, w = x.yy;
         if (d[v] > d[u] + w) {
            d[v] = d[u] + w;
            p[v] = u;
            q.push({-d[v], v});
         }
      }
   }
}

void dijkstra_alternate (int s) {
   d.assign(n, INF);
   p.assign(n, -1);
   d[s] = 0;
   set<pair<int, int>> q;
   q.insert({0, s});
   while (!q.empty()) {
      int u = q.begin()->yy;
      q.erase(q.begin());
      for (auto x : adj[u]) {
         int v = x.xx, w = x.yy;
         if (d[v] > d[u] + w) {
            q.erase({d[v], v});
            d[v] = d[u] + w;
            p[v] = u;
            q.insert({d[v], v});
         }
      }
   }
}

void solve () {
   cin >> n >> m;
   adj.resize(n);
   for (int i = 1, u, v, w; i <= m; i++) {
      cin >> u >> v >> w, u--, v--;
      adj[u].push_back({v, w});
      adj[v].push_back({u, w});
   }
   int x, y;
   cin >> x >> y, x--, y--;
   dijkstra(x);
   cout << d[y] << "\n";
   vector<int> path;
   for (int v = y; v != x; v = p[v]) {
      path.push_back(v);
   }
   path.push_back(x);
   reverse(all(path));
   for (auto i : path) {
      cout << i + 1 << " ";
   }
   cout << endl;
} 