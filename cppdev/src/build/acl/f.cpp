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

// n次多項式a := a_n * x^n + a_{n-1} * x^{n-1} + ... + a_0 * x^0
// m次多項式b := b_m * x^m + b_{m-1} * x^{m-1} + ... + b_0 * x^0
// の畳み込みを計算する
// つまりc_i := sum_{i=j+k} a_j * b_kなるn+m次多項式を返す
// 注意：
// MODはほぼ998244353限定
// a, bの係数はint範囲内です
// long longにしたい場合、法を複数使って復元する（未履修）
template<int MOD> struct Convolution {
  // 原子根
  // 998244353と上手く合う数（あまり追えてないです）
  Fp<MOD> G = 3;

  Convolution(){}

  // 数論変換（Number Theoretic Transform）
  // 発想はFFTと同じ
  void ntt(std::vector<Fp<MOD>> &a, bool invert) {
    int n = a.size();

    // bit反転順に並べ替え
    // バタフライ演算の前処理
    // 偶奇でまとめたものに対して再帰的にNTTを実施するのと同義
    // e.g.)
    // 0, 1, 2, 3, 4, 5, 6, 7
    // bit:000, 001, 010, 011, 100, 101, 110, 111
    // inv:000, 100, 010, 110, 001, 101, 011, 111
    // 0, 4, 2, 6, 1, 5, 3 ,7
    // 再帰の場合
    // 0, 2, 4, 6と1, 3, 5 ,7
    // 0, 4と2, 6、1, 5と3, 7
    // となる
    for(int i = 1, j = 0; i < n; i++) {
      int bit = n >> 1;
      for(; j & bit; bit >>= 1) {
        j ^= bit;
      }
      j ^= bit;
      if(i < j) std::swap(a.at(i), a.at(j));
    }

    // バタフライ演算
    for(int len = 2; len <= n; len <<= 1) {
      Fp<MOD> wlen = modpow(G, (MOD-1)/len);

      if(invert) {
        wlen = modpow(wlen, MOD-2);
      }

      for(int i = 0; i < n; i+= len) {
        Fp<MOD> w = 1;

        for(int j = 0; j < len / 2; j++) {
          Fp<MOD> u = a.at(i+j);
          Fp<MOD> v = a.at(i+j+len/2) * w;

          a.at(i+j) = u + v;
          a.at(i+j+len/2) = u - v;

          w = w * wlen;
        }
      }
    }

    if(invert) {
      Fp<MOD> nn = n;
      Fp<MOD> inv_n = modpow(nn, MOD-2);
      for(int i = 0; i < (int)a.size(); i++) {
        a.at(i) = a.at(i) * inv_n;
      }
    }
  }

  // 畳み込み
  std::vector<Fp<MOD>> convolve(std::vector<Fp<MOD>> a, std::vector<Fp<MOD>> b) {
    if(a.empty() || b.empty()) return {};

    int sz = a.size() + b.size() - 1;
    int n = 1;
    while(n < sz) n<<=1;

    a.resize(n);
    b.resize(n);

    ntt(a, false);
    ntt(b, false);

    for(int i = 0; i < n; i++) {
      a.at(i) = a.at(i) * b.at(i);
    }

    ntt(a, true);

    a.resize(sz);
    return a;
  }

};

const int MOD = 998244353;

void solve(){
  int n, m; cin >> n >> m;

  vector<Fp<MOD>> a(n);
  vector<Fp<MOD>> b(m);

  rep(i, n){
    int ai; cin >> ai;
    a.at(i) = ai;
  }
  rep(i, m){
    int bi; cin >> bi;
    b.at(i) = bi;
  }

  Convolution<MOD> convolution;

  vector<Fp<MOD>> c = convolution.convolve(a, b);

  rep(i, c.size()){
    if(i) cout << " ";
    cout << c.at(i);
  }
  cout << endl;

}

int main() {
  solve();
  return 0;
}
