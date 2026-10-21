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

// 自前ライブラリ
// 分数のまま計算することが可能
// 負の値のとき分子が負になる
// 計算する度に既約分数の形になる
template<class T> struct Fraction {
  // 分子
  T nume;
  // 分母
  T deno;

  constexpr Fraction(T n, T d) noexcept : nume(n), deno(d){
    assert(deno != 0);
    if(deno < 0){
      nume *= -1;
      deno *= -1;
    }
    T g = _in_gcd(nume, deno);
    nume /= g;
    deno /= g;
  }

  constexpr Fraction operator - () const noexcept {
    return nume *= -1;
  }

  constexpr Fraction operator + (const Fraction &r) const noexcept { return Fraction(*this) += r; }
  constexpr Fraction operator - (const Fraction &r) const noexcept { return Fraction(*this) -= r; }
  constexpr Fraction operator * (const Fraction &r) const noexcept { return Fraction(*this) *= r; }
  constexpr Fraction operator / (const Fraction &r) const noexcept { return Fraction(*this) /= r; }

  constexpr Fraction& operator += (const Fraction& r) noexcept {
    // b/a + d/c
    // = (bc + ad) / ac
    T n_nume = nume * r.deno + deno * r.nume;
    T n_deno = deno * r.deno;
    nume = n_nume;
    deno = n_deno;
    T g = _in_gcd(nume, deno);
    nume /= g;
    deno /= g;
    return *this;
  }
  constexpr Fraction& operator -= (const Fraction& r) noexcept {
    // b/a - d/c
    // = (bc - ad) / ac
    T n_nume = nume * r.deno - deno * r.nume;
    T n_deno = deno * r.deno;
    nume = n_nume;
    deno = n_deno;
    T g = _in_gcd(nume, deno);
    nume /= g;
    deno /= g;
    return *this;
  }
  constexpr Fraction& operator *= (const Fraction& r) noexcept {
    // b/a * d/c
    // = bd / ac
    T n_nume = nume * r.nume;
    T n_deno = deno * r.deno;
    nume = n_nume;
    deno = n_deno;
    T g = _in_gcd(nume, deno);
    nume /= g;
    deno /= g;
    return *this;
  }
  constexpr Fraction& operator /= (const Fraction& r) noexcept {
    // b/a / d/c
    // = bc / ad
    // 0 divided exception
    assert(r.nume != 0);
    T n_nume = nume * r.deno;
    T n_deno = deno * r.nume;
    nume = n_nume;
    deno = n_deno;
    T g = _in_gcd(nume, deno);
    nume /= g;
    deno /= g;
    return *this;
  }

  constexpr Fraction& operator == (const Fraction& r) noexcept {
    return this->nume == r.nume && this->deno == r.deno;
  }
  constexpr Fraction& operator != (const Fraction& r) noexcept {
    return this->nume != r.nume || this->deno != r.deno;
  }
  friend constexpr ostream& operator << (ostream &os, const Fraction& x) noexcept {
    return os << x.nume << "/" << x.deno;
  }

  public:
  // sort用
  static bool frac_cmp(Fraction<T> f1, Fraction<T>f2){
    // b/a < d/c
    // = bc < ad
    return f1.nume * f2.deno < f1.deno * f2.nume;
  }

  private:
  // greatest common divisor
  T _in_gcd(T a, T b){
    return b == 0 ? a : _in_gcd(b, a%b);
  }

};

void solve(){
  ll n, m; cin >> n >> m;

  vector<ll> s(m);
  rep(i, m) cin >> s.at(i);
  sort(s.begin(), s.end());

  ll diff = s.at(0)+n -s.at(m-1);
  rep(i, m-1){
    chmax(diff, s.at(i+1)-s.at(i));
  }

  ll d = (n - diff + 1) / 2;
  Fraction<ll> frac(d * 360, n);

  cout << frac << endl;

}


int main() {

  solve();

  return 0;
}
