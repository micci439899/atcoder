# include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, a, b) for (int i = (int)(a); i < (int)(b); i++)
#define rep_ll(i, n) for (ll i = 0; i < (ll)(n); i++)

template<class T> void print_vec(vector<T> &v){for(int i=0;i<(int)v.size();i++){cout<<v.at(i)<<" ";}cout<<endl;}
template<class T> void print_vec2d(vector<vector<T>> &v){for(int i=0;i<(int)v.size();i++){for(int j=0;j<(int)v.at(i).size();j++){cout<<v.at(i).at(j)<<" ";}cout<<endl;}}

int main() {
  ll n, q;
  cin >> n >> q;

  vector<ll> a(n);
  vector<int> cum_sum(n+1);
  rep_ll(i, n){
    cin >> a.at(i);
  }

  cum_sum.at(0) = 0;
  for(ll i = 1; i < n+1; i++){
    cum_sum.at(i) = cum_sum.at(i-1) + a.at(i-1);
  }

  ll idx = 0;
  rep_ll(i, q){
    int q_type;
    cin >> q_type;
    if(q_type == 1){
      ll c;
      cin >> c;
      idx += c;
      if(idx>=n){
        idx = idx%n;
      }
    } else if(q_type == 2){
      ll l, r;
      cin >> l >> r;
      l--; r--;

      if(r+idx >= n){
        ll new_idx = (r+idx)%n;
        if(r == l){
          ll res1 = cum_sum.at(new_idx+1) - cum_sum.at(new_idx);
          cout << res1 << endl;
        }else{
          ll new_l_idx = l+idx >= n+1 ? (l+idx)%n : l+idx;
          //ll res1 = cum_sum.at(n) - cum_sum.at(l+idx);
          ll res1 = cum_sum.at(n) - cum_sum.at(new_l_idx);
          ll res2 = cum_sum.at(new_idx+1);
          cout << res1 + res2 << endl;
        }

      }else{
        ll res = cum_sum.at(r+idx+1) - cum_sum.at(l+idx);
        cout << res << endl;
      }

    } else {
      // undefined
    }
  }



  return 0;
  
}
