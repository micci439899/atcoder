# include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep_ll(i, n) for (ll i = 0; i < (ll)(n); i++)

template<class T> void out_vec(vector<T> &v){for(int i=0;i<(int)v.size();i++){cout<<v.at(i)<<" ";}cout<<endl;}
template<class T> void out_vec2d(vector<vector<T>> &v){for(int i=0;i<(int)v.size();i++){for(int j=0;j<(int)v.at(i).size();j++){cout<<v.at(i).at(j)<<" ";}cout<<endl;}}
void out_yn(bool b){if(b){cout << "Yes" << endl;}else{cout << "No" << endl;}}

int main() {
  int n;
  cin >> n;

  map<ll, ll> mp;
  rep(i, n){
    ll a;
    cin >> a;
    mp[a]++;
  }

  if(mp.size() == 1){
    cout << 0 << endl;
    return 0;
  }

  ll ans = 0;
  for(auto [f, s] : mp){
    if(s == 1LL) continue;

    ans += (s*(s-1)/2) * (n-s);
  }

  cout << ans << endl;




  return 0;  
}
