// The template file is below
// https://github.com/micci439899/atcoder

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using uint = unsigned;
using ull = unsigned long long;
using pii = pair<int, int>;
using pll = pair<long long, long long>;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define debug(x) cerr << #x << " " << x << " " << endl;

template<class T>using min_priority_queue = priority_queue<T, vector<T>, greater<T>>;
template<class T>bool chmax(T&a, T b){if(a<b){a=b;return true;}return false;}
template<class T>bool chmin(T&a, T b){if(b<a){a=b;return true;}return false;}

template<class T, class U>ostream&operator<<(ostream&os, pair<T,U>p){os<<"("<<p.first << "," << p.second<<")";return os;}
template<class T>ostream&operator<<(ostream&os, const vector<T>&v){os<<"[";for(int i = 0; i < v.size(); i++){cout << v.at(i);if(i != v.size()-1){cout << ",";}}os<<"]";return os;}
template<class T>ostream&operator<<(ostream&os, const set<T>&st){os<<"{";int idx=0;for(auto &e : st){cout << e;if(idx != st.size()-1){cout << ",";}idx++;}os<<"}";return os;}
template<class T>ostream&operator<<(ostream&os, const multiset<T>&st){os<<"{";int idx=0;for(auto &e : st){cout << e;if(idx != st.size()-1){cout << ",";}idx++;}os<<"}";return os;}
template<class T, class U>ostream&operator<<(ostream&os, map<T,U>mp){os<<"{";int idx=0;for(auto p : mp){cout << p;if(idx != mp.size()-1){cout << ",";}idx++;}os<<"}";return os;}

template<class T> void out_vec(vector<T> &v){for(int i=0;i<(int)v.size();i++){cout<<v.at(i)<<" ";}cout<<endl;}
template<class T> void out_vec2d(vector<vector<T>> &v){for(int i=0;i<(int)v.size();i++){for(int j=0;j<(int)v.at(i).size();j++){cout<<v.at(i).at(j)<<" ";}cout<<endl;}}
void out_yn(bool b){if(b){cout << "Yes" << endl;}else{cout << "No" << endl;}}
int ctoi(char c){return int(c-'0');} // e.g.) a -> 49, 1 -> 1
char itoc(int x){return x+'0';}


const long double PI = 3.1415926535;


// 自分の提出コードより（ライブラリ化してません...）
// --------------------------
// https://atcoder.jp/contests/abc442/submissions/72977411
// クロス積（外積）
// 2次元座標平面におけるベクトル同士のクロス積におけるz座標相当
ll cross_product(const pll &a, const pll &b){
  return a.first * b.second - b.first * a.second;
}
bool cmp(const pll &a, const pll &b){
  // 下半平面にいるか
  // より具体的には、y座標が0未満もしくはx軸上でx座標が負
  // （x軸上からの反時計回りでの角度を考えたとき、半開区間）
  bool is_low_a = a.second < 0 || (a.second == 0 && a.first < 0);
  bool is_low_b = b.second < 0 || (b.second == 0 && b.first < 0);

  // どちらかが上でどちらかが下
  // aが上ならaの方が角度が小さい
  if(is_low_a != is_low_b) return !is_low_a;

  // 同じ半平面ならクロス積（のz座標）が大きいときaの方が角度が小さい
  return cross_product(a, b) > 0;
}

// https://atcoder.jp/contests/awc0103/submissions/77995251
ll cross_product(const pair<long long, long long> &o, const pair<long long, long long> &a, const pair<long long, long long> &b){
  return (o.first - a.first) * (o.second - b.second) - (o.second - a.second) * (o.first - b.first);
}
// --------------------------

long double find_angle(const pll &a, const pll &b){
  ll c = cross_product(a, b);
  // ll c = cross_product({0LL, 0LL}, a, b);

  long double a_len = sqrt(a.first*a.first + a.second*a.second);
  long double b_len = sqrt(b.first*b.first + b.second*b.second);

  return asin((long double)c / a_len / b_len);
}



void testcase(){
  ll n; cin >> n;

  vector<pll> xy(n);
  rep(i, n){
    ll x, y; cin >> x >> y;
    xy.at(i) = {x, y};
  }
  sort(xy.begin(), xy.end(), cmp);

  vector<long double> cum_angle(2*n+1, 0);
  rep(i, 2*n){
    long double angle = find_angle(xy.at(i%n), xy.at((i+1)%n));
    cum_angle.at(i+1) = cum_angle.at(i) + abs(angle);
  }

  ll ans = 0;
  rep(i, n){
    long double angle = cum_angle.at(i);
    auto it = lower_bound(cum_angle.begin(), cum_angle.end(), angle+PI/2);
    ll idx = lower_bound(cum_angle.begin(), cum_angle.end(), angle+PI/2) - cum_angle.begin();
    ans = max(ans, n-(idx-i));
    // ans = max(ans, n-idx);
    // if(it != cum_angle.end()){
    //   debug(i);
    //   debug(*it);
    //   debug(idx);
    // }
  }
  cout << ans << endl;




/*
  long double res = find_angle(xy.front(), xy.back());
  long double res2 = find_angle(xy.back(), xy.front());
  debug(res);
  debug(res2);
*/

/*
  debug(xy);
  for(int i = 1; i < n; i++){
    // ll res = cross_product(xy.at(0), xy.at(i));
    long double res = find_angle(xy.at(0), xy.at(i));
    long double res2 = res*180.00/PI;
    if(res2<0) res2 += 360.00;

    debug(res);
    debug(res2);

  }
*/
  // for(int i = 0; i < n-1; i++){
  //   ll res = cross_product({0LL, 0LL}, xy.at(i), xy.at(i+1));
  //   debug(res);
  // }

}

void solve(){
  // 解けず
  // 偏角ソートして各点+180度までにある星の数で行けそうな気はした
  ll t; cin >> t;
  while(t--){
    testcase();
  }
}

int main() {
  solve();
  return 0;
}
