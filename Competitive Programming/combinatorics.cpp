const int N = 2e6 + 1, mod = 1e9 + 7;
int fact[N], invFact[N];

ll binpow(ll x, ll n, ll m) {
   x %= m;  
   ll res = 1;
   while (n > 0) {
      if (n % 2 == 1)  
         res = res * x % m;
      x = x * x % m;
      n /= 2;  
   }
   return res;
}

void precompute () {
   fact[0] = invFact[0] = 1;
   for (int i = 1; i < (int)N; i++) {
      fact[i] = (int)((i * (ll)fact[i - 1]) % mod);
      invFact[i] = (int)binpow(fact[i], mod - 2, mod);
   }
}

int choose (int x, int y) {
   if(x < y) return 0;
   return (int)((((fact[x] * (ll)invFact[y]) % mod) * invFact[x - y]) % mod);
}