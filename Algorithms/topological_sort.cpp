// Can alternatively implement using a recursive dfs function 
void solve () {
   int n, m;
   cin >> n >> m;
   vector<bool> vis;
   vector<vector<int>> adj(n); 
   vector<int> ans;
   stack<int> dfs;
   for (int i = 0, a, b; i < m; i++) {
      cin >> a >> b;
      adj[a].push_back(b);
   }
   vis.assign(n, false);
   for (int i = 0; i < n; i++) {
      if (!vis[i]) {
         dfs.push(i);
         while (!dfs.empty()) {
            int v = dfs.top();
            dfs.pop();
            vis[v] = true;
            for (int u : adj[v]) {
               if (!vis[u])
                 dfs.push(u);
            }
            ans.push_back(v);
         }
      }
   }
   reverse(ans.begin(), ans.end());
   for (auto i : ans) {
      cout << i << " ";
   }
} 


// Or using bfs - Also known as Kuhn's algorithm
void solve () {
   int n, m;
   cin >> n >> m;
   vector<vector<int>> adj(n); 
   vector<int> ans, nodes_indegree;
   nodes_indegree.assign(n, 0);
   for (int i = 0, a, b; i < m; i++) {
      cin >> a >> b;
      adj[a].push_back(b);
      nodes_indegree[b]++;
   }
   queue<int> bfs;
   for (int i = 0; i < n; i++) {
      if (nodes_indegree[i] == 0) {
         bfs.push(i);
      }
   }
   while (!bfs.empty()) {
      int u = bfs.front();
      bfs.pop();
      ans.push_back(u);
      for (auto v : adj[u]) {
         nodes_indegree[v]--;
         if (nodes_indegree[v] == 0) {
            bfs.push(v);
         }
      }
   }
   for (auto i : ans) {
      cout << i << " ";
   }
} 