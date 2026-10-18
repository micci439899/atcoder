#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, a, b) for (int i = (int)(a); i < (int)(b); i++)

int main() {
  ll n, m;
  cin >> n >> m;

  vector<ll> a(n+1, 0);
  for(ll i = 0; i < m; i++){
    ll l, r;
    cin >> l >> r;
    a.at(l-1)++;
    a.at(r)--;
  }
  for(ll i = 0; i < n-1; i++){
    a.at(i+1) += a.at(i);
  }
  ll min_val = *min_element(a.begin(), a.end()-1);

  cout << min_val << endl;







  return 0;
  
}
