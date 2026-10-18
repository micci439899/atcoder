#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, a, b) for (int i = (int)(a); i < (int)(b); i++)

int main() {
  ll n;
  cin >> n;

  vector<ll> a(60);
  a.at(0) = 2;
  for(int i = 0; i < 59; i++) {
    a.at(i+1) = a.at(i) * 2;
  }


  //set<int> s;
  ll ans = 0;
  rep(i, a.size()){
    if(n < a.at(i)) break;

    ll m = n/a.at(i);
    for(ll j = 1; j*j <= m; j+=2) {
      ans++;
      ll x = (a.at(i) * j * j);
      //s.insert(x);

      //cout << x << " = 2^" << i+1 << " * " << j << "^2" << endl;
    }
  }

  //cout << s.size() << endl;
  cout << ans << endl;




  return 0;
  
}
