#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, a, b) for (int i = (int)(a); i < (int)(b); i++)

int main() {
  ll n;
  cin >> n;

  vector<ll> r(n);
  vector<ll> c(n);
  rep(i, n){
    cin >> r.at(i) >> c.at(i);
  }

  int min_r = *min_element(r.begin(), r.end());
  int max_r = *max_element(r.begin(), r.end());
  int min_c = *min_element(c.begin(), c.end());
  int max_c = *max_element(c.begin(), c.end());

  int r_dist = (max_r - min_r+1)/2;
  int c_dist = (max_c - min_c+1)/2;

  cout << max(r_dist, c_dist) << endl;



  return 0;
  
}
