# include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep_ll(i, n) for (ll i = 0; i < (ll)(n); i++)

template<class T> void out_vec(vector<T> &v){for(int i=0;i<(int)v.size();i++){cout<<v.at(i)<<" ";}cout<<endl;}
template<class T> void out_vec2d(vector<vector<T>> &v){for(int i=0;i<(int)v.size();i++){for(int j=0;j<(int)v.at(i).size();j++){cout<<v.at(i).at(j)<<" ";}cout<<endl;}}
void out_yn(bool b){if(b){cout << "Yes" << endl;}else{cout << "No" << endl;}}

int main() {
  string s;
  cin >> s;

  if(s.size() == 1){
    cout << 0 << endl;
    return 0;
  }

  int num = s.at(0) - '0';
  int cnt = 1;

  vector<pair<int, int>> rle;
  for(int i = 1; i < (int)s.size(); i++){
    int cur = s.at(i) - '0';
    if(num != cur){
      rle.emplace_back(num, cnt);
      num = cur;
      cnt = 1;
    }else{
      cnt++;
    }

    if(i == (int)s.size()-1) rle.emplace_back(num, cnt);
  }

  ll ans = 0LL;

  auto [prev_num, prev_cnt] = rle.at(0);
  for(int i = 1; i < (int)rle.size(); i++){
    auto [cur_num, cur_cnt] = rle.at(i);
    if(prev_num+1 == cur_num){
      ll mi = min(prev_cnt, cur_cnt);
      ans += mi;
    }
    prev_num = cur_num;
    prev_cnt = cur_cnt;
  }

  cout << ans << endl;



  return 0;  
}
