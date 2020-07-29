//“Make it work, make it right, make it fast.” – Kent Beck
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double dd;
const int siz = 1e6 + 5;
const int MOD = 1e9 + 7;
#define endl '\n'
#define deb(x) cout << #x << " = " << x << endl;

vector<vector<int>> adj;
vector<bool> vis;
vector<int> cycle; 
int n;

void dfs(int s) {
  if(vis[s])
  return;
  vis[s] = 1;
  cycle.push_back(s);
  for(auto i : adj[s]) {
    if(!vis[i])
      dfs(i);
  }
}

void solve() {
  adj.resize(n);
  vector<pair<int, int>> a(n), b;
  for(int i = 0; i < n; i++) {
    cin >> a[i].first;
    a[i].second = i;
  }
  b = a;
  sort(b.begin(), b.end());
  for(int i = 0; i < n; i++) {
    if(a[i].first != b[i].first) {
      adj[a[i].second].push_back(b[i].second);
      adj[b[i].second].push_back(a[i].second);
    }
  }
  int cost = 0;
  vis.resize(n, 0);
  for(int i = 0; i < n; i++) {
    if(!vis[i]) {
      if(adj[i].size() == 0) continue;
      dfs(i);
      sort(cycle.begin(), cycle.end());
      int sum = 0, sum2 = b[0].first+b[cycle[0]].first;
      for(int j = 1; j < (int)cycle.size(); j++) {
        sum += b[cycle[j]].first + b[cycle[0]].first;
      }
      for(int j = 0; j < (int)cycle.size(); j++) {
        sum2 += b[cycle[j]].first + b[0].first;
      }
      cost += min(sum, sum2);
      cycle.clear();
    }
  }
  vis.clear();
  cycle.clear();
  cout << cost << endl << endl;
  for(int i = 0; i < n; i++)
    adj[i].clear();
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  cout << fixed << setprecision(10);
  // int t = 1;
  // cin >> t;
  for(int tt = 1; ; tt++) {
    cin >> n;
    if(n == 0) {
      break;
    }
    cout << "Case " << tt << ": ";
    solve();
  }
  return 0;
}  