# include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep_ll(i, n) for (ll i = 0; i < (ll)(n); i++)

template<class T> void out_vec(vector<T> &v){for(int i=0;i<(int)v.size();i++){cout<<v.at(i)<<" ";}cout<<endl;}
template<class T> void out_vec2d(vector<vector<T>> &v){for(int i=0;i<(int)v.size();i++){for(int j=0;j<(int)v.at(i).size();j++){cout<<v.at(i).at(j)<<" ";}cout<<endl;}}
void out_yn(bool b){if(b){cout << "Yes" << endl;}else{cout << "No" << endl;}}

// reference
// https://www.youtube.com/watch?v=W9jftsWrLQA&t=7390s

int main() {
  ll n;
  cin >> n;

  ll ans = 0;
  vector<ll> dist(n+2);
  // position, index
  set<pair<ll, ll>> st;
  // x_0
  st.emplace(0LL, 0LL);
  // 番兵
  st.emplace(2e9, n+1);
  dist.at(0) = 2e9;
  ans += dist.at(0);

  auto update = [&](ll i, ll d){
    ans -= dist.at(i);
    dist.at(i) = min(dist.at(i), d);
    ans += dist.at(i);
  };

  for(int i = 1; i <= n; i++){
    ll x;
    cin >> x;

    // setのinsertはiteratorとsetされたかどうかのpairを返す
    auto it = st.emplace(x, i).first;

    // previous iterator
    // 人0がいるので必ず前にいる
    auto prev_it = prev(it);

    // 追加した人と前の人との距離
    ll prev_dist = x - (*prev_it).first;

    //next iterator
    // 番兵がいるので必ず後ろにいる
    auto next_it = next(it);

    // 追加した人と後ろの人との距離
    ll next_dist = (*next_it).first - x;

    // 近い方
    dist.at(i) = min(prev_dist, next_dist);
    ans += dist.at(i);

    ll prev_idx = (*prev_it).second;
    update(prev_idx, prev_dist);

    ll next_idx = (*next_it).second;
    update(next_idx, next_dist);

    cout << ans << endl;
  }



  return 0;
}
