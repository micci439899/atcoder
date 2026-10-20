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
  cin >> n;

  map<int, ll> a_mp;
  map<int, ll> b_mp;
  map<int, ll> c_mp;

  rep(i, n){
    int a;
    cin >> a;
    a_mp[a%46]++;
  }
  rep(i, n){
    int b;
    cin >> b;
    b_mp[b%46]++;
  }
  rep(i, n){
    int c;
    cin >> c;
    c_mp[c%46]++;
  }

  ll ans = 0;
  for(auto a_p : a_mp){
    for(auto b_p : b_mp){
      for(auto c_p : c_mp){
        if((a_p.first + b_p.first + c_p.first)%46 == 0){
          ans += a_p.second * b_p.second * c_p.second;
        }
      }
    }
  }

  cout << ans << endl;

  return 0;  
}
