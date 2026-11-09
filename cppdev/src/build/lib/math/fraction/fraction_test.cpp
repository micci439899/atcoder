#include <bits/stdc++.h>
#include "fraction.hpp"
using namespace std;

void do_my_fraction(){
  Fraction<int> frac1(1, 2);
  Fraction<int> frac2(1, 3);

  Fraction<int> frac3 = frac1 + frac2;
  Fraction<int> frac4 = frac1 - frac2;
  Fraction<int> frac5 = frac1 * frac2;
  Fraction<int> frac6 = frac1 / frac2;

  cout << frac1 << endl;
  cout << frac2 << endl;
  cout << frac3 << endl;
  cout << frac4 << endl;
  cout << frac5 << endl;
  cout << frac6 << endl;

  cout << "frac7" << endl;
  Fraction<int> frac7(1, 12);
  frac7 += {7, 12};
  cout << frac7 << endl;
  frac7 -= {5, 12};
  cout << frac7 << endl;
  frac7 *= {5, 7};
  cout << frac7 << endl;
  frac7 /= {1, 9};
  cout << frac7 << endl;

  // error
  // cout << "frac8" << endl;
  // Fraction<int> frac8(1, 0);

  // error
  // cout << "frac9" << endl;
  // Fraction<int> frac9(0, 1);
  // frac9 /= {0, 1};

  cout << "frac10" << endl;
  Fraction<int> frac10(-123, 456);
  frac10 += {0, 1};
  cout << frac10 << endl;

  vector<Fraction<int>> v;
  for(int i = 0; i < 10; i++){
    int nume = i%2 == 0 ? i * (-1) : i;
    int deno = 2 * i + 1;
    v.push_back({nume, deno});
  }
  for(int i = 0; i < (int)v.size(); i++) {
    if(i) cout << " ";
    cout << v.at(i);
  }
  cout << endl;

  sort(v.begin(), v.end(), Fraction<int>::frac_cmp);

  for(int i = 0; i < (int)v.size(); i++) {
    if(i) cout << " ";
    cout << v.at(i);
  }
  cout << endl;

  for(int i = 0; i < (int)v.size()-1; i++) {
    cout << v.at(i+1) - v.at(i) << endl;
  }
}

int main() {
  do_my_fraction();
  return 0;
}