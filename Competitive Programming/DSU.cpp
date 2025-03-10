struct DSU {   
   vector<int> e;
   DSU(int N) { e = vector<int>(N, -1); }
   int get(int x) { return e[x] < 0 ? x : e[x] = get(e[x]); } 
   bool same_set(int a, int b) { return get(a) == get(b); }
   int size(int x) { return -e[get(x)]; }
   bool unite(int x, int y) {  
      x = get(x), y = get(y);
      if (x == y) return false;
      if (e[x] > e[y]) swap(x, y);
      e[x] += e[y]; e[y] = x;
      return true;
   }
}; 

template<class T> T kruskal(int N, vector<pair<T, pair<int, int>> ed) {
	sort(ed.begin(), ed.end());
	T ans = 0; DSU D; D.init(N); // edges that unite are in MST
	for(auto a : ed) if (D.unite(a.second.first, a.second.second)) ans += a.first;
	return ans;
}
