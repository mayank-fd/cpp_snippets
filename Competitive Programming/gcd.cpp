template<typename T> inline T gcd(T a, T b) { while (b) swap(b, a %= b); return a; }
template<typename T> inline long long lcm(T a, T b) { return ((long long)a * b) / gcd(a, b); }
