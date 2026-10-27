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


// クロス積（外積）
// 2次元座標平面におけるベクトル同士のクロス積におけるz座標相当
long long cross_product(const pair<long long, long long> &a, const pair<long long, long long> &b){
  return a.first * b.second - b.first * a.second;
}

bool cmp(const pair<long long, long long> &a, const pair<long long, long long> &b){
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

void testcase(){
  ll n; cin >> n;

  vector<pll> xy(n);
  rep(i, n){
    ll x, y; cin >> x >> y;
    xy.at(i) = {x, y};
  }
  sort(xy.begin(), xy.end(), cmp);

  vector<pll> xy2(2*n);
  rep(i, n){
    xy2.at(i) = xy.at(i);
    xy2.at(i+n) = xy.at(i);
  }

  ll r = 1;
  ll ans = 1;
  rep(l, n){
    r = max(r, (ll)l+1);
    while(r < l+n && cross_product(xy2.at(l), xy2.at(r)) > 0){
      r++;
    }
    ans = max(ans, r-l);
  }
  cout << ans << endl;
}

void solve(){
  ll t; cin >> t;
  while(t--){
    testcase();
  }
}

int main() {
  solve();
  return 0;
}
