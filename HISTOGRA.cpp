//“Make it work, make it right, make it fast.” – Kent Beck
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double dd;
const int siz = 1e6 + 5;
const int MOD = 1e9 + 7;
#define endl '\n'
#define deb(x) cout << #x << " = " << x << endl;

void solve(){
  int n;
  cin >> n;
  if(n == 0)
    exit(0);
  vector<ll>a(n);
  for(ll &i : a) cin >> i;
  ll maxi = 0, maxitop = 0, tp = 0;
  stack<int>s;
  int i = 0;
  maxi = 0;
  auto histo = [&]() {
    maxi = 0, maxitop = 0;
    i = 0;
    while(i < n) {
      if(s.empty() or a[s.top()] <= a[i]) 
        s.push(i++);
      else {
         tp = s.top();
        s.pop();
        maxitop = a[tp] * (s.empty() ? i : i - s.top() - 1);
        maxi = max(maxi, maxitop);
      }
    }
    while(!s.empty()) {
      tp = s.top();
      s.pop();
      maxitop = a[tp] * (s.empty() ? i : i - s.top() - 1);
      maxi = max(maxi, maxitop);
    }
    return maxi;
  };

  maxi = histo();
  cout << maxi << endl;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t = 1;
  // cin >> t;
  while(t){
    //tt++;
    //cout << "Case #" << tt << ": ";
    solve();
  }
  return 0;
}  

/*
7
6 2 5 4 5 1 6
0

*/