# include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep_ll(i, n) for (ll i = 0; i < (ll)(n); i++)

template<class T> void out_vec(vector<T> &v){for(int i=0;i<(int)v.size();i++){cout<<v.at(i)<<" ";}cout<<endl;}
template<class T> void out_vec2d(vector<vector<T>> &v){for(int i=0;i<(int)v.size();i++){for(int j=0;j<(int)v.at(i).size();j++){cout<<v.at(i).at(j)<<" ";}cout<<endl;}}
void out_yn(bool b){if(b){cout << "Yes" << endl;}else{cout << "No" << endl;}}


int main() {
  ll n;
  cin >> n;

  vector<ll> a(n);
  rep(i, n){
    cin >> a.at(i);
  }
  sort(a.begin(), a.end());

  ll q;
  cin >> q;

  vector<ll> b(q);
  rep(i, q){
    cin >> b.at(i);
  }

  rep(i, q){
    ll bi = b.at(i);
    ll val;
    auto it = lower_bound(a.begin(), a.end(), bi);
    if(it == a.begin()){
      val = abs(bi - *it);
    }else if(it == a.end()){
      val = abs(bi - *(it-1));
    }else{
      ll val1 = abs(bi - *it);
      ll val2 = abs(bi - *(it-1));
      val = min(val1, val2);
    }
    cout << val << endl;
  }

  return 0;  
}
