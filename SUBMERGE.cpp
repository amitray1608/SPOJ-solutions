//“Make it work, make it right, make it fast.” – Kent Beck
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double dd;
const int siz = 1e6 + 5;
const int MOD = 1e9 + 7;
#define endl '\n'
#define deb(x) cout << #x << " = " << x << endl;

int n, m;
vector<vector<int>>adj;
vector<bool>vis, ans;
vector<int>tin, low;

int timer;
int counts = 0;
void dfs(int v, int p = -1) {
  vis[v] = true;
  tin[v] = low[v] = timer++;
  int child = 0;
  for(int to : adj[v]) {
    if(to == p) continue;
    if(vis[to])
      low[v] = min(low[v], tin[to]);
    else {
      dfs(to, v);
      low[v] = min(low[v], low[to]);
      if(low[to] >= tin[v] and p != -1)
        ans[v] = true;
      child++;
    }
  }
  if(p == -1 and child > 1)
    ans[v] = true;
}

void solve(){
  cin >> n >> m;
  if(n == m and m == 0)
    exit(0);
  ans.resize(n, false);
  adj.resize(n);
  vis.resize(n, false);
  tin.assign(n, -1);
  low.assign(n, -1);

  for(int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;
    u--, v--;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  timer = 0;
  for(int i = 0; i < n; i++) {
    if(!vis[i]) {
      dfs(i);
    }
  }
  for(auto i: ans)
    if(i)
      counts++;

  cout << counts << endl;
  counts = 0;
  for(int i = 0; i < n; i++)
    adj[i].clear();
  low.clear();
  tin.clear();
  vis.clear();
  ans.clear();
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  while(true){
    //tt++;
    //cout << "Case #" << tt << ": ";
    solve();
  }
  return 0;
}  