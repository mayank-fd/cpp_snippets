ll binpow (ll x, ll n, ll m) {
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

ll inv(ll x, ll m) {
   return binpow(x, m - 2, m);
}