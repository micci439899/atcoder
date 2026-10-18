# include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, a, b) for (int i = (int)(a); i < (int)(b); i++)


int main() {
  ll n, m;
  cin >> n >> m;

  vector<ll> a(m+1);
  a.at(0) = 1;
  rep(i, m) {
    a.at(i+1) = a.at(i) * n;
  }

  ll ans = 0;
  rep(i, m+1){
    ans += a.at(i);
    if(ans > 1000000000){
      cout << "inf" << endl;
      return 0;
    }
  }

  cout << ans << endl;
  return 0;

}











