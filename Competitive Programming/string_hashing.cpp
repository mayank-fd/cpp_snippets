struct hasher {
   const int P = 23917, M = 1e9 + 7;
   vector<int> h, p;
   hasher(string &s) {
      int n = (int)s.size();
      h.resize(n + 1); p.resize(n + 1);
      p[0] = 1;
      for (int i = 0; i < n; i++) {
         h[i + 1] = (h[i] * 1LL * P + s[i]) % M;
         p[i + 1] = (p[i] * 1LL * P) % M;
      }
   }
   // hash value of s[l..(r-1)] 
   int get (int l, int r) {
      return (h[r] - (h[l] * 1LL * p[r - l]) % M + M) % M;
   }
};