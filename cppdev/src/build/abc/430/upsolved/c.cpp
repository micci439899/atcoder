# include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep_ll(i, n) for (ll i = 0; i < (ll)(n); i++)

template<class T> void out_vec(vector<T> &v){for(int i=0;i<(int)v.size();i++){cout<<v.at(i)<<" ";}cout<<endl;}
template<class T> void out_vec2d(vector<vector<T>> &v){for(int i=0;i<(int)v.size();i++){for(int j=0;j<(int)v.at(i).size();j++){cout<<v.at(i).at(j)<<" ";}cout<<endl;}}
void out_yn(bool b){if(b){cout << "Yes" << endl;}else{cout << "No" << endl;}}


ll binary_search_a(vector<ll> &cum_sum, ll l, ll r, ll a){
  // cout << "binary search a" << endl;
  // 固定（ここからの累積が知りたい）
  ll l_init = l;
  auto is_ok = [&](ll mid, ll l){
    return cum_sum.at(mid) - cum_sum.at(l) >= a;
  };
  while(r - l > 1){
    ll mid = l + (r-l)/2;
    // cout << "mid: " << mid << endl;
    if(is_ok(mid, l_init)){
      r = mid;
      // cout << "ok, r: " << r << endl;
    }else{
      l = mid;
      // cout << "ng, l: " << l << endl;
    }
  }
  return r;
}

ll binary_search_b(vector<ll> &cum_sum, ll l, ll r, ll b){
  // cout << "binary search b" << endl;
  // 固定（ここからの累積が知りたい）
  ll l_init = l;
  auto is_ok = [&](ll mid, ll l){
    // 条件に気を付ける
    return cum_sum.at(mid) - cum_sum.at(l) >= b;
  };
  while(r - l > 1){
    ll mid = l + (r-l)/2;
    // cout << "mid: " << mid << endl;
    if(is_ok(mid, l_init)){
      r = mid;
      // cout << "ok, r: " << r << endl;
    }else{
      l = mid;
      // cout << "ng, l: " << l << endl;
    }
  }
  return r;
}


int main() {
  ll n, a, b;
  cin >> n >> a >> b;

  string s;
  cin >> s;

  vector<ll> cum_sum_a(n+1, 0);
  vector<ll> cum_sum_b(n+1, 0);

  rep(i, n){
    cum_sum_a.at(i+1) = cum_sum_a.at(i) + (s.at(i) == 'a' ? 1 : 0);
    cum_sum_b.at(i+1) = cum_sum_b.at(i) + (s.at(i) == 'b' ? 1 : 0);
  }

  // cout << "cum_sum_a" << endl;
  // out_vec(cum_sum_a);
  // cout << "cum_sum_b" << endl;
  // out_vec(cum_sum_b);

  ll ans = 0;
  rep(i, n){
    ll l = i, r = n+1;
    ll ra = binary_search_a(cum_sum_a, l, r, a);
    ll rb = binary_search_b(cum_sum_b, l, r, b);

    // cout << "ra: " << ra << " rb: " << rb << endl;

    ans += max(0LL, rb-ra);
  }

  cout << ans << endl;








  return 0;  
}
