//“Make it work, make it right, make it fast.” – Kent Beck
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double dd;
const ll siz = 1e6 + 5;
const ll MOD = 1e9 + 7;
#define endl '\n'
#define deb(x) cout << #x << " = " << x << endl;


struct Edge{
  ll u, v, w;
  bool operator<(Edge const& o) {
    return w < o.w;
  }
};

vector<Edge>e;

template<typename T>
class dsu {
  public:
    ll n;
    vector<ll>p, rank;
    dsu(ll _n) : n(_n) {
      p.resize(n);
      rank.resize(n);
      iota(p.begin(), p.end(), 0);
      fill(rank.begin(), rank.end(), 0);
    } 

    inline ll root(ll x) {
      return (x == p[x] ? x : (p[x] = root(p[x])));
    }

    inline void unite(ll u, ll v) {
      u = root(u);
      v = root(v);
      if(u != v) {
        if(rank[u] > rank[v]) {
          swap(u, v);
        }
        p[u] = v;
        if(rank[u] == rank[v])
          rank[v]++;
      }
    }
};

void solve(){
  ll p, n, m;
  cin >> p >> n >> m;
  dsu<ll> d(n);
  e.resize(m);
  for(ll i = 0; i < m; i++) {
    ll u, v, c;
    cin >> u >> v >> c;
    u--, v--;
    e[i].u = u;
    e[i].v = v;
    e[i].w = c;
  }
  sort(e.begin(), e.end());
  ll cost = 0;
  for(Edge ee : e) {
    if(d.root(ee.u) != d.root(ee.v)) {
      cost += ee.w;
      d.unite(ee.u, ee.v);
    }
  }
  ll ans = cost*p;
  cout << ans << endl;
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