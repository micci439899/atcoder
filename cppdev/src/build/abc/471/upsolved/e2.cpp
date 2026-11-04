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


const int MOD = 998244353;

void solve(){
  int n, k; cin >> n >> k;

  vector<Fp<MOD>> a(n);
  rep(i, n){
    int ai; cin >> ai;
    a.at(i) = ai;
  }

  Combination<MOD> comb(n);

  // iを固定する
  // iを選ぶ組み合わせはn-1 C k-1個ある
  // (o + o + A_i + o + o + ...)^2 + (o + o + o + A_i + o + ...)^2 + ...
  // のようなイメージ

  // iを固定したときj(\ne i)を選ぶ組み合わせはn-2 C k-2個あり
  // またA_i * A_iはn-1 C k-1個ある

  // (A1 + ... + An)^2
  // = A1^2 + ... + An^2 + A1(A2+...+An) + A2(A1+A3...+An) + ...
  // より
  // A1(A2+...+An) + ... = (A1+...+An)^2 - (A1^2 + ... + An^2)
  // なので右辺のn-2 C k-2倍をすれば良い

  Fp<MOD> sm = 0;
  Fp<MOD> sq_sm = 0;
  rep(i, n){
    sm += a.at(i);
    sq_sm += a.at(i)*a.at(i);
  }
  Fp<MOD> sm_sq = sm*sm;

  Fp<MOD> ans = comb.comb(n-1, k-1) * sq_sm;
  ans += comb.comb(n-2, k-2) * (sm_sq - sq_sm);

  cout << ans << endl;
}

int main() {

  solve();

  return 0;
}