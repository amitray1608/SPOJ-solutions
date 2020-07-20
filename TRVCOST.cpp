//“Make it work, make it right, make it fast.” – Kent Beck
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double dd;
const int siz = 1e6 + 5;
const int MOD = 1e9 + 7;
#define endl '\n'
#define deb(x) cout << #x << " = " << x << endl;

const int INF = 1e9;
typedef pair<int, int> pri;
vector<vector<pri>>adj;
vector<int>dis;


void dijk(int s) {
  priority_queue<pri, vector<pri>, greater<pri>>q;
  dis[s] = 0;
  q.push({0, s});
  while(!q.empty()) {
    auto x = q.top();
    q.pop();
    int u = x.second;
    if(x.first == INF) continue;
    for(auto i : adj[u]) {
      int v = i.first;
      int c = i.second;
      if(dis[v] > dis[u]+c) {
        dis[v] = dis[u]+c;
        q.push({dis[v], v});
      }
    }
  }
}

void solve(){
  int n = 501;
  int m;
  cin >> m;
  adj.resize(n);
  dis.resize(n, INF);
  for(int i = 0; i < m; i++) {
    int u, v, c;
    cin >> u >> v >> c;
    adj[u].push_back({v, c});
    adj[v].push_back({u, c});
  }
  int u;
  cin >> u;
  dijk(u);
  int q;
  cin >> q;
  while(q--) {
    int d;
    cin >> d;
    if(dis[d] >= INF)
      cout << "NO PATH" << endl;
    else
      cout << dis[d] << endl;
  }
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t = 1;
  // cin >> t;
  while(t--){
    //tt++;
    //cout << "Case #" << tt << ": ";
    solve();
  }
  return 0;
}  

