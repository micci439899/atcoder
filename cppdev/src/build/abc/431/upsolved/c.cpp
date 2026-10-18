# include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep_ll(i, n) for (ll i = 0; i < (ll)(n); i++)

template<class T> void out_vec(vector<T> &v){for(int i=0;i<(int)v.size();i++){cout<<v.at(i)<<" ";}cout<<endl;}
template<class T> void out_vec2d(vector<vector<T>> &v){for(int i=0;i<(int)v.size();i++){for(int j=0;j<(int)v.at(i).size();j++){cout<<v.at(i).at(j)<<" ";}cout<<endl;}}
void out_yn(bool b){if(b){cout << "Yes" << endl;}else{cout << "No" << endl;}}

int main() {
  int n, m, k;
  cin >> n >> m >> k;

  vector<ll> h(n);
  rep(i, n) cin >> h.at(i);

  vector<ll> b(m);
  rep(i, m) cin >> b.at(i);

  sort(h.begin(), h.end());
  sort(b.begin(), b.end());

  rep(i, k){
    bool ng = h.at(i) > b.at(m-k+i);
    if(ng){
      out_yn(false);
      return 0;
    }
  }

  out_yn(true);



  return 0;  
}
