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
  ll n, k;
  cin >> n >> k;

  vector<ll> a(n);
  rep_ll(i, n){
    cin >> a.at(i);
  }

  vector<ll> b(n);
  rep_ll(i, n){
    cin >> b.at(i);
  }

  vector<ll> c(n);
  ll sm = 0;
  rep_ll(i, n){
    c.at(i) = abs(a.at(i) - b.at(i));
    sm += c.at(i);
  }

  if(sm > k){
    cout << "No" << endl;
    return 0;
  }

  out_yn((k - sm)%2 == 0);

  return 0;  
}
