#include<bits/stdc++.h>
using namespace std;

template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }
template<typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> ostream& operator<<(ostream &os, const T_container &v) { os << '{'; string sep; for (const T &x : v) os << sep << x, sep = ", "; return os << '}'; }
void dbg_out() { cerr << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }
#define dbg(...) cerr << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int rand (int l, int r) {
   uniform_int_distribution<int> uid(l, r);
   return uid(rng);
}

const int N = 1e5;
int n;
vector<int> a;
string s, t;

struct state () {
   
};
state res1, res2;

bool checker (state &a, state &b) {
   return true;
}

state your_solution () {
   state s;
   return s;
}

state correct_solution () {
   state s;
   return s;
}

// Random n numbers between l and r
void num (int l, int r, int n) {
   for (int i = 0; i < n; ++i) {
      a.push_back(rand(l, r));
   }
}

// Random n strings of length l
void str (int l, int n) {
   for (int i = 0; i < n; ++i) {
      string tmp = "";
      for (int j = 0; j < l; ++j) {
         int v = rand(1,150);
         if(v%3==0) tmp += (char)rand('a','z');
         else if(v%3==1)tmp += (char)rand('A','Z');
         else tmp += rand(0,9);
      }
      // use tmp here
   }
}

// Random tree of n nodes: Errichto method
void tree(int n) {
   
}

int main() {
   ios_base::sync_with_stdio(!cin.tie(0););
   n = rand(1, N);
   for (int i = 1; ; i++) {
      dbg(i);
      res1 = your_solution(), res2 = correct_solution();
      if (!checker) {
         // dbg here
         break;
      }
   }
}
