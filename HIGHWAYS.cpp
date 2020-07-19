//“Make it work, make it right, make it fast.” – Kent Beck
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double dd;
const ll siz = 1e6 + 5;
const ll MOD = 1e9 + 7;
#define endl '\n'
#define deb(x) cout << #x << " = " << x << endl;

const ll INF = 1000000000;
vector<vector<pair<ll, ll>>>adj;
vector<ll>dist;
vector<bool>vis;

void solve(){
  ll n, m, s, d;
  cin >> n >> m >> s >> d;
  s--, d--;
  dist.resize(n, INF);
  adj.resize(n);
  vis.resize(n, false);
  for(ll i = 0; i < m; i++) {
    ll u, v, c;
    cin >> u >> v >> c;
    u--, v--;
    adj[u].push_back({v, c});
    adj[v].push_back({u, c});
  }
  priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>>q;
  q.push({0, s});
  dist[s] = 0;
  while(!q.empty()) {
    auto x = q.top();
    q.pop();
    ll u = x.second;
    // ll cost = x.first;
    // cout << u << endl;
    vis[u] = true;
    if(x.first == INF) continue;
    for(auto c : adj[u]) {
      ll v = c.first;
      ll cost = c.second;
      if(!vis[v] and dist[v] > dist[u] + cost) {
        dist[v] = dist[u] + cost;
        q.push({dist[v], v});
      }
    }
  }
  // for(ll i = 0; i < n; i++)
  //   cout << dist[i] << ' ';
  if(dist[d] >= INF)
    cout << "NONE" << endl;
  else
    cout << dist[d] << endl;
  adj.clear();
  dist.clear();
  vis.clear();
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