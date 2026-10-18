# include <bits/stdc++.h>
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
template<class T, class U>ostream&operator<<(ostream&os, map<T,U>mp){os<<"{";int idx=0;for(auto p : mp){cout << p;if(idx != mp.size()-1){cout << ",";}idx++;}os<<"}";return os;}

template<class T> void out_vec(vector<T> &v){for(int i=0;i<(int)v.size();i++){cout<<v.at(i)<<" ";}cout<<endl;}
template<class T> void out_vec2d(vector<vector<T>> &v){for(int i=0;i<(int)v.size();i++){for(int j=0;j<(int)v.at(i).size();j++){cout<<v.at(i).at(j)<<" ";}cout<<endl;}}
void out_yn(bool b){if(b){cout << "Yes" << endl;}else{cout << "No" << endl;}}
int ctoi(char c){return int(c-'0');} // e.g.) a -> 49, 1 -> 1
char itoc(int x){return x+'0';}

// FenwickTree(Binary Indexed Tree)
// 下記参考
// https://qiita.com/DaikiSuyama/items/7295f5160a51684554a7
// https://algo-logic.info/binary-indexed-tree/
template<typename T>
struct FenwickTree {
  int n;
  vector<T> bit;

  FenwickTree(int n_) : n(n_+1), bit(n_+1, 0){}

  // 1点更新
  // 0-indexed
  void add(int i, T x){
    // 内部的には1-indexed
    i++;
    for(int idx = i; idx < n; idx += (idx & -idx)){
      bit.at(idx) += x;
    }
  }

  // a_0 + ... + a_i
  // 0-indexed
  T sum(int i){
    // 内部的には1-indexed
    i++;
    T sm(0);
    for(int idx = i; idx > 0; idx -= (idx & -idx)){
      sm += bit.at(idx);
    }
    return sm;
  }
};



void solve(){
  ll n; cin >> n;

  vector<pll> xy(n);
  rep(i, n){
    ll x, y; cin >> x >> y;
    xy.at(i) = {x, y};
  }
  sort(xy.begin(), xy.end());

  // debug(xy);

  ll ans = 0;
  rep(i, n){
    if(xy.at(i).second < xy.at(i).first) ans++;
  }
  cout << ans << endl;


/*
  vector<pll> xy(n);
  rep(i, n){
    ll x, y; cin >> x >> y;
    xy.at(i) = {x, y};
  }
  sort(xy.begin(), xy.end());

  auto [x0, y0] = xy.at(0);
  vector<bool> is_ok(n, true);

  for(int i = 1; i < n; i++){
    if(x0 < xy.at(i).first && y0 < xy.at(i).second) is_ok.at(i) = false;
  }

  ll ans = 0;
  rep(i, n){
    if(is_ok.at(i)) ans++;
  }
  cout << ans << endl;
*/


/*
  // vector<pll> xy(n);
  vector<pii> xy(n);
  // vector<pll> yx(n);
  rep(i, n){
    // ll x, y; cin >> x >> y;
    int x, y; cin >> x >> y;
    xy.at(i) = {x, y};
    // yx.at(i) = {y, x};
  }
  sort(xy.begin(), xy.end());
  // sort(yx.begin(), yx.end());

  debug(xy);
  // debug(yx);

  FenwickTree<int> tree(n);
  int ans = 0;
  rep(i, n){
    ans += i - tree.sum(xy.at(i).second-1);
    tree.add(xy.at(i).second-1, 1);


    // if(i == 0) ans++;    
    // ll l = 0; r = i;
    // if(r - l > 1){

    // }

    // auto it = lower_bound(xy.begin(), xy.begin() + i, {-1LL, xy.at(i).second}
    //   , [](const pll xy1, const pll xy2) { return xy1.second > xy2.second; }
    // );
    // if(it == xy.end()){
    //   ans++;
    // }
  }
  cout << ans << endl;
*/

}



int main() {

  solve();

  return 0;
}
