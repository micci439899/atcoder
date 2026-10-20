# include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep_ll(i, n) for (ll i = 0; i < (ll)(n); i++)

template<class T> void out_vec(vector<T> &v){for(int i=0;i<(int)v.size();i++){cout<<v.at(i)<<" ";}cout<<endl;}
template<class T> void out_vec2d(vector<vector<T>> &v){for(int i=0;i<(int)v.size();i++){for(int j=0;j<(int)v.at(i).size();j++){cout<<v.at(i).at(j)<<" ";}cout<<endl;}}
void out_yn(bool b){if(b){cout << "Yes" << endl;}else{cout << "No" << endl;}}

int main() {
  int n, k;
  cin >> n >> k;

  vector<ll> c;
  rep(i, n){
    ll a, b;
    cin >> a >> b;
    c.push_back(b);
    c.push_back(a-b);
  }

  sort(c.rbegin(), c.rend());

  ll ans = 0LL;
  rep(i, k){
    ans += c.at(i);
  }

  cout << ans << endl;





  return 0;  
}
