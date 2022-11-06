#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
template <class T> using Tree = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

Tree<int> t;
cout << t.order_of_key(x) << endl;
cout << *t.find_by_order(y) << endl;

// Read more on https://codeforces.com/blog/entry/11080
