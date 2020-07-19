//“Make it work, make it right, make it fast.” – Kent Beck
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double dd;
const ll siz = 1e6 + 5;
const ll MOD = 1e9 + 7;
#define endl '\n'
#define deb(x) cout << #x << " = " << x << endl;

vector<ll>staus;

struct Edge {
  ll u, v, w;
  bool operator<(Edge const& o) {
    return w < o.w;
  }
};

vector<Edge>e;

template<typename T>
class dsu {
  public:
    T n;
    vector<T>p, rank;
    
    dsu(T _n) : n(_n) {
      p.resize(n);
      rank.resize(n);
      iota(p.begin(), p.end(), 0);
      fill(rank.begin(), rank.end(), 1);
    }

     bool isconnect(T x, T y) {
      return root(x) == root(y);
    }

    T root(T x) {
      return (x == p[x] ? x : (p[x] = root(p[x])));
    }

     void unite(T x, T y) {
      x = root(x);
      y = root(y);
      if(x != y) {
        if(rank[x] > rank[y]) {
          p[y] = x;
          rank[x] += rank[y];
          rank[y] = 0;
        } else {
          p[x] = y;
          rank[y] += rank[x];
          rank[x] = 0;
        }
      }
    }
};

void solve(){
  ll n, m;
  cin >> n >> m;
  dsu<ll> d(n+1);
  staus.resize(n);
  for(ll &i : staus) {
    cin >> i;
  }
  for(int i = 0; i < n; i++) {
    if(staus[i])
      e.push_back({i, n, 0});
  }
  for(ll i = 0; i < m; i++) {
    ll u, v, c;
    cin >> u >> v >> c;
    u--, v--;
    e.push_back({u, v, c});
  }
  // cout << "ok" << endl;
  sort(e.begin(), e.end());
  // for(Edge ee : e) {
  //   cout << ee.u << ' ' << ee.v << ' ' << ee.w << endl;
  // }
  ll cost = 0;
  for(ll i = 0; i < (ll)e.size(); i++) {
    if(d.root(e[i].u) != d.root(e[i].v)) {
        cost += e[i].w;
        // cout << e[i].u << ' ' << e[i].v << endl;
        d.unite(e[i].u, e[i].v);
      }
  }
  for(int i = 0; i < n; i++) {
    if(!d.isconnect(i, n)) {
      cout << "impossible" << endl;
      return;
    }
  }
    cout << cost << endl;
    e.clear();
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  ll t = 1;
  cin >> t;
  while(t--){
    //tt++;
    //cout << "Case #" << tt << ": ";
    solve();
  }
  return 0;
}  

/*
4
5 7
0 1 0 1 0
1 2 11
1 3 1
1 5 17
2 3 1
3 5 18
4 5 3
2 4 5
4 3
0 1 0 1
1 2 2
3 4 2
1 3 1
5 8
0 0 0 0 1
1 2 12
2 3 3
3 4 7
5 1 5
3 2 5
2 3 2
2 1 4
1 5 3
5 3
1 0 0 0 0
1 3 2
3 4 2
2 4 2

*/