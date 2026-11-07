#include <iostream>
#include <vector>
#include "fp.hpp"

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

