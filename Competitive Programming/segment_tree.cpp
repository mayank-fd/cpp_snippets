template<class T> struct SegTree { // comb(ID,b) = b
   const T ID{}; T comb(T a, T b) { return a+b; }
   int n; vector<T> seg;
   void init (int _n) { // st.init(n) for queries on range [0, n).
      for (n = 1; n < _n; ) n *= 2; 
      seg.assign(2*n, ID);
   }
   void pull(int p) { seg[p] = comb(seg[2*p], seg[2*p+1]); }
   void upd(int p, T val) { // set val at position p
      seg[p += n] = val; for (p /= 2; p; p /= 2) pull(p); }
   T query(int l, int r) {	// sum on interval [l, r]
      T ra = ID, rb = ID;
      for (l += n, r += n+1; l < r; l /= 2, r /= 2) {
         if (l&1) ra = comb(ra, seg[l++]);
         if (r&1) rb = comb(seg[--r], rb);
      }
      return comb(ra, rb);
   }
   // void build (vector<int>& a) {  // to build the tree in O(n) instead of nlogn
   //    for (int i = 0; i < (int)a.size(); i++) seg[n + i] = (T)a[i];
   //    for (int i = n - 1; i > 0; --i) seg[i] = comb(seg[2*i], seg[2*i + 1]);
   // }
};