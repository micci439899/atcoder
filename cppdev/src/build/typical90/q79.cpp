# include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep_ll(i, n) for (ll i = 0; i < (ll)(n); i++)

template<class T> void out_vec(vector<T> &v){for(int i=0;i<(int)v.size();i++){cout<<v.at(i)<<" ";}cout<<endl;}
template<class T> void out_vec2d(vector<vector<T>> &v){for(int i=0;i<(int)v.size();i++){for(int j=0;j<(int)v.at(i).size();j++){cout<<v.at(i).at(j)<<" ";}cout<<endl;}}
void out_yn(bool b){if(b){cout << "Yes" << endl;}else{cout << "No" << endl;}}


int main() {
  int h, w;
  cin >> h >> w;

  vector<vector<int>> a(h, vector<int>(w));
  rep(i, h)rep(j, w) cin >> a.at(i).at(j);

  vector<vector<int>> b(h, vector<int>(w));
  rep(i, h)rep(j, w) cin >> b.at(i).at(j);

  ll ans = 0LL;
  rep(i, h-1)rep(j, w-1){
    int c = b.at(i).at(j) - a.at(i).at(j);
    a.at(i).at(j) += c;
    a.at(i+1).at(j) += c;
    a.at(i).at(j+1) += c;
    a.at(i+1).at(j+1) += c;
    ans += c > 0 ? c : -c;
  }

  rep(i, h)rep(j, w){
    if(a.at(i).at(j) != b.at(i).at(j)){
      cout << "No" << endl;
      return 0;
    }
  }
  cout << "Yes" << endl;
  cout << ans << endl;




  return 0;  
}
