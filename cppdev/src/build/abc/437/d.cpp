# include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

template<class T> void out_vec(vector<T> &v){for(int i=0;i<(int)v.size();i++){cout<<v.at(i)<<" ";}cout<<endl;}
template<class T> void out_vec2d(vector<vector<T>> &v){for(int i=0;i<(int)v.size();i++){for(int j=0;j<(int)v.at(i).size();j++){cout<<v.at(i).at(j)<<" ";}cout<<endl;}}
void out_yn(bool b){if(b){cout << "Yes" << endl;}else{cout << "No" << endl;}}

const ll MOD = 998244353;
//const ll mod = 1e9 + 7;

int main() {
  ll n, m;
  cin >> n >> m;

  vector<ll> a(n);
  rep(i, n) cin >> a.at(i);

  vector<ll> b(m);
  rep(i, m) cin >> b.at(i);

  sort(a.begin(), a.end());
  sort(b.begin(), b.end());

  vector<ll> cum_a(n+1, 0);
  rep(i, n){
    cum_a.at(i+1) += cum_a.at(i) + a.at(i);
  }
  vector<ll> cum_b(m+1, 0);
  rep(i, m){
    cum_b.at(i+1) += cum_b.at(i) + b.at(i);
  }


  ll ans = 0;
  rep(i, n){
    size_t pos = 0;
    auto it = lower_bound(b.begin(), b.end(), a.at(i));
    if(it != b.end()){
      pos = distance(b.begin(), it);
    }else{
      pos = m;
    }

    // cout << "pos: " << pos << endl;
    ans += a.at(i) * pos;
    ans %= MOD;
    // cout << "a added: " << a.at(i) * pos << endl;

    ans += cum_b.at(m) - cum_b.at(pos);
    ans %= MOD;

    // cout << "b added: " << cum_b.at(m) - cum_b.at(pos) << endl;

    ans -= a.at(i) * (m-pos);
    if(ans < 0) ans += MOD;
    ans %= MOD;

    // cout << "a subtraceted: " << a.at(i) * (m-pos) << endl;

    ans -= cum_b.at(pos);
    if(ans < 0) ans += MOD;
    ans %= MOD;

    // cout << "b subtraceted: " << cum_b.at(pos) << endl;


  }
  if(ans < 0) ans += MOD;
  ans %= MOD;

  cout << ans << endl;




  return 0;
}
