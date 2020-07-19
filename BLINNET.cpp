//“Make it work, make it right, make it fast.” – Kent Beck
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double dd;
const ll siz = 1e6 + 5;
const ll MOD = 1e9 + 7;
#define endl '\n'
#define deb(x) cout << #x << " = " << x << endl;

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
    vector<T>p;
    vector<T>rank;
    ll n;

    dsu(ll _n) : n(_n) {
      p.resize(n);
      rank.resize(n);
      iota(p.begin(), p.end(), 0);
      fill(rank.begin(), rank.end(), 1);
    }

    inline T root(T x) {
      return (x == p[x] ? x : (p[x] = root(p[x])));
    }

    inline void unite(T x, T y) {
      x = root(x);
      y = root(y);
      if(x != y) {
        if(rank[y] < rank[x]) 
          swap(x, y);
        p[x] = y;
        if(rank[x] == rank[y])
          rank[y]++;
      }
    }
};


void solve(){
  ll n;
  cin >> n;
  dsu<ll> d(n);
  e.resize(n*n);
  ll M = 0;
  for(ll i = 0; i < n; i++) {
    string s;
    cin >> s;
    ll m;
    cin >> m;
    while(m--) {
      ll v, c;
      cin >> v >> c;
      v--;
      e[M].u = i;
      e[M].v = v;
      e[M++].w = c;
    }
  }
    sort(e.begin(), e.begin()+M);
    ll cost = 0;
    for(ll i = 0; i < M; i++) {
      if(d.root(e[i].u) != d.root(e[i].v)) {
        cost += e[i].w;
        d.unite(e[i].u, e[i].v);
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