//“Make it work, make it right, make it fast.” – Kent Beck
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double dd;
const int siz = 1e6 + 5;
const int MOD = 1e9 + 7;
#define endl '\n'
#define deb(x) cout << #x << " = " << x << endl;

vector<vector<int>> table;
vector<int> logtable;
void logcal(int n) {
  logtable.resize(n+1);
  logtable[1] = 0;
  for(int i = 2; i <= n; i++)
    logtable[i] = logtable[i/2] + 1;
}

void SparseTable(int n, vector<int>&a) {
  int k = log2(n);
  table.resize(n, vector<int>(k+1));
  for(int i = 0; i < n; i++) {
    table[i][0] = a[i];
  }
  for(int j = 1; j <= k; j++)
    for(int i = 0; i + (1 << j) <= n; i++)
      table[i][j] = min(table[i][j-1], table[i + (1 << (j-1))][j-1]);
}

int query(int l, int r) {
  int j = logtable[r-l];
  return min(table[l][j], table[r - (1 << j) + 1][j]);
}

void solve() {
  int n;
  cin >> n;
  vector<int>a(n);
  for(int &i : a) cin >> i;
  SparseTable(n, a);
  logcal(n);
  int q;
  cin >> q;
 /*
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < log2(n)+1; j++)
      cout << table[i][j] << ' ';
    cout << endl;
  }
  */
  while(q--) {
    int l, r;
    cin >> l >> r;
    cout << query(l, r) << endl;
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  cout << fixed << setprecision(10);
  int t = 1;
  // cin >> t;
  for(int tt = 1; tt <= t; tt++) {
    //cout << "Case #" << tt << ": ";
    solve();
  }
  return 0;
}  
