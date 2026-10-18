#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, a, b) for (int i = (int)(a); i < (int)(b); i++)


int main() {
  ll n, m;
  cin >> n >> m;

  string s, t;
  cin >> s >> t;

  vector<ll> a(n+1);
  rep(i, m){
    ll l, r;
    cin >> l >> r;
    a.at(l-1)++;
    a.at(r)--;
  }

  rep(i, n-1){
    a.at(i+1) += a.at(i);
  }

  rep(i, n){
    if(a.at(i)%2==0){
      cout << s.at(i);
    } else {
      cout << t.at(i);
    }
  }
  cout << endl;



  return 0;
}
