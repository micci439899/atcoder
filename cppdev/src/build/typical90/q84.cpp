# include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

template<class T> void out_vec(vector<T> &v){for(int i=0;i<(int)v.size();i++){cout<<v.at(i)<<" ";}cout<<endl;}
template<class T> void out_vec2d(vector<vector<T>> &v){for(int i=0;i<(int)v.size();i++){for(int j=0;j<(int)v.at(i).size();j++){cout<<v.at(i).at(j)<<" ";}cout<<endl;}}
void out_yn(bool b){if(b){cout << "Yes" << endl;}else{cout << "No" << endl;}}

int main() {
  int n;
  cin >> n;
  string s;
  cin >> s;

  if(n == 1){
    cout << 0 << endl;
    return 0;
  }

  vector<pair<char, ll>> rle;
  char c = s.at(0);
  ll cnt = 1;
  for(int i = 1; i < n; i++){
    if(s.at(i) != c){
      rle.emplace_back(c, cnt);
      cnt = 1;
      c = s.at(i);
    }else{
      cnt++;

    }
    if(i == n-1) rle.emplace_back(c, cnt);
  }



  ll sm = 0;
  rep(i, rle.size()){
    auto [c, cnt] = rle.at(i);
    sm += cnt * (cnt+1) / 2LL;
  }

  ll ans = (ll)n * (ll)(n+1)/2LL - sm;
  cout << ans << endl;



  return 0;  
}
