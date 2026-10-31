#include <bits/stdc++.h>
#include "fp.hpp"
using namespace std;

const int MOD = 998244353;

void do_fp_calc(){
  vector<Fp<MOD>> v1 = {1, 2, 3 ,4};
  vector<Fp<MOD>> v2 = {5, 6, 7 ,8};

  for(int i = 0; i < (int)v1.size(); i++) {
    for(int j = 0; j < (int)v2.size(); j++){
      cout << v1.at(i) << " + " << v2.at(j) << " = " << v1.at(i)+v2.at(j) << endl;
      cout << v1.at(i) << " - " << v2.at(j) << " = " << v1.at(i)-v2.at(j) << endl;
      cout << v1.at(i) << " * " << v2.at(j) << " = " << v1.at(i)*v2.at(j) << endl;
      cout << v1.at(i) << " / " << v2.at(j) << " = " << v1.at(i)/v2.at(j) << endl;
    }
  }

  cout << endl;

  for(int i = 0; i < 10; i++) {
    Fp<20> a = i;

    for(int j = 0; j < 10; j++) {
      cout << i << "^" << j << " = " << modpow(a, j) << endl;
    }
  }


  for(int i = 0; i < 10; i++) {
    Fp<MOD> ii = -i;
    cout << ii << endl;
  }

  for(int i = 0; i < (int)v1.size(); i++) {
    for(int j = 1; j < 11; j++){
      Fp<MOD> base = 10;
      auto a_i = - v1.at(i) * modpow(base, j);
      cout << "- "<< v1.at(i) << " * 10^" << j << " = " << a_i << endl;
    }
  }
}


int main() {
  do_fp_calc();
  return 0;
}


