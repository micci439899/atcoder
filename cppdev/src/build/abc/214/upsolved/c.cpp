# include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, a, b) for (int i = (int)(a); i < (int)(b); i++)
#define rep_ll(i, n) for (ll i = 0; i < (ll)(n); i++)

template<class T> void out_vec(vector<T> &v){for(int i=0;i<(int)v.size();i++){cout<<v.at(i)<<" ";}cout<<endl;}
template<class T> void out_vec2d(vector<vector<T>> &v){for(int i=0;i<(int)v.size();i++){for(int j=0;j<(int)v.at(i).size();j++){cout<<v.at(i).at(j)<<" ";}cout<<endl;}}
void out_yn(bool b){if(b){cout << "Yes" << endl;}else{cout << "No" << endl;}}



int main() {
  ll n;
  cin >> n;

  vector<ll> s(n);
  rep_ll(i, n){
    cin >> s.at(i);
  }

  vector<ll> t(n);
  rep_ll(i, n){
    cin >> t.at(i);
  }

  vector<ll> dp(n);
  dp.at(0) = t.at(0);
  for(ll i = 0; i < 2*n; i++){
    dp.at((i+1)%n) = min(dp.at(i%n) + s.at(i%n), t.at((i+1)%n));
  }

  rep_ll(i, n){
    cout << dp.at(i) << endl;
  }



  return 0;  
}
