const int N = 100;
vector<bool> is_prime(101, true);
is_prime[0] = is_prime[1] = false;
for (int i = 2; i * i <= N; i++) {
   if (is_prime[i]) {
      for (int p = i * i; p <= N; p += i) {
         is_prime[p] = false;
      }
   }
}