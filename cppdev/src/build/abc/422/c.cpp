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

    if(na < 1 || nc < 1){
      cout << 0 << endl;
      continue;
    }

    ll min_ac = min(na, nc);
    na -= min_ac;
    nc -= min_ac;

    ll ans = min(na+nb+nc, min_ac);
    if(na+nb+nc < min_ac){
      ans += na+nb+nc+min_ac/2;
    }

    cout << ans << endl;
  }






  return 0;
  
}
