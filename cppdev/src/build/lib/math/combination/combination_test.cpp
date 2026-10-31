#include <bits/stdc++.h>
#include "combination.hpp"
using namespace std;

const int MOD = 998244353;

void do_combination() {
  Combination<MOD> comb(100);

  for(int i = 0; i <= 100; i++) {
    for(int j = 0; j <= i; j++) {
      Fp<MOD> res = comb.comb(i, j);
      cout << i << "C" << j << " = " << res << endl;
    }
  }
}


int main() {
  do_combination();
  return 0;
}


