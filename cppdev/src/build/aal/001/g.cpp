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

// 有限体F_p上の演算
// https://qiita.com/drken/items/3b4fdf0a78e7a138cd9a
template<int MOD> struct Fp {
  long long val;

  constexpr Fp(long long v = 0) noexcept : val(v % MOD){
    if(val < 0) val += MOD;
  }

  constexpr Fp operator - () const noexcept {
    return val ? MOD - val : 0;
  }

  constexpr Fp operator + (const Fp &r) const noexcept { return Fp(*this) += r; }
  constexpr Fp operator - (const Fp &r) const noexcept { return Fp(*this) -= r; }
  constexpr Fp operator * (const Fp &r) const noexcept { return Fp(*this) *= r; }
  constexpr Fp operator / (const Fp &r) const noexcept { return Fp(*this) /= r; }

  constexpr Fp& operator += (const Fp& r) noexcept {
    val += r.val;
    if(val >= MOD) val -= MOD;
    return *this;
  }
  constexpr Fp& operator -= (const Fp& r) noexcept {
    val -= r.val;
    if(val < 0) val += MOD;
    return *this;
  }
  constexpr Fp& operator *= (const Fp& r) noexcept {
    val = val * r.val % MOD;
    return *this;
  }
  constexpr Fp& operator /= (const Fp& r) noexcept {
    long long a = r.val;
    long long b = MOD;
    long long u = 1, v = 0;
    while(b){
      long long t = a / b;
      a -= t * b; swap(a, b);
      u -= t * v; swap(u, v);
    }

    val = val * u % MOD;
    if(val < 0) val += MOD;
    return *this;
  }

  constexpr Fp& operator == (const Fp& r) noexcept {
    return this->val == r.val;
  }
  constexpr Fp& operator != (const Fp& r) noexcept {
    return this->val != r.val;
  }
  friend constexpr ostream& operator << (ostream &os, const Fp<MOD>& x) noexcept {
    return os << x.val;
  }
  friend constexpr Fp<MOD> modpow (const Fp<MOD> &a, long long n) noexcept {
    if (n == 0) return 1;
    auto t = modpow(a, n / 2);
    t = t * t;
    if (n & 1) t = t * a;
    return t;
  }
};

const int MOD = 998244353;

