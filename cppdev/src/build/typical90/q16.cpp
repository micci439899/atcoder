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
  ll n, a, b, c;
  cin >> n >> a >> b >> c;

  ll ans = 99999;
  for(ll i = 0; i <= 9999; i++){
    for(ll j = 0; j <= 9999; j++){
      ll t = n - a*i -b*j;
      if(t < 0) continue;
        
      if(t % c == 0){
        ll k = t/c;
        ans = min(ans, i+j+k);
      }
    }
  }

  cout << ans << endl;


  return 0;  
}
