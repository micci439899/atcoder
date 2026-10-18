#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, a, b) for (int i = (int)(a); i < (int)(b); i++)

int main() {
  ll n;
  cin >> n;

  unordered_map<ll, int> um_l;
  unordered_map<ll, int> um_r;

  vector<ll> a(n);
  cin >> a.at(0);
  um_l[a.at(0)] = 1;
  for(ll i = 1; i < n; i++){
    cin >> a.at(i);
    if(um_r.count(a.at(i))){
      um_r[a.at(i)]++;
    } else {
      um_r[a.at(i)] = 1;
    }
  }

  ll l_sz = (ll)um_l.size();
  ll r_sz = (ll)um_r.size();
  ll max_val = l_sz + r_sz;

  for(ll i = 1; i < n; i++){
    ll a_i = a.at(i);
    if(um_l.count(a_i)){
      um_l[a_i]++;
    } else {
      um_l[a_i] = 1;
      l_sz++;
    }
    um_r[a_i]--;
    if(um_r[a_i] == 0)r_sz--;

    max_val = max(max_val, l_sz + r_sz);
  }

  cout << max_val << endl;

  return 0;
  
}
