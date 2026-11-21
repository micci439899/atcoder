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
      a -= t * b; std::swap(a, b);
      u -= t * v; std::swap(u, v);
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
  friend constexpr std::ostream& operator << (std::ostream &os, const Fp<MOD>& x) noexcept {
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

template<int MOD> struct Combination {
  std::vector<Fp<MOD>> fac;
  std::vector<Fp<MOD>> ifac;

  Combination(int n) {
    fac.resize(n+1);
    ifac.resize(n+1);
    fac.at(0) = 1;
    ifac.at(0) = 1;

    for(int i = 1; i <= n; i++) {
      fac.at(i) = fac.at(i-1) * i;
      ifac.at(i) = ifac.at(i-1) / i;
    }
  }

  Fp<MOD> comb(int n, int k) {
    if(n < 0 || k < 0 || n < k) return 0;
    return fac.at(n) * ifac.at(n-k) * ifac.at(k);
  }
};

// 素集合データ構造（Union-Find）
struct DisjointSetUnion {
  std::vector<int> parents;
  std::vector<int> sizes;

  // 初期化子リスト
  DisjointSetUnion(int n) : parents(n, -1), sizes(n, 1) {}

  // xが属しているグループの代表（根）を取得
  int find(int x) {
    if(parents.at(x) == -1) return x;

    // 経路圧縮
    parents.at(x) = find(parents.at(x));
    return parents.at(x);
  }

  // xとyが同じグループに属しているかどうか
  bool is_same(int x, int y) {
    return find(x) == find(y);
  }

  // xが属しているグループとyが属しているグループを併合する
  // xとyが既に同じグループに属しているときfalse、そうでないときtrueを返す
  bool unite(int x, int y) {
    int x_r = find(x);
    int y_r = find(y);

    if(x_r == y_r) return false;

    // union by size（木の深さをなるべく小さくする）
    if(sizes.at(x_r) < sizes.at(y_r)) std::swap(x_r, y_r);

    parents.at(y_r) = x_r;
    sizes.at(x_r) += sizes.at(y_r);
    return true;
  }

  // xが属しているグループの要素数を返す
  int size(int x) {
    return sizes.at(find(x));
  }
};


const int MOD = 998244353;

void solve(){
  ll n, m; cin >> n >> m;
  string s; cin >> s;

  Combination<MOD> combination(n);

  DisjointSetUnion dsu(n);

  rep(_, m){
    ll u, v; cin >> u >> v;
    u--; v--;
    dsu.unite(u, v);
  }

  set<ll> p_st;
  rep(i, n){
    ll p = dsu.find(i);
    p_st.insert(p);
  }

  // vector<vector<ll>> p_vec((int)p_st.size());
  vector<vector<ll>> p_vec(n);
  rep(i, n){
    ll p = dsu.find(i);
    p_vec.at(p).push_back(i);
  }

  // debug(p_vec);

  Fp<MOD> ans = 1;
  rep(i, p_vec.size()){
    ll cnt0 = 0;
    ll cnt1 = 0;
    ll sz = p_vec.at(i).size();
    if(sz == 0) continue;
    rep(j, sz){
      ll k = p_vec.at(i).at(j);
      if(s.at(k) == '0') cnt0++;
      if(s.at(k) == '1') cnt1++;
    }
    Fp<MOD> c = combination.comb(cnt0+cnt1, cnt0);
    // debug(c);
    // debug(cnt0);
    // debug(cnt1);
    ans *= c;
  }

  cout << ans << endl;
}

int main() {
  solve();
  return 0;
}
