#include <bits/stdc++.h>
#include "convolution.hpp"
using namespace std;

const int MOD = 998244353;

void convolution_test() {
  vector<Fp<MOD>> a = {1, 2, 3};
  vector<Fp<MOD>> b = {4, 5, 6};

  Convolution<MOD> convolution;

  // 数式でいうと
  // (1 + 2x + 3x^2)(4 + 5x +6x^2)
  // = 4 + 5x + 6x^2 + 8x + 10x^2 + 12x^3 + 12x^2 + 15x^3 + 18x^4
  // = 4 + 13x + 28x^2 + 27x^3 + 18x^4
  // convolutionを定義通り計算すると
  // c_0 = a_0 * b_0
  //     = 1 * 4
  //     = 4
  // c_1 = a_0 * b_1 + a_1 * b_0
  //     = 1 * 5 + 2 * 4
  //     = 13
  // c_2 = a_0 * b_2 + a_1 * b_1 + a_2 * b_0
  //     = 1 * 6 + 2 * 5 + 3 * 4
  //     = 28
  // c_3 = a_1 * b_2 + a_2 * b_1
  //     = 2 * 6 + 3 * 5
  //     = 27
  // c_4 = a_2 * b_2
  //     = 18
  vector<Fp<MOD>> c = convolution.convolve(a, b);

  for(int i = 0; i < (int)c.size(); i++) {
    if(i) cout << " ";
    cout << c.at(i);
  }
  cout << endl;
}

int main() {
  convolution_test();
  return 0;
}