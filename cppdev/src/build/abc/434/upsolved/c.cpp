# include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

template<class T> void out_vec(vector<T> &v){for(int i=0;i<(int)v.size();i++){cout<<v.at(i)<<" ";}cout<<endl;}
template<class T> void out_vec2d(vector<vector<T>> &v){for(int i=0;i<(int)v.size();i++){for(int j=0;j<(int)v.at(i).size();j++){cout<<v.at(i).at(j)<<" ";}cout<<endl;}}
void out_yn(bool b){if(b){cout << "Yes" << endl;}else{cout << "No" << endl;}}


void solve(){
  ll n, h;
  cin >> n >> h;

  vector<ll> t(n);
  vector<ll> l(n);
  vector<ll> u(n);
  rep(i, n) cin >> t.at(i) >> l.at(i) >> u.at(i);

  int prev_t = 0;
  int prev_l = h;
  int prev_u = h;

  bool is_ok = true;
  rep(i, n){
    ll diff_t = t.at(i) - prev_t;
    ll new_l = prev_l - diff_t;
    ll new_u = prev_u + diff_t;

    prev_t = t.at(i);
    prev_l = max(new_l, l.at(i));
    prev_u = min(new_u, u.at(i));

    if(prev_u < prev_l){
      is_ok = false;
      break;
    }
  }
  out_yn(is_ok);
}

int main() {
  int t;
  cin >> t;

  while(t--){
    solve();
  }

  return 0;  
}
