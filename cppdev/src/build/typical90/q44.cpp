# include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep_ll(i, n) for (ll i = 0; i < (ll)(n); i++)

template<class T> void out_vec(vector<T> &v){for(int i=0;i<(int)v.size();i++){cout<<v.at(i)<<" ";}cout<<endl;}
template<class T> void out_vec2d(vector<vector<T>> &v){for(int i=0;i<(int)v.size();i++){for(int j=0;j<(int)v.at(i).size();j++){cout<<v.at(i).at(j)<<" ";}cout<<endl;}}
void out_yn(bool b){if(b){cout << "Yes" << endl;}else{cout << "No" << endl;}}


int main() {
  ll n, q;
  cin >> n >> q;

  vector<ll> a(n);
  rep_ll(i, n){
    cin >> a.at(i);
  }

  ll idx = 0;
  for(;q--;){
    int t;
    ll x, y;
    cin >> t >> x >> y;
    x--; y--;

    if(t == 1){
      swap(a.at((x+idx)%n), a.at((y+idx)%n));
    }else if(t == 2){
      idx = (idx + n - 1)%n;
    }else if(t == 3){
      cout << a.at((x+idx)%n) << endl;
    }else{
      assert(false);
    }
  }





  return 0;  
}
