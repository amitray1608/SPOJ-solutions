//“Make it work, make it right, make it fast.” – Kent Beck
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double dd;
const int siz = 1e6 + 5;
const int MOD = 1e9 + 7;
#define endl '\n'
#define deb(x) cout << #x << " = " << x << endl;

const ll INF = 1e9;
vector<vector<ll>>dis;

void solve(){
  int n = 501;
  int m;
  cin >> m;
  dis.resize(n, vector<ll>(n, INF));
  for(int i = 0; i < m; i++) {
    int u, v;
    ll c;
    cin >> u >> v >> c;

    dis[u][v] = min(dis[u][v], c);
    dis[v][u] = min(dis[v][u], c);
  }
  int u;
  cin >> u;
  for(int i = 0; i < n; i++) {
    dis[i][i] = 0;
  }
  //Floyd
  for(int k = 0; k < n; k++) {
    for(int i = 0; i < n; i++) {
      for(int j = 0; j < n; j++) {
        dis[i][j] = min(dis[i][j], dis[i][k]+dis[k][j]);
      }
    }
  }

  int q;
  cin >> q;
  while(q--) {
    int d;
    cin >> d;
    if(u == d)
      cout << 0 << endl;
    else if(dis[u][d] >= INF or d > 500)
      cout << "NO PATH" << endl;
    else 
      cout << dis[u][d] << endl;
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

