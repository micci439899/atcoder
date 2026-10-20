# include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep_ll(i, n) for (ll i = 0; i < (ll)(n); i++)

template<class T> void out_vec(vector<T> &v){for(int i=0;i<(int)v.size();i++){cout<<v.at(i)<<" ";}cout<<endl;}
template<class T> void out_vec2d(vector<vector<T>> &v){for(int i=0;i<(int)v.size();i++){for(int j=0;j<(int)v.at(i).size();j++){cout<<v.at(i).at(j)<<" ";}cout<<endl;}}
void out_yn(bool b){if(b){cout << "Yes" << endl;}else{cout << "No" << endl;}}


int main() {
  int n, q;
  cin >> n >> q;

  vector<ll> a(n);
  rep(i, n) cin >> a.at(i);

  ll diff_sum = 0;
  vector<ll> diff(n-1);
  rep(i, n-1){
    diff.at(i) = a.at(i) - a.at(i+1);
    diff_sum += abs(diff.at(i));
  }

  while(q--){
    ll l, r, v;
    cin >> l >> r >> v;
    l--; r--;

    if(l != 0){
      diff_sum -= abs(diff.at(l-1));
      diff.at(l-1) -= v;
      diff_sum += abs(diff.at(l-1));
    }

    if(r != n-1){
      diff_sum -= abs(diff.at(r));
      diff.at(r) += v;
      diff_sum += abs(diff.at(r));
    }

    cout << diff_sum << endl;
  }




  return 0;  
}
