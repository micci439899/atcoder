# include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep_ll(i, n) for (ll i = 0; i < (ll)(n); i++)

template<class T> void out_vec(vector<T> &v){for(int i=0;i<(int)v.size();i++){cout<<v.at(i)<<" ";}cout<<endl;}
template<class T> void out_vec2d(vector<vector<T>> &v){for(int i=0;i<(int)v.size();i++){for(int j=0;j<(int)v.at(i).size();j++){cout<<v.at(i).at(j)<<" ";}cout<<endl;}}
void out_yn(bool b){if(b){cout << "Yes" << endl;}else{cout << "No" << endl;}}

// reference
// https://www.youtube.com/watch?v=9lm2NUh-_yQ

int main() {
  ll n, m, c;
  cin >> n >> m >> c;

  // key:地点、value:人数
  map<ll, int> mp;
  rep(i, n){
    ll a_i;
    cin >> a_i;
    mp[a_i]++;
  }

  // 地点、人数の2周分
  vector<pair<ll, int>> d;
  for(auto p : mp) d.emplace_back(p);
  for(auto p : mp) d.emplace_back(p.first+m, p.second);

  // 人のいる地点の数
  int pos_sz = mp.size();

  // 1つ前の（人のいる）地点
  // l=0のとき最後の地点〜最初の地点（負の値になる）
  ll prev_x = d.at(pos_sz-1).first - m;

  int r = 0;
  int current_p_num = 0;
  ll ans = 0;
  rep(l, pos_sz){
    while(current_p_num < c){
      current_p_num += d.at(r).second;
      r++;
    }

    auto [x, p_num] = d.at(l);
    ans += current_p_num * (x - prev_x);
    prev_x = x;

    // 次の人のいる地点のとき、今いる地点の人数分だけ減らす（差分）
    current_p_num -= p_num;
  }

  cout << ans << endl;

  return 0;
}
