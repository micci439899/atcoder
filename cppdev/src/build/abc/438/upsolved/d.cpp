# include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

template<class T> inline bool chmax(T& a, const T& b){if(a<b){a = b;return true;}return false;}

template<class T> void out_vec(vector<T> &v){for(int i=0;i<(int)v.size();i++){cout<<v.at(i)<<" ";}cout<<endl;}
template<class T> void out_vec2d(vector<vector<T>> &v){for(int i=0;i<(int)v.size();i++){for(int j=0;j<(int)v.at(i).size();j++){cout<<v.at(i).at(j)<<" ";}cout<<endl;}}
void out_yn(bool b){if(b){cout << "Yes" << endl;}else{cout << "No" << endl;}}

// reference
// https://atcoder.jp/contests/abc438/editorial/14963

// d_i := \sum_{j=0}^{i-1} a_j
// e_i := \sum_{j=0}^{i-1} b_j
// f_i := \sum_{j=0}^{i-1} c_j

// ans = \sum_{i=0}^{x-1} a_i
// + \sum_{i=0}^{x-1} b_i
// + \sum_{i=0}^{x-1} c_i
// =
// a_0 + ... + a_{x-1}
// +
// b_x + ... + b_{y-1}
// +
// c_y + ... + c_{n-1}
// =
// a_0 + ... + a_{x-1}
// -(b_0 + ... + b_{x-1})
// +(b_0 + ... + b_{x-1}) + b_x + ... + b_{y-1}
// -(c_0 + ... + c_{y-1})
// +(c_0 + ... + c_{y-1}) + c_y + ... + c_{n-1}
// = d_x - e_x + e_y - f_y + f_n

// g_i := d_i - e_i
// h_i := e_i - f_i

// (x, y)
// (0, 1)
// (0, 2), (1, 2)
// (0, 3), (1, 3), (2, 3)
// ...
// (0, n-1), (1, n-1), ..., (n-2, n-1)
// の組み合わせのいずれか

// y=1~n-1を走査していく中で
// x=0~y-1のmaxも分かる

const ll INFL = LONG_LONG_MAX/2;

int main() {
  ll n;
  cin >> n;

  vector<ll> a(n);
  rep(i, n) cin >> a.at(i);

  vector<ll> b(n);
  rep(i, n) cin >> b.at(i);

  vector<ll> c(n);
  rep(i, n) cin >> c.at(i);

  // 公式解説でいうd ~ f
  vector<ll> cum_a(n+1);
  vector<ll> cum_b(n+1);
  vector<ll> cum_c(n+1);

  // 公式解説でいうg ~ h
  vector<ll> cum_diff_ab(n+1);
  vector<ll> cum_diff_bc(n+1);

  rep(i, n){
    cum_a.at(i+1) = cum_a.at(i) + a.at(i);
    cum_b.at(i+1) = cum_b.at(i) + b.at(i);
    cum_c.at(i+1) = cum_c.at(i) + c.at(i);

    cum_diff_ab.at(i+1) = cum_a.at(i+1) - cum_b.at(i+1);
    cum_diff_bc.at(i+1) = cum_b.at(i+1) - cum_c.at(i+1);
  }

  // 0 ~ y-1までのmax（つまりxの箇所までの累積和）
  // y=0は条件を満たさないので初期値を-inf（と思われる）
  ll diff_sm_max = - INFL;

  // cの累積和
  ll c_sm = cum_c.at(n);

  ll ans = 0LL;
  for(int i = 1; i < n; i++){
    // g_x + h_y + f_n
    ll sm_all = diff_sm_max + cum_diff_bc.at(i) + c_sm;

    ans = max(ans, sm_all);

    // g_x更新
    diff_sm_max = max(diff_sm_max, cum_diff_ab.at(i));
  }


  cout << ans << endl;

  return 0;
}
