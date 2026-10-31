#include "../fp.hpp"

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
