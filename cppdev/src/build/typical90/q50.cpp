# include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep_ll(i, n) for (ll i = 0; i < (ll)(n); i++)

template<class T> void out_vec(vector<T> &v){for(int i=0;i<(int)v.size();i++){cout<<v.at(i)<<" ";}cout<<endl;}
template<class T> void out_vec2d(vector<vector<T>> &v){for(int i=0;i<(int)v.size();i++){for(int j=0;j<(int)v.at(i).size();j++){cout<<v.at(i).at(j)<<" ";}cout<<endl;}}
void out_yn(bool b){if(b){cout << "Yes" << endl;}else{cout << "No" << endl;}}

const ll MD = 1e9 + 7;

int main() {
  ll n, l;
  cin >> n >> l;

  vector<ll> dp(n+1);
  dp.at(0) = 1;

  for(ll i = 1; i < n+1; i++){
    if(i < l){
      dp.at(i) = dp.at(i-1) % MD;
    }else{
      dp.at(i) = (dp.at(i-1) + dp.at(i-l)) % MD;
    }
  }

  //out_vec(dp);

  ll ans = dp.at(n) % MD;

  cout << ans << endl;




  return 0;  
}
