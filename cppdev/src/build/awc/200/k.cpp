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
template<class T, class U>ostream&operator<<(ostream&os, map<T,U>mp){os<<"{";int idx=0;for(auto p : mp){cout << p.first<<":"<<p.second;if(idx != mp.size()-1){cout << ",";}idx++;}os<<"}";return os;}
template<class T, class U>ostream&operator<<(ostream&os, unordered_map<T,U>mp){os<<"{";int idx=0;for(auto p : mp){cout << p.first<<":"<<p.second;if(idx != mp.size()-1){cout << ",";}idx++;}os<<"}";return os;}

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
  std::function<T(T,T)> op;
  T e;

  // 元のデータサイズ
  int n;

  // SegmentTreeで管理するデータ
  std::vector<T> x;

  // SegmentTreeで確保したデータから実データにアクセスするためのoffset
  int offset;

  SegmentTree(int N, std::function<T(T,T)> op, T e) : op(op), e(e) {
    initialize(N);
  }
  SegmentTree(const std::vector<T> &v, const std::function<T(T,T)> op, T e) : op(op), e(e) {
    initialize((int)v.size());
    build(v);
  }

  void initialize(int N) {
    n = N;
    offset = 1;
    while(offset < N) offset *= 2;
    x.assign(2*offset, e);
  }

  void build(const std::vector<T> &v) {
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

  // SegmentTree上の二分探索
  // [l, r)に対する演算がtrueとなるrを返す
  int max_right(const std::function<bool(T)> f, int l = 0) {
    if(l == n) return n;
    l += offset;
    T res = e;
    do {
      while(l%2 == 0) l >>= 1;
      if(!f(op(res, x.at(l)))) {
        while(l < offset) {
          l = l * 2;
          if(f(op(res, x.at(l)))) {
            res = op(res, x.at(l));
            l++;
          }
        }
        return l - offset;
      }
      res = op(res, x.at(l));
      l++;
    } while((l & -l) != l);
    return n;
  }

  // SegmentTree上の二分探索
  // [l, r)に対する演算がtrueとなるlを返す
  int min_left(const std::function<bool(T)> f, int r = -1) {
    if(r == 0) return 0;
    if(r == -1) r = n;
    r += offset;
    T res = e;
    do {
      r--;
      while(r > 1 && (r%2)) r >>= 1;
      if(!f(op(x.at(r), res))){
        while(r < offset) {
          r = r * 2 + 1;
          if(f(op(x.at(r), res))) {
            res = op(x.at(r), res);
            r--;
          }
        }
        return r + 1 - offset;
      }
      res = op(x.at(r), res);
    } while((r & -r) != r);
    return 0;
  }

  // debug用
  void out() {
    // 改行する要素番号（0-indexed）
    int br_num = 1;
    for(int i = 0; i < (int)x.size(); i++) {
      if(i == 0) continue;
      std::cout << x.at(i) << " ";
      if(br_num == i){
        std::cout << std::endl;
        // 2^(n-1) - 1から2^n - 1
        br_num = (br_num+1)*2-1;
      }
    }
  }
};

struct Node{
  ll l;
  ll r;
  ll h;
  ll sm;
};

void solve(){
  // 解けず
  // 方針自体違いそう





  ll n, s; cin >> n >> s;

  vector<Node> a(n);
  rep(i, n){
    ll ai;
    cin >> ai;
    a.at(i) = {i, i+1, ai, ai};
  }

  auto f = [](Node a, Node b) -> Node { 
    ll h = min(a.h, b.h);
    // ll sm = (b.r - a.l + 1) * h;
    ll sm = (b.r - a.l) * h;
    return {a.l, b.r, h, sm};
  };
  Node e = {1LL<<60, -1, -1LL<<60, 0LL};
  SegmentTree<Node> seg(a, f, e);


  ll ans = 1LL<<60;
  rep(i, n+1){
    if(i == 0) continue;
    ll idx = seg.min_left(
      [&](Node x) -> bool { return x.sm < s; }, i
    );
    if(idx == 0){
      Node x = seg.prod(idx, i);
      if(x.sm < s) continue;
    }
    ans = min(ans, i-idx+1);
  }

  if(ans > n){
    cout << -1 << endl;
  }else{
    cout << ans+1 << endl;
  }


}

int main() {
  solve();
  return 0;
}
