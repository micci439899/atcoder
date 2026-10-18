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
  string s;
  cin >> n >> s;

  ll ans1 = 0;
  int idx1 = 0;
  rep(i, 2*n) {
    if(s.at(i) == 'A') {
      ans1 += abs(idx1 - i);
      idx1 += 2;
    }
  }

  ll ans2 = 0;
  int idx2 = 1;
  rep(i, 2*n) {
    if(s.at(i) == 'A') {
      ans2 += abs(idx2 - i);
      idx2 += 2;
    }
  }

  ll ans = min(ans1, ans2);

  cout << ans << endl;




  return 0;  
}
