// Binary Indexed Tree
template<class T> struct BIT {
   int N; vector<T> data;
   void init(int _N) { N = _N; data.resize(N); } // init(n + 1) for queries in range [1, n]
   void add(int p, T x) { for (++p; p<=N; p += p&-p) data[p-1] += x; }
   T sum(int l, int r) { return sum(r+1) - sum(l); }
   T sum(int r) { T s = 0; for(; r; r -= r&-r) s += data[r-1]; return s; }
   // int lower_bound(T sum) {
   // 	if (sum <= 0) return -1;
   // 	int pos = 0;
   // 	for (int pw = 1<<25; pw; pw >>= 1) {
   // 		int npos = pos+pw;
   // 		if (npos <= N && data[npos-1] < sum)
   // 			pos = npos, sum -= data[pos-1];
   // 	}
   // 	return pos;
   // }
};


// Fenwick Tree
template<class T> struct FT {
   vector<T> s;
   FT(int n) : s(n) {}
   void update(int pos, T dif) { // a[pos] += dif
      for (; pos < sz(s); pos |= pos + 1) s[pos] += dif;
   }
   T query(int pos) { // sum of values in [0, pos)
      T res = 0;
      for (; pos > 0; pos &= pos - 1) res += s[pos-1];
      return res;
   }
};


// Sparse Tables
struct RMQ {
   int N, K;
   vector<int> lg;
   vector<vector<int>> st;

   RMQ (vector<int> &array) {
      N = array.size();
      lg.resize(N + 1);
      lg[1] = 0;
      for (int i = 2; i <= N; i++) {
         lg[i] = lg[i/2] + 1;
      }
      for (K = 0; (1 << K) <= N;) K++;
      st.resize(N, vector<int>(K));
      for (int i = 0; i < N; i++) {
         st[i][0] = array[i];
      }
      for (int j = 1; j <= K; j++) {
         for (int i = 0; i + (1 << j) <= N; i++) {
            st[i][j] = min(st[i][j - 1], st[i + (1 << (j - 1))][j - 1]);
         }
      }
   }

   int query (int L, int R) {
      int j = lg[R - L + 1];
      return min(st[L][j], st[R - (1 << j) + 1][j]);
   }
};