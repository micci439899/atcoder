#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, a, b) for (int i = (int)(a); i < (int)(b); i++)

int main() {
  ll t;
  cin >> t;

  rep(i, t){
    ll na, nb, nc;
    cin >> na >> nb >> nc;

    ll ans = min(na, nc);
    ans = min(ans, (na+nb+nc)/3);

    cout << ans << endl;
  }


  return 0;
  
}
