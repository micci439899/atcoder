# include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep_ll(i, n) for (ll i = 0; i < (ll)(n); i++)

template<class T> void out_vec(vector<T> &v){for(int i=0;i<(int)v.size();i++){cout<<v.at(i)<<" ";}cout<<endl;}
template<class T> void out_vec2d(vector<vector<T>> &v){for(int i=0;i<(int)v.size();i++){for(int j=0;j<(int)v.at(i).size();j++){cout<<v.at(i).at(j)<<" ";}cout<<endl;}}
void out_yn(bool b){if(b){cout << "Yes" << endl;}else{cout << "No" << endl;}}


int main() {
  int n;
  cin >> n;

  ll total = 0;
  vector<ll> a(2*n);
  rep(i, n){
    ll a_i;
    cin >> a_i;
    a_i *= 10;
    a.at(i) = a_i;
    a.at(i+n) = a_i;
    total += a_i;
  }

  ll target_size = total / 10;
  for(int left = 0; left < n; left++){
    ll sm = 0;

    // [left, right)
    int right = left;

    while(right < left + n && sm + a.at(right) <= target_size){
      sm += a.at(right);
      right++;
    }

    if(target_size == sm){
      out_yn(true);
      return 0;
    }
  }

  out_yn(false);

  return 0;  
}
