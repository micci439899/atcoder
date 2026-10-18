# include <bits/stdc++.h>
using namespace std;


int main() {
  string S;
  cin >> S;

  int sz = S.size();
  long double ans = 0;

  for (int i = 0; i < sz; i++) {
    if (S.at(i) != 't') {
      continue;
    }
    for (int j = i + 2; j < sz; j++) {
      if (S.at(j) != 't') {
        continue;
      }

      int x = 0;
      for (int k = i; k <= j; k++) {
        if (S.at(k) == 't') {
          x++;
        }
      }
      long double tmp = (long double)(x - 2) / (long double)(j - i + 1 - 2);
      if (ans < tmp) {
        ans = tmp;
      }
    }
  }

  cout << fixed << setprecision(12) << ans << endl;

  return 0;
}











