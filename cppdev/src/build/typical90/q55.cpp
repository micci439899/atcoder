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
  int n;
  ll p, q;
  cin >> n >> p >> q;

  vector<ll> a(n);
  rep(i, n){
    cin >> a.at(i);
  }

  int ans = 0;
  for(ll i = 0; i < a.size(); i++){
    ll tmp1 = a.at(i) % p;
    for(ll j = i+1; j < a.size(); j++){
      ll tmp2 = (tmp1 * a.at(j)) % p;
      for(ll k = j+1; k < a.size(); k++){
        ll tmp3 = (tmp2 * a.at(k)) % p;
        for(ll l = k+1; l < a.size(); l++){
          ll tmp4 = (tmp3 * a.at(l)) % p;
          for(ll m = l+1; m < a.size(); m++){
            ll tmp5 = a.at(m) % p;
            if((tmp4 * tmp5) % p == q){
              ans++;
            }
          }
        }
      }
    }
  }

  cout << ans << endl;

  return 0;  
}
