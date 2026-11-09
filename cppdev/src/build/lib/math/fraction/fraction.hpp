#include <iostream>
#include <cassert>

// 2026/11/10
// とりあえずz.cppから分離だけした
// int128にすればlong longでも上手くいく？
// どこかで確認する
// AWC0154Aが通れば多分ok
// 2026/10/03
// Tの範囲に収まらないときがあるので注意する
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
  friend constexpr std::ostream& operator << (std::ostream &os, const Fraction& x) noexcept {
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
