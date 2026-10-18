#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, a, b) for (int i = (int)(a); i < (int)(b); i++)

int main() {
  ll n;
  cin >> n;

  vector<ll> a(n);
  for(ll i = 0; i < n; i++){
    cin >> a.at(i);
  }


  ll cnt = 0;
  for(ll i = 0; i < n; i++){
    auto it = lower_bound(a.begin(), a.end(), 2 * a.at(i));
    if(it == a.end() && 2 * a.at(i) > a.at(n-1)){
    } else {
      cnt += a.size() - (it - a.begin());
    }
  }

  cout << cnt << endl;



  return 0;
  
}
