# include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep_ll(i, n) for (ll i = 0; i < (ll)(n); i++)

template<class T> void out_vec(vector<T> &v){for(int i=0;i<(int)v.size();i++){cout<<v.at(i)<<" ";}cout<<endl;}
template<class T> void out_vec2d(vector<vector<T>> &v){for(int i=0;i<(int)v.size();i++){for(int j=0;j<(int)v.at(i).size();j++){cout<<v.at(i).at(j)<<" ";}cout<<endl;}}
void out_yn(bool b){if(b){cout << "Yes" << endl;}else{cout << "No" << endl;}}

vector<pair<ll, ll>> factorize(ll x){
  vector<pair<ll, ll>> res;
  for(ll i = 2LL; i*i<= x; i++){
    ll cnt = 0;
    while(x%i == 0){
      cnt++;
      x /= i;
    }
    if(cnt > 0){
      res.emplace_back(i, cnt);
    }
  }
  if(x > 1){
    res.emplace_back(x, 1);
  }
  return res;
}


int main() {
  ll n;
  cin >> n;

  vector<pair<ll, ll>> f = factorize(n);

  ll num = 0;
  rep(i, f.size()){
    auto [a, b] = f.at(i);
    num += b;
  }

  if(num == 1){
    cout << 0 << endl;
  }else{
    ll ans = 0LL;
    ll x = 1LL;
    while(true){
      x *= 2LL;
      ans++;
      if(x >= num)break;
    }
    cout << ans << endl;
  }



  return 0;  
}
