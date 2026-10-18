#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, a, b) for (int i = (int)(a); i < (int)(b); i++)

int main() {
  ll n, k;
  cin >> n >> k;

  if (n < k) {
    cout << 1 << endl;
    return 0;
  }

  vector<ll> a(n+1);
  for(int i = 0; i < k; i++) {
    a.at(i) = 1;
  }
  ll head = a.at(0);
  ll rest = k-1;
  for(int i = k; i < n+1; i++) {
    a.at(i) = (head + rest) % 1000000000;
    rest -= a.at(i-k+1);
    rest += a.at(i);
    head = a.at(i-k+1);
  }

  ll ans = a.at(n) % 1000000000;
  cout << ans << endl;



  return 0;
  
}
