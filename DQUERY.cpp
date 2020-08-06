//“Make it work, make it right, make it fast.” – Kent Beck
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1e9 + 7;
#define endl '\n'
#define deb(x) cout << #x << " = " << x << endl;
 
#define N 311111
#define A 1111111
#define BLOCK 555
 
int cnt[A], a[N], ans[N], answer = 0;
 
struct Node{
  int l, r, i;
}q[N];
 
bool cmp(Node x, Node y) {
  if(x.l/BLOCK != y.l/BLOCK) {
    return x.l/BLOCK < y.l/BLOCK;
  }
  return x.r < y.r;
}
 
void add(int p) {
  cnt[a[p]]++;
  if(cnt[a[p]] == 1)
    answer++;
 }
 
void remove(int p) {
  cnt[a[p]]--;
  if(cnt[a[p]] == 0)
    answer--;
}
 
void solve() {
  int n;
  cin >> n;
  for(int i = 0; i < n; i++) cin >> a[i];
 
  int m;
  cin >> m;
  for(int i = 0; i < m; i++) {
    cin >> q[i].l >> q[i].r;
    q[i].i = i;
    q[i].l--, q[i].r--;
  }
 
  sort(q, q+m, cmp);
 
  int currL = 0, currR = 0;
  for(int i = 0; i < m; i++) {
    int L = q[i].l, R = q[i].r;
    while(currL < L) {
      remove(currL);
      currL++;
    }  
    while(currL > L) {
      add(currL-1);
      currL--;
    }    
    while(currR <= R) {
      add(currR);
      currR++;
    }    
    while(currR > R+1) {
      remove(currR-1);
      currR--;
    }
    ans[q[i].i] = answer;
  }
  for(int i = 0; i < m; i++) {
    cout << ans[i] << endl;
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