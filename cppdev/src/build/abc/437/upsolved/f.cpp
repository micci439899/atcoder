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

template <typename T>
struct SegmentTree {
  // 1-indexedのSegment Tree
  // ただし、外からは0-indexedとみなすことができる

  // 演算、単位元
  function<T(T,T)> op;
  T e;

  // 元のデータサイズ
  int n;

  // SegmentTreeで管理するデータ
  vector<T> x;

  // SegmentTreeで確保したデータから実データにアクセスするためのoffset
  int offset;

  SegmentTree(int N, function<T(T,T)> op, T e) : op(op), e(e) {
    initialize(N);
  }
  SegmentTree(const vector<T> &v, const function<T(T,T)> op, T e) : op(op), e(e) {
    initialize((int)v.size());
    build(v);
  }

  void initialize(int N) {
    n = N;
    offset = 1;
    while(offset < N) offset *= 2;
    x.assign(2*offset, e);
  }

  void build(const vector<T> &v) {
    for(int i = 0; i < (int)v.size(); i++) x.at(i + offset) = v.at(i);
    for(int i = offset-1; i > 0; i--) x.at(i) = op(x.at(i*2), x.at(i*2+1));
  }

  // 1点更新(O(log N))
  // i: 0-indexed
  void set(int i, T val) {
    // 実データは[offset, 2*offset)
    i += offset;
    x.at(i) = val;

    // 親をたどる
    while(i > 1) {
      i /= 2;
      x.at(i) = op(x.at(2*i), x.at(2*i+1));
    }
  }

  // 指定区間に対する演算結果を取得(O(log N))
  // [l, r)
  T prod(int l, int r) {
    // 実データは[offset, 2*offset)
    l += offset;
    r += offset;
    T l_val = e;
    T r_val = e;

    while(l < r) {
      // lが親から見て右の子のときlの値を計算
      if(l % 2 == 1) {
        l_val = op(l_val, x.at(l));
        l++;
      }

      // r-1が親から見て左の子のときr-1の値を計算
      if(r % 2 == 1) {
        r--;
        r_val = op(x.at(r), r_val);
      }
      // 親（1段上）に
      l /= 2;
      r /= 2;
    }
    return op(l_val, r_val);
  }

  // 
  int max_right(const function<bool(T)> f, int l = 0) {
    if(l == n) return n;
    l += offset;
    T sm = e;
    do {
      while(l%2 == 0) l >>= 1;
      if(!f(op(sm, x.at(l)))) {
        while(l < offset) {
          l = l * 2;
          if(f(op(sm, x.at(l)))) {
            sm = op(sm, x.at(l));
            l++;
          }
        }
        return l - offset;
      }
      sm = op(sm, x.at(l));
      l++;
    } while((l & -l) != l);
    return n;
  }

  int min_left(const function<bool(T)> f, int r = -1) {
    if(r == 0) return 0;
    if(r == -1) r = n;
    r += offset;
    T sm = e;
    do {
      r--;
      while(r > 1 && (r%2)) r >>= 1;
      if(!f(op(x.at(r), sm))){
        while(r < offset) {
          r = r * 2 + 1;
          if(f(op(x.at(r), sm))) {
            sm = op(x.at(r), sm);
            r--;
          }
        }
        return r + 1 - offset;
      }
      sm = op(x.at(r), sm);
    } while((r & -r) != r);
    return 0;
  }

  // debug用
  void out() {
    // 改行する要素番号（0-indexed）
    int br_num = 1;
    for(int i = 0; i < (int)x.size(); i++) {
      if(i == 0) continue;
      cout << x.at(i) << " ";
      if(br_num == i){
        cout << endl;
        // 2^(n-1) - 1から2^n - 1
        br_num = (br_num+1)*2-1;
      }
    }
  }
};

const ll INFL = 1LL<<60;

void solve(){
  int n, q; cin >> n >> q;

  vector<ll> u(n);
  vector<ll> v(n);
  rep(i, n){
    ll x, y; cin >> x >> y;
    u.at(i) = x + y;
    v.at(i) = x - y;
  }

  SegmentTree<ll> u_ma_tree(u, [&](ll x, ll y){ return max(x, y);}, -INFL);
  SegmentTree<ll> u_mi_tree(u, [&](ll x, ll y){ return min(x, y);}, INFL);
  SegmentTree<ll> v_ma_tree(v, [&](ll x, ll y){ return max(x, y);}, -INFL);
  SegmentTree<ll> v_mi_tree(v, [&](ll x, ll y){ return min(x, y);}, INFL);

  while(q--){
    int t; cin >> t;
    if(t == 1){
      int i; ll x, y; cin >> i >> x >> y;
      i--;
      ll ui = x + y;
      ll vi = x - y;
      u_ma_tree.set(i, ui);
      u_mi_tree.set(i, ui);
      v_ma_tree.set(i, vi);
      v_mi_tree.set(i, vi);
    }else{
      int l, r; ll x, y; cin >> l >> r >> x >> y;
      l--; r--;
      ll ui = x + y;
      ll vi = x - y;

      ll u_ma = u_ma_tree.prod(l, r+1);
      ll u_mi = u_mi_tree.prod(l, r+1);
      ll v_ma = v_ma_tree.prod(l, r+1);
      ll v_mi = v_mi_tree.prod(l, r+1);

      ll cand1 = abs(ui - u_ma);
      ll cand2 = abs(ui - u_mi);
      ll cand3 = abs(vi - v_ma);
      ll cand4 = abs(vi - v_mi);

      ll ans = max(cand1, max(cand2, max(cand3, cand4)));
      cout << ans << endl;
    }
  }


}

int main() {

  solve();

  return 0;
}