template<class T, class F> struct LazySegmentTree {
  // 1-indexedのLazy Segment Tree
  // ただし、外からは0-indexedとみなすことができる
  
  // 演算、単位元
  function<T(T,T)> op;
  T e;

  // 作用素、恒等写像
  function<T(F,T)> mapping;
  F id;

  // 作用素の合成
  function<F(F,F)> composition;

  // 元のデータサイズ
  int n;

  // SegmentTreeで管理するデータ
  vector<T> x;

  vector<F> lazy;

  // SegmentTreeで確保したデータから実データにアクセスするためのoffset
  int offset;

  // SegmentTreeの高さ
  int height;

  LazySegmentTree(int N, const function<T(T,T)> op, const function<T(F,T)> mapping, const function<F(F,F)> composition, const T e, const F id) : op(op), mapping(mapping), composition(composition), e(e), id(id) {
    initialize(N);
  }
  LazySegmentTree(const vector<T> &v, const function<T(T,T)> op, const function<T(F,T)> mapping, const function<F(F,F)> composition, const T e, const F id) : op(op), mapping(mapping), composition(composition), e(e), id(id) {
    initialize((int)v.size());
    build(v);
  }

  void initialize(int N) {
    n = N;
    offset = 1;
    height = 0;
    while(offset < N) offset *= 2, height++;
    x.assign(2*offset, e);
    lazy.assign(2*offset, id);
  }

  void build(const vector<T> &v) {
    for(int i = 0; i < (int)v.size(); i++) x.at(i + offset) = v.at(i);
    for(int i = offset-1; i > 0; i--) pull(i);
  }

  void pull(int i) {
    x.at(i) = op(x.at(i*2), x.at(i*2+1));
  }

  // i番目のデータを正しい値に直し、遅延分を溜める
  void apply(int i, const F &f) {
    x.at(i) = mapping(f, x.at(i));
    if(i < offset) lazy.at(i) = composition(f, lazy.at(i));
  }

  // 遅延させていた分を子に渡す
  void push(int i) {
    apply(i*2, lazy.at(i));
    apply(i*2+1, lazy.at(i));
    lazy.at(i) = id;
  }

  // 子のデータを自身に反映
  void deep_pull(int i){
    for(int h = 1; h <= height; h++) pull(i>>h);
  }

  void deep_push(int i) {
    for(int h = height; h >= 1; h--) push(i>>h);
  }

  void set(int i, const T &val) {
    int k = i + offset;
    deep_push(k);
    x.at(k) = val;
    deep_pull(k);
  }

  T get(int i) {
    int k = i + offset;
    deep_push(k);
    return x.at(k);
  }

  void apply(int l, int r, const F &f) {
    if(l == r) return;
    l += offset, r += offset;

    for(int h = height; h >= 1; h--) {
      int l_k = l>>h;
      int r_k = r>>h;
      if((l_k << h) != l) push(l_k);
      if((r_k << h) != r) push((r-1)>>h);
    }

    int original_l = l, original_r = r;
    for(; l < r; l>>=1, r>>=1) {
      if(l & 1) {
        apply(l, f);
        l++;
      }
      if(r & 1) {
        r--;
        apply(r, f);
      }
    }

    l = original_l, r = original_r;
    for(int h = 1; h <= height; h++) {
      int l_k = l>>h;
      int r_k = r>>h;
      if((l_k << h) != l) pull(l_k);
      if((r_k << h) != r) pull((r-1)>>h);
    }
  }

  T prod(int l, int r) {
    if(l == r) return e;
    l += offset, r += offset;

    for(int h = height; h >= 1; h--) {
      int l_k = l>>h;
      int r_k = r>>h;
      if((l_k << h) != l) push(l_k);
      if((r_k << h) != r) push(r_k);
    }

    T l_val = e, r_val = e;
    for(; l < r; l>>=1, r>>=1) {
      if(l & 1) {
        l_val = op(l_val, x.at(l));
        l++;
      }
      if(r & 1) {
        r--;
        r_val = op(x.at(r), r_val);
      }
    }
    return op(l_val, r_val);
  }

  int max_right(const function<bool(T)> func, int l = 0) {
    if(l == n) return n;
    l += offset;
    deep_push(l);
    T sm = e;
    do {
      while(l%2 == 0) l >>= 1;
      if(!func(op(sm, x.at(l)))) {
        while(l < offset) {
          deep_push(l);
          l = l * 2;
          if(func(op(sm, x.at(l)))) {
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

  int min_left(const function<bool(T)> func, int r = -1) {
    if(r == 0) return 0;
    if(r == -1) r = n;
    r += offset;
    deep_push(r-1);
    T sm = e;
    do {
      r--;
      while(r > 1 && (r%2)) r >>= 1;
      if(!func(op(x.at(r), sm))) {
        while(r < offset) {
          deep_push(r);
          r = r * 2 + 1;
          if(func(op(x.at(r), sm))) {
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

  void out() {
    // 改行する要素番号（0-indexed）
    int br_num = 1;
    for(int i = 0; i < (int)x.size(); i++) {
      if(i == 0) continue;
      cout << x.at(i) << "(" << lazy.at(i) << "), ";
      if(br_num == i){
        cout << endl;
        // 2^(n-1) - 1から2^n - 1
        br_num = (br_num+1)*2-1;
      }
    }
  }

  vector<T> getX(){
    return x;
  }
};

struct Node {
  vector<Fp<MOD>> v;
  // Fp<MOD> val1;
  // Fp<MOD> val2;
  // Fp<MOD> val3;
  // Fp<MOD> val4;
};

Node createNode(Fp<MOD> a){
  vector<Fp<MOD>> v(4);
  v.at(0) = a;
  v.at(1) = modpow(a, 2);
  v.at(2) = modpow(a, 3);
  v.at(3) = modpow(a, 4);
  return Node{v};
  // Fp<MOD> val1 = a;
  // Fp<MOD> val2 = val1*val1;
  // Fp<MOD> val3 = val2*val1;
  // Fp<MOD> val4 = val3*val1;
  // return Node{
  //   val1, val2, val3, val4
  // };
}

// const Node e = Node{0, 0, 0, 0, -1};
const Node e = Node{{0, 0, 0, 0}};

Node op(Node x, Node y){
  vector<Fp<MOD>> v(4);
  v.at(0) = x.v.at(0) + y.v.at(0);
  v.at(1) = x.v.at(1) + y.v.at(1);
  v.at(2) = x.v.at(2) + y.v.at(2);
  v.at(3) = x.v.at(3) + y.v.at(3);

  // debug(x.v);
  // debug(y.v);
  // debug(v);
  return Node{
    v
    // x.val1 + y.val1,
    // x.val2 + y.val2,
    // x.val3 + y.val3,
    // x.val4 + y.val4
  };
}

Node mapping(Fp<MOD> f, Node x){
  Fp<MOD> ff = x.v.at(0) + f;
  return createNode(f+x.v.at(0));

}

const Fp<MOD> id = 0;

// ll composition(ll g, ll f){
Fp<MOD> composition(Fp<MOD> g, Fp<MOD> f){
  return g + f;
}


void solve(){
  int n, q; cin >> n >> q;

  vector<ll> a(n);
  rep(i, n) cin >> a.at(i);

  vector<Node> v(n);
  rep(i, n){
    Fp<MOD> aa = a.at(i);
    v.at(i) = createNode(aa);

    // debug(v.at(i).v);
  }



  LazySegmentTree<Node, Fp<MOD>> seg(v, op, mapping, composition, e, id);


  // vector<Node> x = seg.getX();
  // rep(i, x.size()){
  //   cout << i << ":" << x.at(i).v.at(0) << " " << x.at(i).v.at(1) << " " << x.at(i).v.at(2) << " " << x.at(i).v.at(3) << endl;
  // }

  // Node res04 = seg.prod(0, 4);
  // debug(res04.v);
  // Node res14 = seg.prod(1, 4);
  // debug(res14.v);
  // Node res24 = seg.prod(2, 4);
  // debug(res24.v);
  // Node res34 = seg.prod(3, 4);
  // debug(res34.v);

  while(q--){
    int t; cin >> t;

    if(t == 1){
      int l, r; ll x; cin >> l >> r >> x;
      l--; r--;
      seg.apply(l, r+1, x);
    }else{
      int l, r, k; cin >> l >> r >> k;
      l--; r--; k--;
      Node res = seg.prod(l, r+1);
      Fp<MOD> ans = res.v.at(k);
      // debug(l);
      // debug(r);
      // debug(k);
      // debug(res.v);
      cout << ans << endl;
    }
  }

}

int main() {

  solve();

  return 0;
}
