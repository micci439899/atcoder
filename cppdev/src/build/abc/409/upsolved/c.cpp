# include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep_ll(i, n) for (ll i = 0; i < (ll)(n); i++)

template<class T> void out_vec(vector<T> &v){for(int i=0;i<(int)v.size();i++){cout<<v.at(i)<<" ";}cout<<endl;}
template<class T> void out_vec2d(vector<vector<T>> &v){for(int i=0;i<(int)v.size();i++){for(int j=0;j<(int)v.at(i).size();j++){cout<<v.at(i).at(j)<<" ";}cout<<endl;}}
void out_yn(bool b){if(b){cout << "Yes" << endl;}else{cout << "No" << endl;}}

int main() {
  int n, l;
  cin >> n >> l;

  map<ll, ll> d_mp;
  d_mp[0]++;
  ll prev = 0LL;
  rep(i, n-1){
    ll d;
    cin >> d;
    d = (prev + d) % l;
    d_mp[d]++;
    prev = d;
  }

  if(l%3 != 0){
    cout << 0 << endl;
    return 0;
  }

  ll res = 0;
  rep(i, l/3){
    res += d_mp[i] * d_mp[i + l/3] * d_mp[i + l/3*2];
  }
  cout << res << endl;

  return 0;  
}
