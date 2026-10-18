# include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, a, b) for (int i = (int)(a); i < (int)(b); i++)


int main() {
  int N, K;
  cin >> N >> K;

  ll y = 1LL;
  rep(i, K){
    y *= 10;
  }
  y--;

  ll ans = 1LL;
  rep(i, N) {
    ll A;
    cin >> A;

    if (ans > (y/A)) {
      ans = 1LL;
    } else {
      ans *= A;
    }
  }

  cout << ans << endl;

  return 0;
}











